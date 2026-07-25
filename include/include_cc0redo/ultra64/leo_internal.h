#ifndef LEO_INTERNAL_H
#define LEO_INTERNAL_H

#include "unk.h"

extern OSPiHandle* LEOPiInfo;
extern u32 D_801E67F0;
extern s32 D_801E67F4;
extern u8 LEOdrive_flag;
void leointerrupt(void*);
void leomain(void*);
extern OSMesgQueue D_801E5A00;
extern void* D_801E5A18;
extern OSMesgQueue LEOblock_que;
extern void* LEOblock_que_buf;
extern OSThread LEOcommandThread;
extern OSMesgQueue LEOcommand_que;
extern OSMesgQueue LEOcontrol_que;
extern void* LEOcontrol_que_buf;
extern OSMesgQueue LEOdma_que;
extern void* LEOdma_que_buf;
extern OSMesgQueue LEOevent_que;
extern void* LEOevent_que_buf;
extern OSThread LEOinterruptThread;
extern STACK(LEOcommandThreadStack, 0x400);
extern STACK(LEOinterruptThreadStack, 0x400);
extern s32 __leoQueuesCreated;
UNK_RET leoClr_queue(void);
extern vu8 LEOclr_que_flag;
extern s32 __leoResetCalled;
u8 leoSend_asic_cmd_i(u32 asic_cmd, u32 asic_data);
u8 leoChk_asic_ready(u32);
s32 leoRecv_event_mesg(s32);
void leoDrive_reset(void);
extern s32 __leoActive;
extern LEOCmd* LEOcur_command;
extern struct tgt_param_form {
    /* 0x0 */ u16 lba;
    /* 0x2 */ u16 cylinder;
    /* 0x4 */ u16 blk_bytes;
    /* 0x6 */ u8 sec_bytes;
    /* 0x7 */ u8 head;
    /* 0x8 */ u8 zone;
    /* 0x9 */ u8 rdwr_blocks;
    /* 0xA */ u8 start_block;
} LEOtgt_param;
s32 __leoSetReset(void);
s32 __osLeoInterrupt(void);
OSPiHandle* osLeoDiskInit(void);
extern UNK_TYPE D_801E8080;
extern u32 LEO_country_code;
extern LEOVersion __leoVersion;
extern STACK(leoDiskStack, 0xFF0);
void func_801D3190(void);
void func_801D3244(void);
extern s32 D_800068E0;
extern u8 LEOdisk_type;
extern const u16 LEOBYTE_TBL2[];
extern const u16 LEOVZONE_TBL[][0x10];
extern const u8 LEOVZONE_PZONEHD_TBL[][0x10];
u16 leoLba_to_vzone(u32 lba);
u32 func_801CB650(void); // "read_write_track"
u16 leoLba_to_phys(u32 lba);
u8 leoSeek_i(u16 rwmode);
extern OSMesgQueue LEOc2ctrl_que;
extern void* LEOc2ctrl_que_buf;
extern u16 LEOrw_flags;
extern void* LEOwrite_pointer;
u32 leoChkUnit_atten(void);
u8 leoChk_cur_drvmode(void);
void leoClrUA_RESET(void);
void leoInitUnit_atten(void);
u8 leoRead_system_area(void);
u32 leoRetUnit_atten(void);
u8 leoSend_asic_cmd_w(u32 asic_cmd, u32 asic_data);
extern UNK_FUN_PTR(D_801D95F0[]);
extern OSIoMesg LEOPiDmaParam;
extern s32 LEOasic_bm_ctl_shadow;
extern s32 LEOasic_seq_ctl_shadow;
extern s32 currentCommand;
typedef union leo_sys_form {
    /* 0x0 */ struct {
        /* 0x0 */ u32 country;
        /* 0x4 */ u8 fmt_type;
        /* 0x5 */ u8 disk_type;
        /* 0x6 */ u16 ipl_load_len;
        /* 0x8 */ u8 defect_num[20];
        /* 0x1C */ void* loadptr;
        /* 0x20 */ u8 defect_data[192];
        /* 0xE0 */ u16 rom_end_lba;
        /* 0xE2 */ u16 ram_start_lba;
        /* 0xE4 */ u16 ram_end_lba;
    } param;
    /* 0x0 */ u64 u64_data[29];
} leo_sys_form;
extern leo_sys_form LEO_sys_data;

#endif
