#include <combo.h>
#include <combo/item.h>

static void EnZk_MaybeSetMovedPos(Actor* this, GameState_Play* play)
{
    int isOpen;
    void (*EnZk_SetMovedPos)(Actor*, GameState_Play*);

    if (comboConfig(CFG_OOT_ZK_OPEN))
        isOpen = 1;
    else if (gSave.age == AGE_ADULT && comboConfig(CFG_OOT_ZK_OPEN_ADULT))
        isOpen = 1;
    else if (GetEventChk(EV_OOT_CHK_KING_ZORA_MOVED))
        isOpen = 1;
    else
        isOpen = 0;

    if (isOpen)
    {
        EnZk_SetMovedPos = actorAddr(AC_EN_ZK, 0x80ad65ec);
        EnZk_SetMovedPos(this, play);
    }
}

PATCH_CALL(0x80ad67a4, EnZk_MaybeSetMovedPos);

int EnZk_HasGiveItem(Actor* this)
{
    if (Actor_HasParent(this))
    {
        this->attachedA = NULL;
        gOotExtraFlags.tunicZora = 1;
        return 1;
    }
    return 0;
}

PATCH_CALL(0x80ad6c5c, EnZk_HasGiveItem);

void EnZk_GiveItem(Actor* this, GameState_Play* play, s16 gi, float a, float b)
{
    int npc;

    if (!(GET_LINK(play)->state & PLAYER_ACTOR_STATE_GET_ITEM))
        Message_Close(play);

    if (!gOotExtraFlags.tunicZora)
    {
        npc = NPC_OOT_ZORA_KING_TUNIC;
    }
    else
    {
        npc = NPC_OOT_TRADE_EYEBALL_FROG;
        comboRemoveTradeItemAdult(XITEM_OOT_ADULT_PRESCRIPTION);
    }

    comboGiveItemNpc(this, play, gi, npc, a, b);
}

PATCH_CALL(0x80ad6cc8, EnZk_GiveItem);
