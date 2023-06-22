import csv
from typing import TypedDict

# csv headers
class Col(TypedDict):
    Name: str
    Red: str
    Green: str
    Blue: str

def c_wrap(s: str):
    return '{ ' + s + ' }'

def struct_prop(field: str, v):
    return f".{field} = {v}"

# hsl in struct
class HSL():
    h: float = 0.0
    s: float = 0.0
    l: float = 0.0
    def __init__(self, hsl: "list[float, float, float]") -> None:
        self.h = hsl[0]
        self.s = hsl[1]
        self.l = hsl[2]

    def to_c(self) -> str:
        return c_wrap(', '.join([
            struct_prop('h', self.h),
            struct_prop('s', self.s),
            struct_prop('l', self.l)
        ]))

# rgb in struct
class RGB():
    r: int = 0
    g: int = 0
    b: int = 0
    
    def to_hsl(self):
        r = self.r / 255.0
        g = self.g / 255.0
        b = self.b / 255.0
        
        max_val = max([r,g,b])
        min_val = min([r,g,b])
        
        hsl = [(max_val + min_val) / 2]*3

        if max_val == min_val:
            hsl[0] = hsl[1] = 0  # achromatic
        else:
            d = max_val - min_val
            hsl[1] = d / (2 - max_val - min_val) if hsl[2] > 0.5 else d / (max_val + min_val)
            
            if max_val == r:
                hsl[0] = (g - b) / d + (6 if g < b else 0)
            elif max_val == g:
                hsl[0] = (b - r) / d + 2
            elif max_val == b:
                hsl[0] = (r - g) / d + 4
            
            hsl[0] /= 6

            if hsl[0] < 0.0:
                hsl[0] += 1.0
            if hsl[0] > 1.0:
                hsl[0] -= 1.0
        return HSL(hsl)

    def to_c(self) -> str:
        return c_wrap(', '.join([
            struct_prop('r', self.r),
            struct_prop('g', self.g),
            struct_prop('b', self.b)
        ]))
        



# output struct (name used in enum)
class DimensiOneColor():
    Name: str
    # actually in struct
    hex: str
    rgb: RGB = RGB()
    hsl: HSL
    
    def __init__(self, col: Col) -> None:
        self.Name = col['Name']
        self.hex = ''.join([col['Red'], col['Blue'], col['Green']])
        self.rgb.r = int(col['Red'], 16)
        self.rgb.g = int(col['Green'], 16)
        self.rgb.b = int(col['Blue'], 16)
        self.hsl = self.rgb.to_hsl()
    
    def to_c_struct(self, tabs = 1) -> str:
        space = tabs * '    '
        innards = ',\n'.join([
            space + space + struct_prop("hex", f'"{self.hex}"'),
            space + space + struct_prop("rgb", self.rgb.to_c()),
            space + space + struct_prop("hsl", self.hsl.to_c()),
        ])
        label = f"{space}[{self.Name}] = "
        return label + "{\n" + innards + "\n" + space + "}"


def read_colors():
    with open('src/game/colors.csv', 'r') as color_csv_fp:
        fieldnames = color_csv_fp.readline().strip('\n').split(',')
        reader = csv.DictReader(color_csv_fp, fieldnames)

        colors: list[DimensiOneColor] = []
        col: Col = None
        for col in reader:
            colors.append(DimensiOneColor(col))
        return colors

def main():
    colors: list[DimensiOneColor] = read_colors()
    array_data = ',\n'.join([c.to_c_struct() for c in colors])
    label = "#include \"game/colors.h\"\n\nstruct DimensiOneColor gD1Colors[] = {"
    c_data = '\n'.join([label, array_data, "};\n"])
    with open('build/us_n64/gen/colors.inc.c', 'w') as col_fp:
        col_fp.write(c_data)
    
    enum_label = "enum DimensiOneColors {"
    enum_data = '\n'.join([enum_label, '    ' + ',\n    '.join([c.Name for c in colors]), "};\n"])
    with open('build/us_n64/gen/colors.inc.h', 'w') as col_h_fp:
        col_h_fp.write(enum_data)

if __name__ == '__main__':
    main()
