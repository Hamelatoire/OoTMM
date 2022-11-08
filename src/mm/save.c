#include <combo.h>

#define ENTRANCE(scene, id) (((scene) - 3) << 9)

#define ENTRANCE_CLOCKTOWN  0xd800
#define ENTRANCE_WOODS      0xc200
#define ENTRANCE_DKING      0x7610
#define ENTRANCE_TEMPLE1    0x3000
#define ENTRANCE_BOSS1      0x3800
#define ENTRANCE_SWAMP      0x8420
#define ENTRANCE_RANCH      0x6400
#define ENTRANCE_GREAT_BAY  0x6800
#define ENTRANCE_BEAVER     0x8e00
#define ENTRANCE_LAB        0x5800
#define ENTRANCE_SMITH      0x5200
#define ENTRANCE_GSHRINE    0x5e00

void Sram_AfterOpenSave(void)
{
    gSave.entranceIndex = ENTRANCE_CLOCKTOWN;

#if defined(DEBUG)
    //gSave.entranceIndex = ENTRANCE(SCE_MM_SAKON_HIDEOUT, 0);
#endif
}
