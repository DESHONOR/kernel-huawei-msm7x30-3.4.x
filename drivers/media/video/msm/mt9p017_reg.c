/*< DTS2012020400396 zhangyu 20120206 begin */
/*< DTS2011092106898   yuguangcai 20110924 begin */

/* Copyright (c) 2010, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#include "mt9p017.h"
#include <linux/kernel.h>
#include <linux/bug.h>

/*Micron settings from Applications for lower power consumption.*/
struct reg_struct const mt9p017_reg_pat[2] =
{
/* <DTS2012041003722 sibingsong 20120410 begin */
/*<DTS2012031902158 wangqing 20120319 begin*/
    { /* Preview */
      /* vt_pix_clk_div          REG=0x0300 */
        13,		/* 5 */

        /* vt_sys_clk_div          REG=0x0302 */
        1,

        /* pre_pll_clk_div         REG=0x0304 */
        2,

        /* pll_multiplier          REG=0x0306 */
        54,

        /* op_pix_clk_div          REG=0x0308 */
        10,		/* 10 */

        /* op_sys_clk_div          REG=0x030A */
        1,

        /* scale_m                 REG=0x0404 */
        16,

        /* row_speed               REG=0x3016 */
        0x0111,

        /* x_addr_start            REG=0x3004 */
        0,

        /* x_addr_end              REG=0x3008 */
        2605,

        /* y_addr_start            REG=0x3002 */
        0,

        /* y_addr_end              REG=0x3006 */
        1957,

        /* read_mode               REG=0x3040
         * Preview 2x2 skipping */
        /*< DTS2011102101224 yuguangcai 20111104 begin */
        0xC4C3, /* 0x046C 2x2 binning, 14 and 15 bits for flip and mirror */
        /* DTS2011102101224 yuguangcai 20111104 end > */

        /* x_output_size           REG=0x034C */
        1304,

        /* y_output_size           REG=0x034E */
        980,

        /* line_length_pck         REG=0x300C */
        3178,

        /* frame_length_lines      REG=0x300A */
        1053,

        /* coarse_integration_time REG=0x3012 */
        1052,

        /* fine_integration_time   REG=0x3014 */
        2342,

        /* fine_correction         REG=0x3010 */
        388,

        /* vcm_control             REG=0x30F0 */
        0x8000,
    },
/*DTS2012031902158  wangqing 20120319 end>*/
/* DTS2012041003722 sibingsong 20120410 end> */
    { /* Snapshot */
      /* vt_pix_clk_div          REG=0x0300 */
        13,

        /* vt_sys_clk_div          REG=0x0302 */
        1,

        /* pre_pll_clk_div         REG=0x0304 */
        2,

        /* pll_multiplier          REG=0x0306
         * 60 for 10fps snapshot */
        54,

        /* op_pix_clk_div          REG=0x0308 */
        10,

        /* op_sys_clk_div          REG=0x030A */
        1,

        /* scale_m                 REG=0x0404 */
        16,

        /* row_speed               REG=0x3016 */
        0x0111,

        /* x_addr_start            REG=0x3004 */
        0,

        /* x_addr_end              REG=0x3008 */
        2607,

        /* y_addr_start            REG=0x3002 */
        0,

        /* y_addr_end              REG=0x3006 */
        1959,

        /*< DTS2011102101224 yuguangcai 20111104 begin */
        /* read_mode               REG=0x3040 */
        0xC041,
        /* DTS2011102101224 yuguangcai 20111104 end > */

        /* x_output_size           REG=0x034C */
        2608,

        /* y_output_size           REG=0x034E */
        1960,

        /* line_length_pck         REG=0x300C */
        5756,   //0x167C,

        /* frame_length_lines      REG=0x300A 10 fps snapshot */
        2037,   //0x7F5,

        /* coarse_integration_time REG=0x3012 */
        2036,   //0x7F4,

        /* fine_integration_time   REG=0x3014 */
        5274,   //0x149A,

        /* fine_correction         REG=0x3010 */
        0xA0,

        /* vcm_control             REG=0x30F0 */
        0x8000,
    }
};

struct mt9p017_i2c_reg_conf const mt9p017_rolloff_tbl[] =
{
/*< DTS2012011202784   songxiaoming 20120112 begin */
    {0x3600, 0x00D0},
    {0x3602, 0x332B},
    {0x3604, 0x00F1},
    {0x3606, 0x872B},
    {0x3608, 0xC38E},
    {0x360A, 0x0450},
    {0x360C, 0xC08E},
    {0x360E, 0x77F0},
    {0x3610, 0x61AE},
    {0x3612, 0x910E},
    {0x3614, 0x0690},
    {0x3616, 0x1B8E},
    {0x3618, 0x07F0},
    {0x361A, 0x8A6F},
    {0x361C, 0x4DCD},
    {0x361E, 0x0470},
    {0x3620, 0xED2E},
    {0x3622, 0x21D1},
    {0x3624, 0x49AD},
    {0x3626, 0x8590},
    {0x3640, 0xA7AC},
    {0x3642, 0xB1AC},
    {0x3644, 0xE9CF},
    {0x3646, 0x84CF},
    {0x3648, 0x4F10},
    {0x364A, 0xE32B},
    {0x364C, 0x718D},
    {0x364E, 0x862E},
    {0x3650, 0x9A2E},
    {0x3652, 0x140D},
    {0x3654, 0x4AED},
    {0x3656, 0x314E},
    {0x3658, 0x0E2E},
    {0x365A, 0x8B6F},
    {0x365C, 0xFFCE},
    {0x365E, 0x1BED},
    {0x3660, 0xD60E},
    {0x3662, 0x09F0},
    {0x3664, 0x088F},
    {0x3666, 0x8171},
    {0x3680, 0x0FF1},
    {0x3682, 0x24EE},
    {0x3684, 0x6291},
    {0x3686, 0x00D1},
    {0x3688, 0xAB73},
    {0x368A, 0x0051},
    {0x368C, 0xCC6F},
    {0x368E, 0x5992},
    {0x3690, 0x67F0},
    {0x3692, 0xF553},
    {0x3694, 0x4E90},
    {0x3696, 0x774D},
    {0x3698, 0x1551},
    {0x369A, 0x63B0},
    {0x369C, 0xBDD2},
    {0x369E, 0x0DD1},
    {0x36A0, 0xA00E},
    {0x36A2, 0x466C},
    {0x36A4, 0x064E},
    {0x36A6, 0xB731},
    {0x36C0, 0x070E},
    {0x36C2, 0x8C0E},
    {0x36C4, 0x8ACD},
    {0x36C6, 0x1DD1},
    {0x36C8, 0x97EF},
    {0x36CA, 0x44CD},
    {0x36CC, 0x52AD},
    {0x36CE, 0xF74E},
    {0x36D0, 0x51EE},
    {0x36D2, 0x1FB0},
    {0x36D4, 0xC0CD},
    {0x36D6, 0xD36E},
    {0x36D8, 0x124C},
    {0x36DA, 0x6D10},
    {0x36DC, 0xB06E},
    {0x36DE, 0x030D},
    {0x36E0, 0x59EE},
    {0x36E2, 0xEA30},
    {0x36E4, 0x070E},
    {0x36E6, 0x3251},
    {0x3700, 0xF6AF},
    {0x3702, 0x256F},
    {0x3704, 0x81B4},
    {0x3706, 0xF232},
    {0x3708, 0x0E35},
    {0x370A, 0x1070},
    {0x370C, 0x2D30},
    {0x370E, 0xD6F4},
    {0x3710, 0xE9D1},
    {0x3712, 0x3A75},
    {0x3714, 0xF7ED},
    {0x3716, 0xCA2D},
    {0x3718, 0x9D73},
    {0x371A, 0xEE31},
    {0x371C, 0x2DF4},
    {0x371E, 0xFEAF},
    {0x3720, 0x154B},
    {0x3722, 0xD4F2},
    {0x3724, 0x7411},
    {0x3726, 0x7632},
    {0x3782, 0x04A4},
    {0x3784, 0x03A0},
    {0x37C0, 0xBBA9},
    {0x37C2, 0xAA08},
    {0x37C4, 0xACEA},
    {0x37C6, 0xD8EA},
    {0x3780, 0x8000},
/* DTS2012011202784  songxiaoming 20120112 end > */
};

/* <DTS2012041003722 sibingsong 20120410 begin */
/* < DTS2012040200700 zhangyu 20120402 begin */
/* change the reg from rev3 to rev4 */
struct mt9p017_i2c_reg_conf const mt9p017_ptiming_tbl[] =
{
	{0x3E00, 0x042F},
	{0x3E02, 0xFFFF},
	{0x3E04, 0xFFFF},
	{0x3E06, 0xFFFF},
	{0x3E08, 0x8071},
	{0x3E0A, 0x7281},
	{0x3E0C, 0x4011},
	{0x3E0E, 0x8010},
	{0x3E10, 0x60A5},
	{0x3E12, 0x4080},
	{0x3E14, 0x4180},
	{0x3E16, 0x0018},
	{0x3E18, 0x46B7},
	{0x3E1A, 0x4994},
	{0x3E1C, 0x4997},
	{0x3E1E, 0x4682},
	{0x3E20, 0x0018},
	{0x3E22, 0x4241},
	{0x3E24, 0x8000},
	{0x3E26, 0x1880},
	{0x3E28, 0x4785},
	{0x3E2A, 0x4992},
	{0x3E2C, 0x4997},
	{0x3E2E, 0x4780},
	{0x3E30, 0x4D80},
	{0x3E32, 0x100C},
	{0x3E34, 0x8000},
	{0x3E36, 0x184A},
	{0x3E38, 0x8042},
	{0x3E3A, 0x001A},
	{0x3E3C, 0x9610},
	{0x3E3E, 0x0C80},
	{0x3E40, 0x4DC6},
	{0x3E42, 0x4A80},
	{0x3E44, 0x0018},
	{0x3E46, 0x8042},
	{0x3E48, 0x8041},
	{0x3E4A, 0x0018},
	{0x3E4C, 0x804B},
	{0x3E4E, 0xB74B},
	{0x3E50, 0x8010},
	{0x3E52, 0x6056},
	{0x3E54, 0x001C},
	{0x3E56, 0x8211},
	{0x3E58, 0x8056},
	{0x3E5A, 0x827C},
	{0x3E5C, 0x0970},
	{0x3E5E, 0x8082},
	{0x3E60, 0x7281},
	{0x3E62, 0x4C40},
	{0x3E64, 0x8E4D},
	{0x3E66, 0x8110},
	{0x3E68, 0x0CAF},
	{0x3E6A, 0x4D80},
	{0x3E6C, 0x100C},
	{0x3E6E, 0x8440},
	{0x3E70, 0x4C81},
	{0x3E72, 0x7C5F},
	{0x3E74, 0x7000},
	{0x3E76, 0x0000},
	{0x3E78, 0x0000},
	{0x3E7A, 0x0000},
	{0x3E7C, 0x0000},
	{0x3E7E, 0x0000},
	{0x3E80, 0x0000},
	{0x3E82, 0x0000},
	{0x3E84, 0x0000},
	{0x3E86, 0x0000},
	{0x3E88, 0x0000},
	{0x3E8A, 0x0000},
	{0x3E8C, 0x0000},
	{0x3E8E, 0x0000},
	{0x3E90, 0x0000},
	{0x3E92, 0x0000},
	{0x3E94, 0x0000},
	{0x3E96, 0x0000},
	{0x3E98, 0x0000},
	{0x3E9A, 0x0000},
	{0x3E9C, 0x0000},
	{0x3E9E, 0x0000},
	{0x3EA0, 0x0000},
	{0x3EA2, 0x0000},
	{0x3EA4, 0x0000},
	{0x3EA6, 0x0000},
	{0x3EA8, 0x0000},
	{0x3EAA, 0x0000},
	{0x3EAC, 0x0000},
	{0x3EAE, 0x0000},
	{0x3EB0, 0x0000},
	{0x3EB2, 0x0000},
	{0x3EB4, 0x0000},
	{0x3EB6, 0x0000},
	{0x3EB8, 0x0000},
	{0x3EBA, 0x0000},
	{0x3EBC, 0x0000},
	{0x3EBE, 0x0000},
	{0x3EC0, 0x0000},
	{0x3EC2, 0x0000},
	{0x3EC4, 0x0000},
	{0x3EC6, 0x0000},
	{0x3EC8, 0x0000},
	{0x3ECA, 0x0000},
	{0x3170, 0x2150},
	{0x317A, 0x0150},
	{0x3ECC, 0x2200},
	{0x3174, 0x0000},
	{0x3176, 0X0000},
	{0x31B0, 0x00C4},
	{0x31B2, 0x0064},
	{0x31B4, 0x0E77},
	{0x31B6, 0x0D24},
	{0x31B8, 0x020E},
	{0x31BA, 0x0710},
	{0x31BC, 0x2A0D},
	{0x31BE, 0xC007},
};

struct mt9p017_i2c_reg_conf const mt9p017_recommend_settings[] =
{
    /*<DTS2012021600809  wangqing 20120216 begin*/
    {0x3100, 0x0000},
    /*DTS2012021600809  wangqing 20120216 end>*/
	{0x316A, 0x8400},
	{0x316C, 0x8400},
	{0x316E, 0x8400},
	{0x3EFA, 0x1A1F},
	{0x3ED2, 0xD965},
	{0x3ED8, 0x7F1B},
	{0x3EDA, 0xAF11},
	{0x3EE2, 0x0060},
	{0x3EF2, 0xD965},
	{0x3EF8, 0x797F},
	{0x3EFC, 0xA8EF},
	{0x30d4, 0x9200},
	{0x30b2, 0xC000},
	{0x30bc, 0x0400},
	{0x306E, 0xB480},
	{0x3EFE, 0x1F0F},
	{0x31E0, 0x1F01},
};
/* DTS2012040200700 zhangyu 20120402 end > */
/* DTS2012041003722 sibingsong 20120410 end> */

struct mt9p017_reg mt9p017_regs =
{
    .reg_pat      = &mt9p017_reg_pat[0],
    .reg_pat_size = ARRAY_SIZE(mt9p017_reg_pat),
    .rftbl        = &mt9p017_rolloff_tbl[0],
    .rftbl_size   = ARRAY_SIZE(mt9p017_rolloff_tbl),
    .pttbl        = &mt9p017_ptiming_tbl[0],
    .pttbl_size   = ARRAY_SIZE(mt9p017_ptiming_tbl),
    .rec_settings = &mt9p017_recommend_settings[0],
    .rec_size     = ARRAY_SIZE(mt9p017_recommend_settings),
};

/* DTS2011092106898   yuguangcai 20110924 end > */
/* DTS2012020400396 zhangyu 20120206 end > */
