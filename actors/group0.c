#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "geo_commands.h"

#include "make_const_nonconst.h"

// Note: This bin does not use bin IDs, unlike the other segmented bins.
#include "mario/model.inc.c"

#include "bubble/model.inc.c"

#include "walk_smoke/model.inc.c"

#include "burn_smoke/model.inc.c"

#include "small_water_splash/model.inc.c"

#include "water_wave/model.inc.c"

#include "sparkle/model.inc.c"

#include "water_splash/model.inc.c"

#include "white_particle_small/model.inc.c"

#include "sparkle_animation/model.inc.c"

#ifdef S2DEX_TEXT_ENGINE
#include "src/s2d_engine/config.h"
#include FONT_C_FILE
#endif
#include "lantern/model.inc.c"

#include "spring/model.inc.c"

#include "bullet_bill/model.inc.c"


#include "peach/model.inc.c"
#include "peach/anims/data.inc.c"
#include "peach/anims/table.inc.c"

#include "moneybag/model.inc.c"
#include "moneybag/anims/data.inc.c"
#include "moneybag/anims/table.inc.c"

#include "penguin/model.inc.c"
#include "penguin/anims/data.inc.c"
#include "penguin/anims/table.inc.c"
#include "penguin/collision.inc.c"
#include "koopa_without_shell_custom/model.inc.c"
#include "shell_custom/model.inc.c"
#include "koopa_with_shell_custom/model.inc.c"