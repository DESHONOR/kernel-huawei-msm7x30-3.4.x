/* Copyright (c) 2009, The Linux Foundation. All rights reserved.
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

#include "mt9p012.h"
#include <linux/kernel.h>
#include <linux/bug.h>
/*Micron settings from Applications for lower power consumption.*/
struct reg_struct const mt9p012_reg_pat[2] = {
	{ /* Preview */
		/* vt_pix_clk_div          REG=0x0300 */
		6,  /* 5 */

		/* vt_sys_clk_div          REG=0x0302 */
		1,
		/* pre_pll_clk_div         REG=0x0304 */
		2,
		/* pll_multiplier          REG=0x0306 */
		60,

		/* op_pix_clk_div          REG=0x0308 */
		8,  /* 10 */

		/* op_sys_clk_div          REG=0x030A */
		1,

		/* scale_m                 REG=0x0404 */
		16,

		/* row_speed               REG=0x3016 */
		0x0111,

		/* x_addr_start            REG=0x3004 */
		8,

		/* x_addr_end              REG=0x3008 */
		2597,

		/* y_addr_start            REG=0x3002 */
		8,

		/* y_addr_end              REG=0x3006 */
		1949,

		/* read_mode               REG=0x3040
		 * Preview 2x2 skipping */
		0x00C3,

		/* x_output_size           REG=0x034C */
		1296,

		/* y_output_size           REG=0x034E */
		972,

		/* line_length_pck         REG=0x300C */
		3659,

		/* frame_length_lines      REG=0x300A */
		1074,

		/* coarse_integration_time REG=0x3012 */
		16,

		/* fine_integration_time   REG=0x3014 */
		1764
	},
	{ /* Snapshot */
		/* vt_pix_clk_div          REG=0x0300 */
		6,

		/* vt_sys_clk_div          REG=0x0302 */
		1,

		/* pre_pll_clk_div         REG=0x0304 */
		2,

		/* pll_multiplier          REG=0x0306
		 * 60 for 10fps snapshot */
		60,

		/* op_pix_clk_div          REG=0x0308 */
		8,

		/* op_sys_clk_div          REG=0x030A */
		1,

		/* scale_m                 REG=0x0404 */
		16,

		/* row_speed               REG=0x3016 */
		0x0111,

		/* x_addr_start            REG=0x3004 */
		8,

		/* x_addr_end              REG=0x3008 */
		2615,

		/* y_addr_start            REG=0x3002 */
		8,

		/* y_addr_end              REG=0x3006 */
		1967,

		/* read_mode               REG=0x3040 */
		0x0041,

		/* x_output_size           REG=0x034C */
		2608,

		/* y_output_size           REG=0x034E */
		1960,

		/* line_length_pck         REG=0x300C */
		3911,

		/* frame_length_lines      REG=0x300A 10 fps snapshot */
		2045,

		/* coarse_integration_time REG=0x3012 */
		16,

		/* fine_integration_time   REG=0x3014 */
		882
	}
};


struct mt9p012_i2c_reg_conf const mt9p012_test_tbl[] = {
	{0x3044, 0x0544 & 0xFBFF},
	{0x30CA, 0x0004 | 0x0001},
	{0x30D4, 0x9020 & 0x7FFF},
	{0x31E0, 0x0003 & 0xFFFE},
	{0x3180, 0x91FF & 0x7FFF},
	{0x301A, (0x10CC | 0x8000) & 0xFFF7},
	{0x301E, 0x0000},
	{0x3780, 0x0000},
};
struct mt9p012_i2c_reg_conf const mt9p012_rolloff_tbl[] = {
	{0x360A, 0x0110},
	{0x360C, 0x270D},
	{0x360E, 0x0071},
	{0x3610, 0xA38D},
	{0x3612, 0xA610},
	{0x364A, 0x8F49},
	{0x364C, 0x696A},
	{0x364E, 0x0FCD},
	{0x3650, 0x20ED},
	{0x3652, 0x81ED},
	{0x368A, 0x1031},
	{0x368C, 0xBCAD},
	{0x368E, 0x77AA},
	{0x3690, 0xD10E},
	{0x3692, 0xC133},
	{0x36CA, 0x4F8D},
	{0x36CC, 0xAC4D},
	{0x36CE, 0xC8CE},
	{0x36D0, 0x73AD},
	{0x36D2, 0xC150},
	{0x370A, 0xB590},
	{0x370C, 0x9010},
	{0x370E, 0xAC52},
	{0x3710, 0x4D51},
	{0x3712, 0x5670},
	{0x3600, 0x00F0},
	{0x3602, 0xCE4B},
	{0x3604, 0x4270},
	{0x3606, 0x8BC9},
	{0x3608, 0xFA2F},
	{0x3640, 0x9A09},
	{0x3642, 0xB40C},
	{0x3644, 0x4ECD},
	{0x3646, 0x1BCC},
	{0x3648, 0xD68E},
	{0x3680, 0x1BF0},
	{0x3682, 0xC94D},
	{0x3684, 0x714F},
	{0x3686, 0x1491},
	{0x3688, 0xB8D3},
	{0x36C0, 0x3E49},
	{0x36C2, 0x7A6C},
	{0x36C4, 0xEF2E},
	{0x36C6, 0xE0EE},
	{0x36C8, 0x570F},
	{0x3700, 0xD6AF},
	{0x3702, 0x2251},
	{0x3704, 0x8A33},
	{0x3706, 0xEFB3},
	{0x3708, 0x1174},
	{0x3614, 0x0150},
	{0x3616, 0xA9AB},
	{0x3618, 0x1770},
	{0x361A, 0x8809},
	{0x361C, 0xE3AE},
	{0x3654, 0x5ACC},
	{0x3656, 0x35EA},
	{0x3658, 0x2DEC},
	{0x365A, 0xB90B},
	{0x365C, 0x250C},
	{0x3694, 0x1630},
	{0x3696, 0xD88C},
	{0x3698, 0xBD0E},
	{0x369A, 0x16D1},
	{0x369C, 0xE492},
	{0x36D4, 0x5D6D},
	{0x36D6, 0x906E},
	{0x36D8, 0x10AE},
	{0x36DA, 0x7A8E},
	{0x36DC, 0x9672},
	{0x3714, 0x8D90},
	{0x3716, 0x04F1},
	{0x3718, 0x23F1},
	{0x371A, 0xF313},
	{0x371C, 0xE833},
	{0x361E, 0x0490},
	{0x3620, 0x14CD},
	{0x3622, 0x38F0},
	{0x3624, 0xBAED},
	{0x3626, 0xFF6F},
	{0x365E, 0x358C},
	{0x3660, 0xA9E9},
	{0x3662, 0x4A4E},
	{0x3664, 0x398D},
	{0x3666, 0x890F},
	{0x369E, 0x2DF0},
	{0x36A0, 0xF7CE},
	{0x36A2, 0xB3CC},
	{0x36A4, 0x118D},
	{0x36A6, 0x9CB3},
	{0x36DE, 0x462D},
	{0x36E0, 0x74AA},
	{0x36E2, 0xC8CF},
	{0x36E4, 0x8DEF},
	{0x36E6, 0xF130},
	{0x371E, 0x9250},
	{0x3720, 0x19CC},
	{0x3722, 0xDFD1},
	{0x3724, 0x5B70},
	{0x3726, 0x34D2},
	{0x3782, 0x0530},
	{0x3784, 0x03C8},
	{0x3780, 0x8000},
};

struct mt9p012_reg mt9p012_regs = {
	.reg_pat = &mt9p012_reg_pat[0],
	.reg_pat_size = ARRAY_SIZE(mt9p012_reg_pat),
	.ttbl = &mt9p012_test_tbl[0],
	.ttbl_size = ARRAY_SIZE(mt9p012_test_tbl),
	.rftbl = &mt9p012_rolloff_tbl[0],
	.rftbl_size = ARRAY_SIZE(mt9p012_rolloff_tbl)
};


