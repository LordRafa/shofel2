#ifndef _T124_RCM_H_
#define _T124_RCM_H_

#define JETSON_TK1_VID 0x0955
#define JETSON_TK1_PID 0x7140

#define SHIELD_TK1_VID 0x0955
#define SHIELD_TK1_PID 0x7f40

#define IROM_BEGIN              0x00100000
#define IROM_END                0x0010FFFF
#define IROM_LEN                0x00010000

#define IRAM_BEGIN              0x40000000
#define IRAM_END                0x4003FFFF
#define IRAM_LEN                0x00040000

#define BOOTROM_DO_BCT_BOOT         0x00100624
#define BOOTROM_EP1_IN_WRITE_IMM    0x001065C0
#define BOOTROM_EP1_OUT_READ_IMM    0x00106612
#define BOOTROM_USB_BUF_1           0x40004000
#define BOOTROM_USB_BUF_2           0x40008000
#define BOOTROM_PAYLOAD_ENTRY       0x4000E000
#define BOOTROM_SMASH_TARGET        0x4000DCD8
#define BOOTROM_STACK_GAP_LEN           0x30C
#define BOOTROM_SMASH_LEN           (BOOTROM_SMASH_TARGET - BOOTROM_USB_BUF_2) // 0x5CD8

#define VARS_LEN 0x10

#define INTERMEZZO_LEN 0x100
#define INTERMEZZO_REL_ADD ( BOOTROM_PAYLOAD_ENTRY - INTERMEZZO_LEN ) // 0x4000DF00

#define OFFSET_INTERMEZZO_START     0x0
#define OFFSET_PAYLOAD_START        ( INTERMEZZO_LEN )
#define OFFSET_MEMCPY_RET_ADD       ( BOOTROM_SMASH_LEN - BOOTROM_STACK_GAP_LEN - 0x4 ) // 0x59C8 ( 0x30C Bytes copied from the stack before entry )
#define OFFSET_PAYLOAD_BEF_LENVAR   ( OFFSET_MEMCPY_RET_ADD - 0x4 )
#define OFFSET_PAYLOAD_AFT_LENVAR   ( OFFSET_MEMCPY_RET_ADD - 0x8 )
#define OFFSET_PAYLOAD_THUMB_MODE   ( OFFSET_MEMCPY_RET_ADD - 0xC )
#define OFFSET_PAYLOAD_CONT         ( OFFSET_MEMCPY_RET_ADD + 0x4 )


#define IRAM_ADD_INTERMEZZO_START    ( BOOTROM_PAYLOAD_ENTRY + OFFSET_INTERMEZZO_START )
#define IRAM_ADD_PAYLOAD_START       ( BOOTROM_PAYLOAD_ENTRY + OFFSET_PAYLOAD_START )
#define IRAM_ADD_PAYLOAD_BEF_LENVAR  ( BOOTROM_PAYLOAD_ENTRY + OFFSET_PAYLOAD_BEF_LENVAR )
#define IRAM_ADD_PAYLOAD_AFT_LENVAR  ( BOOTROM_PAYLOAD_ENTRY + OFFSET_PAYLOAD_AFT_LENVAR )
#define IRAM_ADD_PAYLOAD_THUMB_MODE  ( BOOTROM_PAYLOAD_ENTRY + OFFSET_PAYLOAD_THUMB_MODE )
#define IRAM_ADD_PAYLOAD_CONT        ( BOOTROM_PAYLOAD_ENTRY + OFFSET_PAYLOAD_CONT )


#define RCM_EP1_IN      0x81
#define RCM_EP1_OUT     0x01
#define RCM_CHIP_ID_LEN 0x10

#define RCM_CMD_LEN 0x32274
#define RCM_CMD_MAX_USEFUL_LEN 0x31000 // Ensures Header + Payload + Padding doesn't complete RCM CMD and buffer 2 is used for getstatus.
#define RCM_CMD_HEADER_LEN 0x284

#define RCM_CMD_BUF_INTERMEZZO_START     ( RCM_CMD_HEADER_LEN + OFFSET_INTERMEZZO_START )
#define RCM_CMD_BUF_PAYLOAD_START        ( RCM_CMD_HEADER_LEN + OFFSET_PAYLOAD_START )
#define RCM_CMD_BUF_MEMCPY_RET_ADD       ( RCM_CMD_HEADER_LEN + OFFSET_MEMCPY_RET_ADD )
#define RCM_CMD_BUF_PAYLOAD_BEF_LENVAR   ( RCM_CMD_HEADER_LEN + OFFSET_PAYLOAD_BEF_LENVAR )
#define RCM_CMD_BUF_PAYLOAD_AFT_LENVAR   ( RCM_CMD_HEADER_LEN + OFFSET_PAYLOAD_AFT_LENVAR )
#define RCM_CMD_BUF_PAYLOAD_THUMB_MODE   ( RCM_CMD_HEADER_LEN + OFFSET_PAYLOAD_THUMB_MODE )
#define RCM_CMD_BUF_PAYLOAD_CONT         ( RCM_CMD_HEADER_LEN + OFFSET_PAYLOAD_CONT )


#define MAX_PAYLOAD_BEF_SIZE        ( OFFSET_PAYLOAD_THUMB_MODE - OFFSET_PAYLOAD_START ) // 22716 Bytes
#define MAX_PAYLOAD_AFT_SIZE        ( RCM_CMD_MAX_USEFUL_LEN - RCM_CMD_BUF_PAYLOAD_CONT ) // 177072 Bytes
#define MAX_PAYLOAD_FILE_SIZE       ( MAX_PAYLOAD_BEF_SIZE + MAX_PAYLOAD_AFT_SIZE ) // 199788 Bytes


#define SECURE_BOOT_BASE	0x6000C200
#define SB_CSR_0            0x0
#define SB_PIROM_START_0    0x4
#define SB_PFCFG_0		    0x8
#define JTAG_ON		        0x00000080

#define APB_BASE	0x70000000
#define APB_MISC_PP_CONFIG_CTL_0	0x24
#define APB_MISC_PP_CONFIG_CTL_0_JTAG				0x40
#define APB_MISC_PP_CONFIG_CTL_0_TBE 				0x80

#define FLOW_CTLR_BASE  0x60007000
#define FLOW_CTLR_HALT_COP_EVENTS_0  0x4
#define FLOW_CTLR_HALT_COP_FLOW_MODE_WAITEVENT (1 << 30)
#define FLOW_CTLR_HALT_COP_JTAG           (1 << 28)

#define PMC_BASE               0x7000e400
#define PMC_CNTRL              0x000
#define PMC_CNTRL_MAIN_RST    (1 << 4)
#define PMC_SCRATCH0           0x050
#define PMC_SCRATCH0_MODE_RCM (1 << 1)

#define FUSE_BASE   0x7000F900
#define FUSE_LEN   0x300


#endif

