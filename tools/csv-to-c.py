import csv, sys
from collections import OrderedDict
from pprint import pprint
import json
import os
from typing import TypedDict
import yaml

# csv config
class CSVConfig(TypedDict):
    struct_array_variable_name: str # "gChungusArray"
    struct_array_type: str # "struct BigChungus"
    enum_name: str # "ChungusIDs"

def c_wrap(s: str):
    return '{ ' + s + ' }'

def struct_prop(field: str, v):
    return f".{field} = {v}"

TYPE_DELIM = "::"

FORMATTERS = {
    'literal': lambda v: v,
    'str': lambda v: json.dumps(v),
    'int': lambda v: int(v),
    'hex': lambda v: int(v, 16),
    'float': lambda v: float(v),
}

ENUM_NAME = "enumName"

REPLACER = "<<REPLACE>>"
GEN_WARNING = f'/* WARNING!! THIS FILE WAS GENERATED FROM "{REPLACER}". DO NOT EDIT DIRECTLY */\n\n'

def get_field_names_and_parser(fieldnames: "list[str]"):
    parser_lut = OrderedDict()
    fields = []
    for field in fieldnames:
        fieldname = field
        fmt_type = 'literal'
        if TYPE_DELIM in field:
            fieldname, fmt_type = field.split(TYPE_DELIM)
        formatter = FORMATTERS.get(fmt_type)
        if formatter is None:
            raise ValueError(fieldname + ": Format type " + fmt_type + " does not exist!")
        parser_lut[fieldname] = formatter
        fields.append(fieldname)

    return parser_lut, fields


def read_csv_rows(csv_path: str):
    structs = []
    with open(csv_path, 'r') as csv_fp:
        fieldnames = csv_fp.readline().strip('\n').split(',')
        parser_lut, fields = get_field_names_and_parser(fieldnames)
        reader = csv.DictReader(csv_fp, fields)

        default_struct = None
        for val in reader:
            struct_parsed = OrderedDict()
            for field, parse_func in parser_lut.items():
                if val[field]:
                    struct_parsed[field] = parse_func(val[field])
                else:
                    struct_parsed[field] = default_struct[field]
            structs.append(struct_parsed)

            if not default_struct:
                default_struct = struct_parsed
            
    return structs

def read_csv_conf(csv_path: str) -> CSVConfig:
    with open(csv_path + ".yml", 'r') as conf_fp:
        return CSVConfig(yaml.safe_load(conf_fp))

def main():
    if len(sys.argv) < 2:
        raise ValueError('Did not receive a path to a csv file')

    csv_path = sys.argv[1]
    csv_conf = read_csv_conf(csv_path)

    warning = GEN_WARNING.replace(REPLACER, csv_path)

    csv_name, _ = os.path.splitext(os.path.basename(csv_path))
    build_path = os.path.join('build/us_n64/', 'gen')
    gen_struct_path = os.path.join(build_path, csv_name + '.c.in')
    gen_header_path = os.path.join('include', 'gen', csv_name + '.h.in')

    struct_array_variable_dec =" ".join([
        csv_conf["struct_array_type"],
        csv_conf["struct_array_variable_name"] + "[]"])

    pprint({
        'csv_name': csv_name,
        'build_path': build_path,
        'gen_struct_path': gen_struct_path,
        'gen_header_path': gen_header_path,
        'struct_array_variable_dec': struct_array_variable_dec,
    })
    
    structs = read_csv_rows(csv_path)

    c_file_data = warning + struct_array_variable_dec + ' = {\n'
    structs_c = []
    for s in structs:
        work = f"    [{s[ENUM_NAME]}] = " + "{"
        values = ',\n'.join(['        ' + struct_prop(f, v) for f, v in s.items() if f != ENUM_NAME])
        structs_c.append('\n'.join([work, values, '    }']))
    c_file_data += ',\n'.join(structs_c)
    c_file_data += '\n};\n'
    with open(gen_struct_path, 'w') as fp:
        fp.write(c_file_data)
        print(f'Wrote {csv_name} data to {gen_struct_path}')

    enum_label = warning + " ".join(["enum", csv_conf['enum_name'], "{"])
    enum_data = '\n'.join([
        enum_label,
        '    ' + ',\n    '.join([s[ENUM_NAME] for s in structs]),
        "};\n"
    ])
    with open(gen_header_path, 'w') as fp:
        fp.write(enum_data)
        print(f'Wrote {csv_name} enum to {gen_header_path}')

if __name__ == '__main__':
    main()
