#ifndef MM_PLAY_H
#define MM_PLAY_H

#include <combo/util.h>
#include <combo/game_state.h>
#include <combo/common/actor.h>
#include <combo/common/ocarina.h>

typedef struct
{
    void* readBuf;
    void* saveBuf;
    char unk_00[0x20];
}
SramContext;

_Static_assert(sizeof(SramContext) == 0x28, "MM SramContext size is wrong");

typedef struct PACKED
{
    char unk_000[0x222];
    s16 unk_222;
    char unk_224[0x40];
    struct PACKED
    {
        s16 screenFill;
        s16 buttonA;
        s16 buttonB;
        s16 buttonCLeft;
        s16 buttonCDown;
        s16 buttonCRight;
        s16 health;
        s16 magic;
        s16 minimap;
        s16 start;
    }
    alpha;
    char unk_278[0x096];
    struct PACKED {
        u8 hGauge;
        u8 bButton;
        u8 aButton;
        u8 tradeItems;
        u8 songOfTime;
        u8 songOfDoubleTime;
        u8 invSongOfTime;
        u8 songOfSoaring;
        u8 songOfStorms;
        u8 masks;
        u8 pictoBox;
        u8 all;
    } restrictions;
    char unk_31a[0x02e];
}
InterfaceContext;

ASSERT_OFFSET(InterfaceContext, unk_000,        0x000);
ASSERT_OFFSET(InterfaceContext, alpha,          0x264);
ASSERT_OFFSET(InterfaceContext, unk_278,        0x278);
ASSERT_OFFSET(InterfaceContext, restrictions,   0x30e);
ASSERT_OFFSET(InterfaceContext, unk_31a,        0x31a);

typedef struct
{
    char    unk_000[0x204];
    u8      screenIndex;
    char    unk_205[0x3d];
    s16     cursorIndexX[5];
    s16     cursorIndexY[5];
    char    unk_256[0x008];
    u16     cursorItem[5];
    u16     cursorSlot[5];
    char    unk_272[0x012];
    s16     cursorColorIndex;
    char    unk_286[0x04a];
}
PauseContext;

ASSERT_OFFSET(PauseContext, unk_000,        0x000);
ASSERT_OFFSET(PauseContext, screenIndex,    0x204);
_Static_assert(sizeof(PauseContext) == 0x2d0, "MM PauseContext size is wrong");

typedef struct
{
    int unk;
}
GameOverContext;

typedef struct
{
    u16  unk_00;
    u16  sceneTimeSpeed;
    char unk_04[0xfc];
}
EnvironmentContext;

_Static_assert(sizeof(EnvironmentContext) == 0x100, "MM EnvironmentContext size is wrong");

typedef struct GameState_Play
{
    GameState           gs;
    u16                 sceneId;
    char                unk_000a6[0x01c12];
    ActorList           actors[12];
    char                unk_01d18[0x029a0];
    SramContext         sramCtx;
    char                unk_046e0[0x11c10];
    char                textBuffer[4]; /* Real size unknown */
    char                unk_162f4[0x00514];
    OcarinaStaff*       ocarinaStaff;
    char                unk_1680C[0x00126];
    u16                 ocarinaMode;
    char                unk_16934[2];
    s16                 ocarinaSong;
    char                unk_16938[0x000b0];
    InterfaceContext    interfaceCtx;
    PauseContext        pauseCtx;
    GameOverContext     gameOverCtx;
    EnvironmentContext  envCtx;
    char                unk_17104[0x01698];
    s16                 playerActorCsIds[10];
    float               viewProjectionMtxF[16];
    Vec3f               projectionMtxFDiagonal;
    float               billboardMtxF[16];
    void*               billboardMtx;
    u32                 gameplayFrames;
    u8                  unk_18844;
    u8                  haltAllActors;
    s16                 numSetupActors;
    u8                  numRooms;
    void*               roomList;
    void*               linkActorEntry;
    void*               setupActorList;
    void*               actorCsCamList;
    void*               setupEntranceList;
    u16*                setupExitList;
    void*               setupPathList;
    void*               naviQuestHints;
    void*               sceneMaterialAnims;
    void*               specialEffects;
    u8                  skyboxId;
    u8                  transitionTrigger;
    s16                 worldCoverAlpha;
    s16                 bgCoverAlpha;
    u16                 nextEntrance;
    s8                  unk_1887c;
    s8                  unk_1887d;
    s8                  unk_1887e;
    u8                  transitionType;
    char                unk_18880[0x2ca];
    u8                  transitionMode;
    char                unk_18b4b[0x70d];
}
GameState_Play;

typedef struct
{
    char unk[0x32];
    u16  clockSpeed;
}
GameData;

extern GameData* gGameData;

ASSERT_OFFSET(GameState_Play, unk_16938,        0x16938);
ASSERT_OFFSET(GameState_Play, interfaceCtx,     0x169e8);
ASSERT_OFFSET(GameState_Play, envCtx,           0x17004);
ASSERT_OFFSET(GameState_Play, gameplayFrames,   0x18840);
ASSERT_OFFSET(GameState_Play, setupExitList,    0x18860);
ASSERT_OFFSET(GameState_Play, transitionType,   0x1887f);
ASSERT_OFFSET(GameState_Play, transitionMode,   0x18b4a);

#define TRANS_TRIGGER_NONE          0x00
#define TRANS_TRIGGER_NORMAL        0x14

#define TRANS_TYPE_BLACK     0x02

_Static_assert(sizeof(GameState_Play) == 0x19258, "MM GameState_Play size is wrong");

#endif
