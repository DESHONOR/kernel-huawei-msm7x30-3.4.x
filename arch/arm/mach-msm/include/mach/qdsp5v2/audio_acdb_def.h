/* Copyright (c) 2010 - 2011, The Linux Foundation. All rights reserved.
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
 */
#ifndef _MACH_QDSP5_V2_AUDIO_ACDB_DEF_H
#define _MACH_QDSP5_V2_AUDIO_ACDB_DEF_H

/* Define ACDB device ID */
#define ACDB_ID_HANDSET_SPKR				1
#define ACDB_ID_HANDSET_MIC				2
#define ACDB_ID_HEADSET_MIC				3
#define ACDB_ID_HEADSET_SPKR_MONO			4
#define ACDB_ID_HEADSET_SPKR_STEREO			5
#define ACDB_ID_SPKR_PHONE_MIC				6
#define ACDB_ID_SPKR_PHONE_MONO				7
#define ACDB_ID_SPKR_PHONE_STEREO			8
#define ACDB_ID_BT_SCO_MIC				9
#define ACDB_ID_BT_SCO_SPKR				0x0A
#define ACDB_ID_BT_A2DP_SPKR				0x0B
#define ACDB_ID_BT_A2DP_TX				0x10
#define ACDB_ID_TTY_HEADSET_MIC				0x0C
#define ACDB_ID_TTY_HEADSET_SPKR			0x0D
#define ACDB_ID_HEADSET_MONO_PLUS_SPKR_MONO_RX		0x11
#define ACDB_ID_HEADSET_STEREO_PLUS_SPKR_STEREO_RX	0x14
#define ACDB_ID_FM_TX_LOOPBACK				0x17
#define ACDB_ID_FM_TX					0x18
#define ACDB_ID_LP_FM_SPKR_PHONE_STEREO_RX		0x19
#define ACDB_ID_LP_FM_HEADSET_SPKR_STEREO_RX		0x1A
#define ACDB_ID_I2S_RX					0x20
#define ACDB_ID_SPKR_PHONE_MIC_BROADSIDE		0x2B
#define ACDB_ID_HANDSET_MIC_BROADSIDE			0x2C
#define ACDB_ID_SPKR_PHONE_MIC_ENDFIRE			0x2D
#define ACDB_ID_HANDSET_MIC_ENDFIRE			0x2E
#define ACDB_ID_I2S_TX					0x30
#define ACDB_ID_HDMI					0x40
#define ACDB_ID_FM_RX					0x4F

/* Huawei msm7x30 device */
#ifdef CONFIG_HUAWEI_KERNEL
#define ACDB_ID_SPKR_PHONE_MUSIC_MONO				0xF0
#define ACDB_ID_SPKR_PHONE_MUSIC_STEREO				0xF1
#define ACDB_ID_HEADSET_SPKR_MUSIC_STEREO			0xF2
#define ACDB_ID_HANDSET_HAC_SPKR					0xF3
#define ACDB_ID_SPKR_PHONE_PTT						0xF4
#define ACDB_ID_SPKR_PHONE_PTT_MIC					0xF5
#define ACDB_ID_HEADSET_STEREO_PLUS_SPKR_MONO_RX	0x13
#endif


/*Replace the max device ID,if any new device is added Specific to RTC only*/
#define ACDB_ID_MAX                                 ACDB_ID_SPKR_PHONE_PTT_MIC

/* ID used for virtual devices */
#define PSEUDO_ACDB_ID 					0xFFFF

/* Samsung msm7x30 device */
#define ACDB_ID_HANDSET_RX				1000
#define ACDB_ID_HANDSET_TX				1001
#define ACDB_ID_SPEAKER_RX				1002
#define ACDB_ID_SPEAKER_TX				1003
#define ACDB_ID_HEADSET_RX				1004
#define ACDB_ID_HEADSET_TX				1005
#define ACDB_ID_BT_SCO_RX				1006
#define ACDB_ID_BT_SCO_TX				1007
#define ACDB_ID_BT_SCO_NREC_RX				1008
#define ACDB_ID_BT_SCO_NREC_TX				1009
#define ACDB_ID_HDMI_STEREO_RX				1030
#define ACDB_ID_AUX_DOCK_RX				1031
#define ACDB_ID_SPEAKER_HEADSET_RX			1032
#define ACDB_ID_SPEAKER_DOCK_RX				1033
#define ACDB_ID_SPEAKER_HDMI_RX				1034
#define ACDB_ID_HANDSET_CALL_RX				1050
#define ACDB_ID_HANDSET_CALL_TX				1051
#define ACDB_ID_SPEAKER_CALL_RX				1052
#define ACDB_ID_SPEAKER_CALL_TX				1053
#define ACDB_ID_HEADSET_CALL_RX				1054
#define ACDB_ID_HEADSET_CALL_TX				1055
#define ACDB_ID_BT_SCO_CALL_RX				1056
#define ACDB_ID_BT_SCO_CALL_TX				1057
#define ACDB_ID_BT_SCO_NREC_CALL_RX			1058
#define ACDB_ID_BT_SCO_NREC_CALL_TX			1059
#define ACDB_ID_TTY_HEADSET_MONO_CALL_RX		1078
#define ACDB_ID_TTY_HEADSET_MONO_CALL_TX		1079
#define ACDB_ID_DUALMIC_HANDSET_CALL_TX			1099
#define ACDB_ID_HANDSET_FMRADIO_RX			1100
#define ACDB_ID_HEADSET_FMRADIO_RX			1102
#define ACDB_ID_HEADSET_FMRADIO_TX			1103
#define ACDB_ID_SPEAKER_FMRADIO_RX			1104
#define ACDB_ID_SPEAKER_VOICE_DIALER_TX			1110
#define ACDB_ID_HEADSET_VOICE_DIALER_TX			1111
#define ACDB_ID_BT_SCO_VOICE_DIALER_TX			1112
#define ACDB_ID_BT_SCO_NREC_VOICE_DIALER_TX		1113
#define ACDB_ID_SPEAKER_VOICE_SEARCH_TX			1115
#define ACDB_ID_HEADSET_VOICE_SEARCH_TX			1116
#define ACDB_ID_HEADSET_FMRADIO_ONLY_RX			1117
#define ACDB_ID_SPEAKER_FMRADIO_ONLY_RX			1118

#ifdef CONFIG_MACH_ANCORA_TMO
#define ACDB_ID_HANDSET_CALL_HAC_RX			1121
#define ACDB_ID_HANDSET_CALL_HAC_TX			1122
#endif

/* VOIP call path */
#define ACDB_ID_HANDSET_VOIP_RX				1123
#define ACDB_ID_HANDSET_VOIP_TX				1124
#define ACDB_ID_SPEAKER_VOIP_RX				1125
#define ACDB_ID_SPEAKER_VOIP_TX				1126
#define ACDB_ID_HEADSET_VOIP_RX				1127
#define ACDB_ID_HEADSET_VOIP_TX				1128
#define ACDB_ID_BT_SCO_VOIP_RX				1129
#define ACDB_ID_BT_SCO_VOIP_TX				1130

#ifdef CONFIG_MACH_ANCORA_TMO
#define ACDB_ID_HANDSET_GAN_RX				1133
#define ACDB_ID_HANDSET_GAN_TX				1134
#define ACDB_ID_SPEAKER_GAN_RX				1135
#define ACDB_ID_SPEAKER_GAN_TX				1136
#define ACDB_ID_HEADSET_GAN_RX				1137
#define ACDB_ID_HEADSET_GAN_TX				1138
#define ACDB_ID_BT_SCO_GAN_RX				1139
#define ACDB_ID_BT_SCO_GAN_TX				1140
#endif

#if defined(CONFIG_MACH_ANCORA_TMO) || defined(CONFIG_MACH_APACHE)
#define ACDB_ID_HANDSET_GTALK_RX			1143
#define ACDB_ID_HANDSET_GTALK_TX			1144
#define ACDB_ID_SPEAKER_GTALK_RX			1145
#define ACDB_ID_SPEAKER_GTALK_TX			1146
#define ACDB_ID_HEADSET_GTALK_RX			1147
#define ACDB_ID_HEADSET_GTALK_TX			1148
#define ACDB_ID_BT_SCO_GTALK_RX				1149
#define ACDB_ID_BT_SCO_GTALK_TX				1150
#endif

#if defined (CONFIG_MACH_ANCORA_TMO) || defined (CONFIG_MACH_APACHE)
#define ACDB_ID_SPEAKER_LOOPBACK_RX			1153
#define ACDB_ID_SPEAKER_LOOPBACK_TX			1154
#endif
#if defined (CONFIG_MACH_APACHE)
#define ACDB_ID_HANDSET_AUDIENCE_CALL_RX				1155
#define ACDB_ID_HANDSET_AUDIENCE_CALL_TX				1156
#endif

#endif /* _MACH_QDSP5_V2_AUDIO_ACDB_DEF_H */
