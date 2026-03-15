#include "global.h"
#include "ovl_Bg_Haka_Trap.h"

#define FLAGS 0

void BgHakaTrap_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTrap_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTrap_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaTrap_Draw(Actor* thisx, GlobalContext* globalCtx);

extern const ActorInit Bg_Haka_Trap_InitVars;
#if 0
const ActorInit Bg_Haka_Trap_InitVars = {
    /**/ ACTOR_BG_HAKA_TRAP,
    /**/ ACTORTYPE_BG,
    /**/ FLAGS,
    /**/ OBJECT_HAKA_OBJECTS,
    /**/ sizeof(BgHakaTrap),
    /**/ BgHakaTrap_Init,
    /**/ BgHakaTrap_Destroy,
    /**/ BgHakaTrap_Update,
    /**/ BgHakaTrap_Draw,
};
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/BgHakaTrap_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/BgHakaTrap_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_8087FFC0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808801B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808802D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_80880484.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808805C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808806BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808808F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808809B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_808809E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_80880AE8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_80880C0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/BgHakaTrap_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/func_80880D68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Bg_Haka_Trap/BgHakaTrap_Draw.s")
