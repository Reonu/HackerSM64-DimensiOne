#ifndef LEVEL_COMMANDS_H
#define LEVEL_COMMANDS_H

#include "command_macros_base.h"

#include "level_table.h"
#include "config.h"
#include "game/puppylights.h"

#define CHALLENGE_JUMP_NO_STACK_SIZE 0x10

enum ChallengeLevels {
    LEVEL_CHALLENGES_0  = (1U << 0 ),
    LEVEL_CHALLENGES_1  = (1U << 1 ),
    LEVEL_CHALLENGES_2  = (1U << 2 ),
    LEVEL_CHALLENGES_3  = (1U << 3 ),
    LEVEL_CHALLENGES_4  = (1U << 4 ),
    LEVEL_CHALLENGES_5  = (1U << 5 ),
    LEVEL_CHALLENGES_6  = (1U << 6 ),
    LEVEL_CHALLENGES_7  = (1U << 7 ),
    LEVEL_CHALLENGES_8  = (1U << 8 ),
    LEVEL_CHALLENGES_9  = (1U << 9 ),
    LEVEL_CHALLENGES_10 = (1U << 10),
    LEVEL_CHALLENGES_11 = (1U << 11),
    LEVEL_CHALLENGES_12 = (1U << 12),
    LEVEL_CHALLENGES_13 = (1U << 13),
    LEVEL_CHALLENGES_14 = (1U << 14),
    LEVEL_CHALLENGES_15 = (1U << 15),
    LEVEL_CHALLENGES_16 = (1U << 16),
    LEVEL_CHALLENGES_17 = (1U << 17),
    LEVEL_CHALLENGES_18 = (1U << 18),
    LEVEL_CHALLENGES_19 = (1U << 19),
    LEVEL_CHALLENGES_20 = (1U << 20),
    LEVEL_CHALLENGES_21 = (1U << 21),
    LEVEL_CHALLENGES_22 = (1U << 22),
    LEVEL_CHALLENGES_23 = (1U << 23),
    LEVEL_CHALLENGES_24 = (1U << 24),
    LEVEL_CHALLENGES_25 = (1U << 25),
    LEVEL_CHALLENGES_26 = (1U << 26),
    LEVEL_CHALLENGES_27 = (1U << 27),
    LEVEL_CHALLENGES_28 = (1U << 28),
    LEVEL_CHALLENGES_29 = (1U << 29),
    LEVEL_CHALLENGES_30 = (1U << 30),
    LEVEL_CHALLENGES_31 = (1U << 31),

    LEVEL_CHALLENGES_0_PLUS  = (-1U - (LEVEL_CHALLENGES_0  - 1)),
    LEVEL_CHALLENGES_1_PLUS  = (-1U - (LEVEL_CHALLENGES_1  - 1)),
    LEVEL_CHALLENGES_2_PLUS  = (-1U - (LEVEL_CHALLENGES_2  - 1)),
    LEVEL_CHALLENGES_3_PLUS  = (-1U - (LEVEL_CHALLENGES_3  - 1)),
    LEVEL_CHALLENGES_4_PLUS  = (-1U - (LEVEL_CHALLENGES_4  - 1)),
    LEVEL_CHALLENGES_5_PLUS  = (-1U - (LEVEL_CHALLENGES_5  - 1)),
    LEVEL_CHALLENGES_6_PLUS  = (-1U - (LEVEL_CHALLENGES_6  - 1)),
    LEVEL_CHALLENGES_7_PLUS  = (-1U - (LEVEL_CHALLENGES_7  - 1)),
    LEVEL_CHALLENGES_8_PLUS  = (-1U - (LEVEL_CHALLENGES_8  - 1)),
    LEVEL_CHALLENGES_9_PLUS  = (-1U - (LEVEL_CHALLENGES_9  - 1)),
    LEVEL_CHALLENGES_10_PLUS = (-1U - (LEVEL_CHALLENGES_10 - 1)),
    LEVEL_CHALLENGES_11_PLUS = (-1U - (LEVEL_CHALLENGES_11 - 1)),
    LEVEL_CHALLENGES_12_PLUS = (-1U - (LEVEL_CHALLENGES_12 - 1)),
    LEVEL_CHALLENGES_13_PLUS = (-1U - (LEVEL_CHALLENGES_13 - 1)),
    LEVEL_CHALLENGES_14_PLUS = (-1U - (LEVEL_CHALLENGES_14 - 1)),
    LEVEL_CHALLENGES_15_PLUS = (-1U - (LEVEL_CHALLENGES_15 - 1)),
    LEVEL_CHALLENGES_16_PLUS = (-1U - (LEVEL_CHALLENGES_16 - 1)),
    LEVEL_CHALLENGES_17_PLUS = (-1U - (LEVEL_CHALLENGES_17 - 1)),
    LEVEL_CHALLENGES_18_PLUS = (-1U - (LEVEL_CHALLENGES_18 - 1)),
    LEVEL_CHALLENGES_19_PLUS = (-1U - (LEVEL_CHALLENGES_19 - 1)),
    LEVEL_CHALLENGES_20_PLUS = (-1U - (LEVEL_CHALLENGES_20 - 1)),
    LEVEL_CHALLENGES_21_PLUS = (-1U - (LEVEL_CHALLENGES_21 - 1)),
    LEVEL_CHALLENGES_22_PLUS = (-1U - (LEVEL_CHALLENGES_22 - 1)),
    LEVEL_CHALLENGES_23_PLUS = (-1U - (LEVEL_CHALLENGES_23 - 1)),
    LEVEL_CHALLENGES_24_PLUS = (-1U - (LEVEL_CHALLENGES_24 - 1)),
    LEVEL_CHALLENGES_25_PLUS = (-1U - (LEVEL_CHALLENGES_25 - 1)),
    LEVEL_CHALLENGES_26_PLUS = (-1U - (LEVEL_CHALLENGES_26 - 1)),
    LEVEL_CHALLENGES_27_PLUS = (-1U - (LEVEL_CHALLENGES_27 - 1)),
    LEVEL_CHALLENGES_28_PLUS = (-1U - (LEVEL_CHALLENGES_28 - 1)),
    LEVEL_CHALLENGES_29_PLUS = (-1U - (LEVEL_CHALLENGES_29 - 1)),
    LEVEL_CHALLENGES_30_PLUS = (-1U - (LEVEL_CHALLENGES_30 - 1)),
    LEVEL_CHALLENGES_31_PLUS = (-1U - (LEVEL_CHALLENGES_31 - 1)),

    LEVEL_CHALLENGES_0_BELOW  = (LEVEL_CHALLENGES_0  | ~LEVEL_CHALLENGES_0_PLUS ),
    LEVEL_CHALLENGES_1_BELOW  = (LEVEL_CHALLENGES_1  | ~LEVEL_CHALLENGES_1_PLUS ),
    LEVEL_CHALLENGES_2_BELOW  = (LEVEL_CHALLENGES_2  | ~LEVEL_CHALLENGES_2_PLUS ),
    LEVEL_CHALLENGES_3_BELOW  = (LEVEL_CHALLENGES_3  | ~LEVEL_CHALLENGES_3_PLUS ),
    LEVEL_CHALLENGES_4_BELOW  = (LEVEL_CHALLENGES_4  | ~LEVEL_CHALLENGES_4_PLUS ),
    LEVEL_CHALLENGES_5_BELOW  = (LEVEL_CHALLENGES_5  | ~LEVEL_CHALLENGES_5_PLUS ),
    LEVEL_CHALLENGES_6_BELOW  = (LEVEL_CHALLENGES_6  | ~LEVEL_CHALLENGES_6_PLUS ),
    LEVEL_CHALLENGES_7_BELOW  = (LEVEL_CHALLENGES_7  | ~LEVEL_CHALLENGES_7_PLUS ),
    LEVEL_CHALLENGES_8_BELOW  = (LEVEL_CHALLENGES_8  | ~LEVEL_CHALLENGES_8_PLUS ),
    LEVEL_CHALLENGES_9_BELOW  = (LEVEL_CHALLENGES_9  | ~LEVEL_CHALLENGES_9_PLUS ),
    LEVEL_CHALLENGES_10_BELOW = (LEVEL_CHALLENGES_10 | ~LEVEL_CHALLENGES_10_PLUS),
    LEVEL_CHALLENGES_11_BELOW = (LEVEL_CHALLENGES_11 | ~LEVEL_CHALLENGES_11_PLUS),
    LEVEL_CHALLENGES_12_BELOW = (LEVEL_CHALLENGES_12 | ~LEVEL_CHALLENGES_12_PLUS),
    LEVEL_CHALLENGES_13_BELOW = (LEVEL_CHALLENGES_13 | ~LEVEL_CHALLENGES_13_PLUS),
    LEVEL_CHALLENGES_14_BELOW = (LEVEL_CHALLENGES_14 | ~LEVEL_CHALLENGES_14_PLUS),
    LEVEL_CHALLENGES_15_BELOW = (LEVEL_CHALLENGES_15 | ~LEVEL_CHALLENGES_15_PLUS),
    LEVEL_CHALLENGES_16_BELOW = (LEVEL_CHALLENGES_16 | ~LEVEL_CHALLENGES_16_PLUS),
    LEVEL_CHALLENGES_17_BELOW = (LEVEL_CHALLENGES_17 | ~LEVEL_CHALLENGES_17_PLUS),
    LEVEL_CHALLENGES_18_BELOW = (LEVEL_CHALLENGES_18 | ~LEVEL_CHALLENGES_18_PLUS),
    LEVEL_CHALLENGES_19_BELOW = (LEVEL_CHALLENGES_19 | ~LEVEL_CHALLENGES_19_PLUS),
    LEVEL_CHALLENGES_20_BELOW = (LEVEL_CHALLENGES_20 | ~LEVEL_CHALLENGES_20_PLUS),
    LEVEL_CHALLENGES_21_BELOW = (LEVEL_CHALLENGES_21 | ~LEVEL_CHALLENGES_21_PLUS),
    LEVEL_CHALLENGES_22_BELOW = (LEVEL_CHALLENGES_22 | ~LEVEL_CHALLENGES_22_PLUS),
    LEVEL_CHALLENGES_23_BELOW = (LEVEL_CHALLENGES_23 | ~LEVEL_CHALLENGES_23_PLUS),
    LEVEL_CHALLENGES_24_BELOW = (LEVEL_CHALLENGES_24 | ~LEVEL_CHALLENGES_24_PLUS),
    LEVEL_CHALLENGES_25_BELOW = (LEVEL_CHALLENGES_25 | ~LEVEL_CHALLENGES_25_PLUS),
    LEVEL_CHALLENGES_26_BELOW = (LEVEL_CHALLENGES_26 | ~LEVEL_CHALLENGES_26_PLUS),
    LEVEL_CHALLENGES_27_BELOW = (LEVEL_CHALLENGES_27 | ~LEVEL_CHALLENGES_27_PLUS),
    LEVEL_CHALLENGES_28_BELOW = (LEVEL_CHALLENGES_28 | ~LEVEL_CHALLENGES_28_PLUS),
    LEVEL_CHALLENGES_29_BELOW = (LEVEL_CHALLENGES_29 | ~LEVEL_CHALLENGES_29_PLUS),
    LEVEL_CHALLENGES_30_BELOW = (LEVEL_CHALLENGES_30 | ~LEVEL_CHALLENGES_30_PLUS),
    LEVEL_CHALLENGES_31_BELOW = (LEVEL_CHALLENGES_31 | ~LEVEL_CHALLENGES_31_PLUS),

    LEVEL_CHALLENGES_ALL = -1U,
};

enum LevelCommands {
    /*0x00*/ LEVEL_CMD_LOAD_AND_EXECUTE,
    /*0x01*/ LEVEL_CMD_EXIT_AND_EXECUTE,
    /*0x02*/ LEVEL_CMD_EXIT,
    /*0x03*/ LEVEL_CMD_SLEEP,
    /*0x04*/ LEVEL_CMD_SLEEP2,
    /*0x05*/ LEVEL_CMD_JUMP,
    /*0x06*/ LEVEL_CMD_JUMP_AND_LINK,
    /*0x07*/ LEVEL_CMD_RETURN,
    /*0x08*/ LEVEL_CMD_JUMP_AND_LINK_PUSH_ARG,
    /*0x09*/ LEVEL_CMD_JUMP_REPEAT,
    /*0x0A*/ LEVEL_CMD_LOOP_BEGIN,
    /*0x0B*/ LEVEL_CMD_LOOP_UNTIL,
    /*0x0C*/ LEVEL_CMD_JUMP_IF,
    /*0x0D*/ LEVEL_CMD_JUMP_AND_LINK_IF,
    /*0x0E*/ LEVEL_CMD_SKIP_IF,
    /*0x0F*/ LEVEL_CMD_SKIP,
    /*0x10*/ LEVEL_CMD_SKIPPABLE_NOP,
    /*0x11*/ LEVEL_CMD_CALL,
    /*0x12*/ LEVEL_CMD_CALL_LOOP,
    /*0x13*/ LEVEL_CMD_SET_REGISTER,
    /*0x14*/ LEVEL_CMD_PUSH_POOL_STATE,
    /*0x15*/ LEVEL_CMD_POP_POOL_STATE,
    /*0x16*/ LEVEL_CMD_LOAD_TO_FIXED_ADDRESS,
    /*0x17*/ LEVEL_CMD_LOAD_RAW,
    /*0x18*/ LEVEL_CMD_LOAD_YAY0,
    /*0x19*/ LEVEL_CMD_LOAD_MARIO_HEAD,
    /*0x1A*/ LEVEL_CMD_LOAD_YAY0_TEXTURE,
    /*0x1B*/ LEVEL_CMD_INIT_LEVEL,
    /*0x1C*/ LEVEL_CMD_CLEAR_LEVEL,
    /*0x1D*/ LEVEL_CMD_ALLOC_LEVEL_POOL,
    /*0x1E*/ LEVEL_CMD_FREE_LEVEL_POOL,
    /*0x1F*/ LEVEL_CMD_BEGIN_AREA,
    /*0x20*/ LEVEL_CMD_END_AREA,
    /*0x21*/ LEVEL_CMD_LOAD_MODEL_FROM_DL,
    /*0x22*/ LEVEL_CMD_LOAD_MODEL_FROM_GEO,
    /*0x23*/ LEVEL_CMD_23,
    /*0x24*/ LEVEL_CMD_PLACE_OBJECT,
    /*0x25*/ LEVEL_CMD_INIT_MARIO,
    /*0x26*/ LEVEL_CMD_CREATE_WARP_NODE,
    /*0x27*/ LEVEL_CMD_CREATE_PAINTING_WARP_NODE,
    /*0x28*/ LEVEL_CMD_CREATE_INSTANT_WARP,
    /*0x29*/ LEVEL_CMD_LOAD_AREA,
    /*0x2A*/ LEVEL_CMD_UNLOAD_AREA,
    /*0x2B*/ LEVEL_CMD_SET_MARIO_START_POS,
    /*0x2C*/ LEVEL_CMD_UNLOAD_MARIO_AREA,
    /*0x2D*/ LEVEL_CMD_UPDATE_OBJECTS,
    /*0x2E*/ LEVEL_CMD_SET_TERRAIN_DATA,
    /*0x2F*/ LEVEL_CMD_SET_ROOMS,
    /*0x30*/ LEVEL_CMD_SHOW_DIALOG,
    /*0x31*/ LEVEL_CMD_SET_TERRAIN_TYPE,
    /*0x32*/ LEVEL_CMD_NOP,
    /*0x33*/ LEVEL_CMD_SET_TRANSITION,
    /*0x34*/ LEVEL_CMD_SET_BLACKOUT,
    /*0x35*/ LEVEL_CMD_SET_GAMMA,
    /*0x36*/ LEVEL_CMD_SET_MUSIC,
    /*0x37*/ LEVEL_CMD_SET_MENU_MUSIC,
    /*0x38*/ LEVEL_CMD_FADEOUT_MUSIC,
    /*0x39*/ LEVEL_CMD_SET_MACRO_OBJECTS,
    /*0x3A*/ LEVEL_CMD_3A,
    /*0x3B*/ LEVEL_CMD_CREATE_WHIRLPOOL,
    /*0x3C*/ LEVEL_CMD_GET_OR_SET_VAR,
    /*0x3D*/ LEVEL_CMD_PUPPYVOLUME,
    /*0x3E*/ LEVEL_CMD_CHANGE_AREA_SKYBOX,
    /*0x3F*/ LEVEL_CMD_PUPPYLIGHT_ENVIRONMENT,
    /*0x40*/ LEVEL_CMD_PUPPYLIGHT_NODE,
    /*0x41*/ LEVEL_CMD_MOVING_PLATFORM,
    /*0x42*/ LEVEL_CMD_CHALLENGE_JUMP,
    /*0x43*/ LEVEL_CMD_CHALLENGE_JUMP_NO_STACK,
};

enum BankOrObjectLoad {
    LOAD_BANKS,
    LOAD_GEOS,
    LOAD_OBJECTS,
};

enum LevelActs {
    ACT_1 = (1 << 0),
    ACT_2 = (1 << 1),
    ACT_3 = (1 << 2),
    ACT_4 = (1 << 3),
    ACT_5 = (1 << 4),
    ACT_6 = (1 << 5),
    ALL_ACTS = (ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6)
};

enum LevelCommandEvalOperation {
    OP_AND,
    OP_NAND,
    OP_EQ,
    OP_NEQ,
    OP_LT,
    OP_LEQ,
    OP_GT,
    OP_GEQ
};

enum LevelCommandGetOrSet {
    OP_SET,
    OP_GET
};

enum LevelCommandVar {
    VAR_CURR_SAVE_FILE_NUM,
    VAR_CURR_COURSE_NUM,
    VAR_CURR_ACT_NUM,
    VAR_CURR_LEVEL_NUM,
    VAR_CURR_AREA_INDEX
};

enum WarpCheckpointFlags {
    WARP_NO_CHECKPOINT = (0 << 0), // 0x00
    WARP_CHECKPOINT    = (1 << 7), // 0x80
};

enum LevelCommandCreateWhirlpoolCondition {
    WHIRLPOOL_COND_ALWAYS,
    WHIRLPOOL_COND_BOWSER2_NOT_BEATEN,
    WHIRLPOOL_COND_BOWSER2_BEATEN,
    WHIRLPOOL_COND_AT_LEAST_SECOND_STAR
};

// Head defines
enum GoddardScene {
    REGULAR_FACE = 0x2,
    DIZZY_FACE   = 0x3,
};

#ifdef NO_SEGMENTED_MEMORY
#define EXECUTE(seg, script, scriptEnd, entry) \
    CMD_BBH(LEVEL_CMD_LOAD_AND_EXECUTE, 0x10, 0x0000), \
    CMD_PTR(NULL), \
    CMD_PTR(NULL), \
    CMD_PTR(entry)

#define EXIT_AND_EXECUTE(seg, script, scriptEnd, entry) \
    CMD_BBH(LEVEL_CMD_EXIT_AND_EXECUTE, 0x10, 0x0000), \
    CMD_PTR(NULL), \
    CMD_PTR(NULL), \
    CMD_PTR(entry)
#else
#define EXECUTE(seg, script, scriptEnd, entry) \
    CMD_BBH(LEVEL_CMD_LOAD_AND_EXECUTE, 0x18, seg), \
    CMD_PTR(script), \
    CMD_PTR(scriptEnd), \
    CMD_PTR(entry), \
    CMD_PTR(NULL), \
    CMD_PTR(NULL)

#define EXIT_AND_EXECUTE(seg, script, scriptEnd, entry) \
    CMD_BBH(LEVEL_CMD_EXIT_AND_EXECUTE, 0x18, seg), \
    CMD_PTR(script), \
    CMD_PTR(scriptEnd), \
    CMD_PTR(entry), \
    CMD_PTR(NULL), \
    CMD_PTR(NULL)

#define EXECUTE_WITH_CODE(seg, script, scriptEnd, entry, bssStart, bssEnd) \
    CMD_BBH(LEVEL_CMD_LOAD_AND_EXECUTE, 0x18, seg), \
    CMD_PTR(script), \
    CMD_PTR(scriptEnd), \
    CMD_PTR(entry), \
    CMD_PTR(bssStart), \
    CMD_PTR(bssEnd)

#define EXIT_AND_EXECUTE_WITH_CODE(seg, script, scriptEnd, entry, bssStart, bssEnd) \
    CMD_BBH(LEVEL_CMD_EXIT_AND_EXECUTE, 0x18, seg), \
    CMD_PTR(script), \
    CMD_PTR(scriptEnd), \
    CMD_PTR(entry), \
    CMD_PTR(bssStart), \
    CMD_PTR(bssEnd)
#endif

#define EXIT() \
    CMD_BBH(LEVEL_CMD_EXIT, 0x04, 0x0000)

#define SLEEP(frames) \
    CMD_BBH(LEVEL_CMD_SLEEP, 0x04, frames)

#define SLEEP_BEFORE_EXIT(frames) \
    CMD_BBH(LEVEL_CMD_SLEEP2, 0x04, frames)

#define JUMP(target) \
    CMD_BBH(LEVEL_CMD_JUMP, 0x08, 0x0000), \
    CMD_PTR(target)

#define JUMP_LINK(target) \
    CMD_BBH(LEVEL_CMD_JUMP_AND_LINK, 0x08, 0x0000), \
    CMD_PTR(target)

#define RETURN() \
    CMD_BBH(LEVEL_CMD_RETURN, 0x04, 0x0000)

#define JUMP_LINK_PUSH_ARG(arg) \
    CMD_BBH(LEVEL_CMD_JUMP_AND_LINK_PUSH_ARG, 0x04, arg)

#define JUMP_N_TIMES() \
    CMD_BBH(LEVEL_CMD_JUMP_REPEAT, 0x04, 0x0000)

#define LOOP_BEGIN() \
    CMD_BBH(LEVEL_CMD_LOOP_BEGIN, 0x04, 0x0000)

#define LOOP_UNTIL(op, arg) \
    CMD_BBBB(LEVEL_CMD_LOOP_UNTIL, 0x08, op, 0x00), \
    CMD_W(arg)

#define JUMP_IF(op, arg, target) \
    CMD_BBBB(LEVEL_CMD_JUMP_IF, 0x0C, op, 0x00), \
    CMD_W(arg), \
    CMD_PTR(target)

#define JUMP_LINK_IF(op, arg, target) \
    CMD_BBBB(LEVEL_CMD_JUMP_AND_LINK_IF, 0x0C, op, 0x00), \
    CMD_W(arg), \
    CMD_PTR(target)

#define SKIP_IF(op, arg) \
    CMD_BBBB(LEVEL_CMD_SKIP_IF, 0x08, op, 0) \
    CMD_W(arg)

#define SKIP() \
    CMD_BBH(LEVEL_CMD_SKIP, 0x04, 0x0000)

#define SKIP_NOP() \
    CMD_BBH(LEVEL_CMD_SKIPPABLE_NOP, 0x04, 0x0000)

#define CALL(arg, func) \
    CMD_BBH(LEVEL_CMD_CALL, 0x08, arg), \
    CMD_PTR(func)

// Calls func in a loop until it returns nonzero
#define CALL_LOOP(arg, func) \
    CMD_BBH(LEVEL_CMD_CALL_LOOP, 0x08, arg), \
    CMD_PTR(func)

#define SET_REG(value) \
    CMD_BBH(LEVEL_CMD_SET_REGISTER, 0x04, value)

#define PUSH_POOL() \
    CMD_BBH(LEVEL_CMD_PUSH_POOL_STATE, 0x04, 0x0000)

#define POP_POOL() \
    CMD_BBH(LEVEL_CMD_POP_POOL_STATE, 0x04, 0x0000)

#undef LOAD_MIO0
#define LOAD_MIO0(a,b,c) LOAD_YAY0(a,b,c)

#undef LOAD_MIO0_TEXTURE
#define LOAD_MIO0_TEXTURE(a,b,c) LOAD_YAY0_TEXTURE(a,b,c)

#ifdef NO_SEGMENTED_MEMORY
#define FIXED_LOAD(loadAddr, romStart, romEnd) \
    CMD_BBH(LEVEL_CMD_LOAD_TO_FIXED_ADDRESS, 0x10, 0x0000), \
    CMD_PTR(NULL), \
    CMD_PTR(NULL), \
    CMD_PTR(NULL)

#define LOAD_RAW(seg, romStart, romEnd) \
    CMD_BBH(LEVEL_CMD_LOAD_RAW, 0x0C, 0x0000), \
    CMD_PTR(NULL), \
    CMD_PTR(NULL)

#define LOAD_YAY0(seg, romStart, romEnd) \
    CMD_BBH(LEVEL_CMD_LOAD_YAY0, 0x0C, 0x0000), \
    CMD_PTR(NULL), \
    CMD_PTR(NULL)
#else
#define FIXED_LOAD(loadAddr, romStart, romEnd) \
    CMD_BBH(LEVEL_CMD_LOAD_TO_FIXED_ADDRESS, 0x10, 0x0000), \
    CMD_PTR(loadAddr), \
    CMD_PTR(romStart), \
    CMD_PTR(romEnd)

#define LOAD_RAW(seg, romStart, romEnd) \
    CMD_BBH(LEVEL_CMD_LOAD_RAW, 0x14, seg), \
    CMD_PTR(romStart), \
    CMD_PTR(romEnd), \
    CMD_PTR(0), \
    CMD_PTR(0)

#define LOAD_RAW_WITH_CODE(seg, romStart, romEnd, bssStart, bssEnd) \
    CMD_BBH(LEVEL_CMD_LOAD_RAW, 0x14, seg), \
    CMD_PTR(romStart), \
    CMD_PTR(romEnd), \
    CMD_PTR(bssStart), \
    CMD_PTR(bssEnd)

#define LOAD_YAY0(seg, romStart, romEnd) \
    CMD_BBH(LEVEL_CMD_LOAD_YAY0, 0x0C, seg), \
    CMD_PTR(romStart), \
    CMD_PTR(romEnd)
#endif

#ifdef KEEP_MARIO_HEAD
#define LOAD_MARIO_HEAD(sethead) \
    CMD_BBH(LEVEL_CMD_LOAD_MARIO_HEAD, 0x04, sethead)
#else
#define LOAD_MARIO_HEAD() \
    CMD_BBH(LEVEL_CMD_NOP, 0x04, 0x0000)
#endif

#ifdef NO_SEGMENTED_MEMORY
#define LOAD_YAY0_TEXTURE(seg, romStart, romEnd) \
    CMD_BBH(LEVEL_CMD_LOAD_YAY0_TEXTURE, 0x0C, 0x0000), \
    CMD_PTR(NULL), \
    CMD_PTR(NULL)
#else
#define LOAD_YAY0_TEXTURE(seg, romStart, romEnd) \
    CMD_BBH(LEVEL_CMD_LOAD_YAY0_TEXTURE, 0x0C, seg), \
    CMD_PTR(romStart), \
    CMD_PTR(romEnd)
#endif

#undef LOAD_MIO0_TEXTURE
#define LOAD_MIO0_TEXTURE(a,b,c) LOAD_YAY0_TEXTURE(a,b,c)

#define CHANGE_AREA_SKYBOX(area, segStart, segEnd) \
    CMD_BBH(LEVEL_CMD_CHANGE_AREA_SKYBOX, 0x0C, area), \
    CMD_PTR(segStart), \
    CMD_PTR(segEnd)


#define INIT_LEVEL() \
    CMD_BBH(LEVEL_CMD_INIT_LEVEL, 0x04, 0x0000)

#define CLEAR_LEVEL() \
    CMD_BBH(LEVEL_CMD_CLEAR_LEVEL, 0x04, 0x0000)

#define ALLOC_LEVEL_POOL() \
    CMD_BBH(LEVEL_CMD_ALLOC_LEVEL_POOL, 0x04, 0x0000)

#define FREE_LEVEL_POOL() \
    CMD_BBH(LEVEL_CMD_FREE_LEVEL_POOL, 0x04, 0x0000)

#define AREA(index, geo) \
    CMD_BBBB(LEVEL_CMD_BEGIN_AREA, 0x08, index, 0), \
    CMD_PTR(geo)

#define END_AREA() \
    CMD_BBH(LEVEL_CMD_END_AREA, 0x04, 0x0000)

#define LOAD_MODEL_FROM_DL(model, dl, layer) \
    CMD_BBH(LEVEL_CMD_LOAD_MODEL_FROM_DL, 0x0C, 0), \
    CMD_PTR(dl), \
    CMD_HH(layer, model)

#define LOAD_MODEL_FROM_GEO(model, geo) \
    CMD_BBH(LEVEL_CMD_LOAD_MODEL_FROM_GEO, 0x08, model), \
    CMD_PTR(geo)

// unk8 is float, but doesn't really matter since CMD23 is unused
#define CMD23(model, unk4, unk8) \
    CMD_BBH(LEVEL_CMD_23, 0x08, 0), \
    CMD_PTR(unk4), \
    CMD_W(unk8)

#define OBJECT_WITH_ACTS_CHALLENGE_LEVEL(model, posX, posY, posZ, angleX, angleY, angleZ, behParam, beh, acts, challenge_levels) \
    CMD_BBBB(LEVEL_CMD_PLACE_OBJECT, 0x20, acts, 0x00), \
    CMD_HHHHHH(posX, posY, posZ, angleX, angleY, angleZ), \
    CMD_W(behParam), \
    CMD_PTR(beh), \
    CMD_W(model), \
    CMD_W(challenge_levels)

#define CHALLENGE_OBJECT(model, posX, posY, posZ, angleX, angleY, angleZ, behParam, beh, challenge_levels) \
    OBJECT_WITH_ACTS_CHALLENGE_LEVEL(model, posX, posY, posZ, angleX, angleY, angleZ, behParam, beh, 0x1F, challenge_levels)

#define OBJECT_WITH_ACTS(model, posX, posY, posZ, angleX, angleY, angleZ, behParam, beh, acts) \
    OBJECT_WITH_ACTS_CHALLENGE_LEVEL(model, posX, posY, posZ, angleX, angleY, angleZ, behParam, beh, acts, LEVEL_CHALLENGES_ALL)

#define OBJECT(model, posX, posY, posZ, angleX, angleY, angleZ, behParam, beh) \
    OBJECT_WITH_ACTS_CHALLENGE_LEVEL(model, posX, posY, posZ, angleX, angleY, angleZ, behParam, beh, 0x1F, LEVEL_CHALLENGES_ALL)

#define MOVING_PLATFORM_WITH_ACTS(geolayout, collision, posX, posY, posZ, angleX, angleY, angleZ, behParam, beh, acts) \
    CMD_BBBB(LEVEL_CMD_MOVING_PLATFORM, 0x20, acts, 0x00), \
    CMD_HHHHHH(posX, posY, posZ, angleX, angleY, angleZ), \
    CMD_W(behParam), \
    CMD_PTR(beh), \
    CMD_PTR(geolayout), \
    CMD_PTR(collision)

#define MOVING_PLATFORM(geolayout, collision, posX, posY, posZ, angleX, angleY, angleZ, behParam, beh) \
    MOVING_PLATFORM_WITH_ACTS(geolayout, collision, posX, posY, posZ, angleX, angleY, angleZ, behParam, beh, 0x1F)

#define MARIO(model, behArg, beh) \
    CMD_BBH(LEVEL_CMD_INIT_MARIO, 0x0C, model), \
    CMD_W(behArg), \
    CMD_PTR(beh)

#define WARP_NODE(id, destLevel, destArea, destNode, flags) \
    CMD_BBBB(LEVEL_CMD_CREATE_WARP_NODE, 0x08, id, destLevel), \
    CMD_BBBB(destArea, destNode, flags, 0x00)

#define PAINTING_WARP_NODE(id, destLevel, destArea, destNode, flags) \
    CMD_BBBB(LEVEL_CMD_CREATE_PAINTING_WARP_NODE, 0x08, id, destLevel), \
    CMD_BBBB(destArea, destNode, flags, 0x00)

#define INSTANT_WARP(index, destArea, displaceX, displaceY, displaceZ) \
    CMD_BBBB(LEVEL_CMD_CREATE_INSTANT_WARP, 0x10, index, destArea), \
    CMD_W(displaceX), \
    CMD_W(displaceY), \
    CMD_W(displaceZ)

#define LOAD_AREA(area) \
    CMD_BBBB(LEVEL_CMD_LOAD_AREA, 0x04, area, 0x00)

#define UNLOAD_AREA(area) \
    CMD_BBBB(LEVEL_CMD_UNLOAD_AREA, 0x04, area, 0x00)

#define MARIO_POS(area, yaw, posX, posY, posZ) \
    CMD_BBBB(LEVEL_CMD_SET_MARIO_START_POS, 0x0C, area, 0x00), \
    CMD_HH(yaw, posX), \
    CMD_HH(posY, posZ)

// unused
#define UNLOAD_MARIO_AREA() \
    CMD_BBH(LEVEL_CMD_UNLOAD_MARIO_AREA, 0x04, 0x0000)

#define UPDATE_OBJECTS() \
    CMD_BBH(LEVEL_CMD_UPDATE_OBJECTS, 0x04, 0x0000)

#define TERRAIN(terrainData) \
    CMD_BBH(LEVEL_CMD_SET_TERRAIN_DATA, 0x08, 0x0000), \
    CMD_PTR(terrainData)

#define ROOMS(surfaceRooms) \
    CMD_BBH(LEVEL_CMD_SET_ROOMS, 0x08, 0x0000), \
    CMD_PTR(surfaceRooms)

#define SHOW_DIALOG(index, dialogId) \
    CMD_BBBB(LEVEL_CMD_SHOW_DIALOG, 0x04, index, dialogId)

#define TERRAIN_TYPE(terrainType) \
    CMD_BBH(LEVEL_CMD_SET_TERRAIN_TYPE, 0x04, terrainType)

#define NOP() \
    CMD_BBH(LEVEL_CMD_NOP, 0x04, 0x0000)

#define TRANSITION(transType, time, colorR, colorG, colorB) \
    CMD_BBBB(LEVEL_CMD_SET_TRANSITION, 0x08, transType, time), \
    CMD_BBBB(colorR, colorG, colorB, 0x00)

#define BLACKOUT(active) \
    CMD_BBBB(LEVEL_CMD_SET_BLACKOUT, 0x04, active, 0x00)

#define GAMMA(enabled) \
    CMD_BBBB(LEVEL_CMD_SET_GAMMA, 0x04, enabled, 0x00)

#ifdef BETTER_REVERB
#define SET_BACKGROUND_MUSIC_WITH_REVERB(settingsPreset, seq, reverbPresetConsole, reverbPresetEmulator) \
    CMD_BBH(LEVEL_CMD_SET_MUSIC, 0x08, settingsPreset), \
    CMD_BBH(reverbPresetConsole, reverbPresetEmulator, seq)

#define SET_MENU_MUSIC_WITH_REVERB(seq, reverbPresetConsole, reverbPresetEmulator) \
    CMD_BBH(LEVEL_CMD_SET_MENU_MUSIC, 0x08, seq), \
    CMD_BBH(reverbPresetConsole, reverbPresetEmulator, 0x0000)
#else
// Functionally identical to calling SET_BACKGROUND_MUSIC if BETTER_REVERB is disabled
#define SET_BACKGROUND_MUSIC_WITH_REVERB(settingsPreset, seq, reverbPresetConsole, reverbPresetEmulator) \
    CMD_BBH(LEVEL_CMD_SET_MUSIC, 0x08, settingsPreset), \
    CMD_HH(0x0000, seq)

// Functionally identical to calling SET_MENU_MUSIC if BETTER_REVERB is disabled
#define SET_MENU_MUSIC_WITH_REVERB(seq, reverbPresetConsole, reverbPresetEmulator) \
    CMD_BBH(LEVEL_CMD_SET_MENU_MUSIC, 0x04, seq)
#endif

#define SET_BACKGROUND_MUSIC(settingsPreset, seq) \
    SET_BACKGROUND_MUSIC_WITH_REVERB(settingsPreset, seq, 0x00, 0x00)

#define SET_MENU_MUSIC(seq) \
    SET_MENU_MUSIC_WITH_REVERB(seq, 0x00, 0x00)

#define STOP_MUSIC(fadeOutTime) \
    CMD_BBH(LEVEL_CMD_FADEOUT_MUSIC, 0x04, fadeOutTime)

#define MACRO_OBJECTS(objList) \
    CMD_BBH(LEVEL_CMD_SET_MACRO_OBJECTS, 0x08, 0x0000), \
    CMD_PTR(objList)

// ONE Challenge macros
#define CHALLENGE_JUMP(bankOrObj, target) \
    CMD_BBH(LEVEL_CMD_CHALLENGE_JUMP, 0x08, bankOrObj), \
    CMD_PTR(target)

#define CHALLENGE_JUMP_NO_STACK(bankLoad, geoLoad, objLoad) \
    CMD_BBH(LEVEL_CMD_CHALLENGE_JUMP_NO_STACK, CHALLENGE_JUMP_NO_STACK_SIZE, 0x0000), \
    CMD_PTR(bankLoad), \
    CMD_PTR(geoLoad), \
    CMD_PTR(objLoad)

// unused
#define CMD3A(unk2, unk4, unk6, unk8, unk10) \
    CMD_BBH(LEVEL_CMD_3A, 0x0C, unk2), \
    CMD_HH(unk6, unk8), \
    CMD_HH(unk10, 0x0000)

#define WHIRLPOOL(index, condition, posX, posY, posZ, strength) \
    CMD_BBBB(LEVEL_CMD_CREATE_WHIRLPOOL, 0x0C, index, condition), \
    CMD_HH(posX, posY), \
    CMD_HH(posZ, strength)

#define GET_OR_SET(op, var) \
    CMD_BBBB(LEVEL_CMD_GET_OR_SET_VAR, 0x04, op, var)

// Presets

#define LOAD_LEVEL_DATA(level) \
    LOAD_YAY0(/*seg*/ SEGMENT_LEVEL_DATA, /*romStart*/ _##level##_segment_7SegmentRomStart, /*romEnd*/ _##level##_segment_7SegmentRomEnd)

#define LOAD_TEXTURE_BIN(textureBin) \
    LOAD_YAY0_TEXTURE(/*seg*/ SEGMENT_TEXTURE, /*romStart*/ _##textureBin##_yay0SegmentRomStart, /*romEnd*/ _##textureBin##_yay0SegmentRomEnd)

#define LOAD_SKYBOX(skybox) \
    LOAD_YAY0(/*seg*/ SEGMENT_SKYBOX, /*romStart*/ _##skybox##_skybox_yay0SegmentRomStart, /*romEnd*/ _##skybox##_skybox_yay0SegmentRomEnd)

#define LOAD_EFFECTS() \
    LOAD_YAY0(/*seg*/ SEGMENT_EFFECT_YAY0, /*romStart*/ _effect_yay0SegmentRomStart, /*romEnd*/ _effect_yay0SegmentRomEnd)

#define LOAD_GROUPA(groupName) \
    LOAD_YAY0(/*seg*/ SEGMENT_GROUPA_YAY0, /*romStart*/ _##groupName##_yay0SegmentRomStart, /*romEnd*/ _##groupName##_yay0SegmentRomEnd), \
    LOAD_RAW( /*seg*/ SEGMENT_GROUPA_GEO,  /*romStart*/ _##groupName##_geoSegmentRomStart,  /*romEnd*/ _##groupName##_geoSegmentRomEnd)

#define LOAD_GROUPB(groupName) \
    LOAD_YAY0(/*seg*/ SEGMENT_GROUPB_YAY0, /*romStart*/ _##groupName##_yay0SegmentRomStart, /*romEnd*/ _##groupName##_yay0SegmentRomEnd), \
    LOAD_RAW (/*seg*/ SEGMENT_GROUPB_GEO,  /*romStart*/ _##groupName##_geoSegmentRomStart,  /*romEnd*/ _##groupName##_geoSegmentRomEnd)

#define LOAD_COMMON0() \
    LOAD_YAY0(/*seg*/ SEGMENT_COMMON0_YAY0, /*romStart*/ _common0_yay0SegmentRomStart, /*romEnd*/ _common0_yay0SegmentRomEnd), \
    LOAD_RAW( /*seg*/ SEGMENT_COMMON0_GEO,  /*romStart*/ _common0_geoSegmentRomStart,  /*romEnd*/ _common0_geoSegmentRomEnd)

#define LOAD_BEHAVIOR_DATA() \
    LOAD_RAW( /*seg*/ SEGMENT_BEHAVIOR_DATA, /*romStart*/ _behaviorSegmentRomStart, /*romEnd*/ _behaviorSegmentRomEnd)

#define LOAD_GODDARD() \
    FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd)

#define LOAD_TITLE_SCREEN_BG() \
    LOAD_YAY0_TEXTURE(/*seg*/ SEGMENT_SKYBOX, /*romStart*/ _title_screen_bg_yay0SegmentRomStart, /*romEnd*/ _title_screen_bg_yay0SegmentRomEnd)

// behParams

#define BP(a, b, c, d) \
    (((a) << 24) | ((b) << 16) | ((c) << 8) | (d))

#endif // LEVEL_COMMANDS_H
