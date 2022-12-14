/*
 * Copyright (C) 2018 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */
#include <linux/kernel.h>
#include "cam_cal_list.h"
#include "eeprom_i2c_common_driver.h"
#include "eeprom_i2c_custom_driver.h"
#include "kd_imgsensor.h"

#define IMX586_MAX_EEPROM_SIZE 0x24D0
#define OV8856_MAX_EEPROM_SIZE 0x8000
#define S5K4H7_MAX_EEPROM_SIZE 0x8000
#define MAX_EEPROM_SIZE_16K 0x4000

struct stCAM_CAL_LIST_STRUCT g_camCalList[] = {
#ifdef OPLUS_FEATURE_CAMERA_COMMON
	{OV64B_SENSOR_ID_20730, 0xA0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{IMX471_SENSOR_ID2_20730, 0xA8, Common_read_region},
	{OV8856_SENSOR_ID2_20730, 0xA2, Common_read_region, MAX_EEPROM_SIZE_16K},
	{GC02M1_SENSOR_ID_20730,0xA4,Common_read_region},
#else
	/*Below is commom sensor */
	{IMX519_SENSOR_ID, 0xA0, Common_read_region},
	{S5K2T7SP_SENSOR_ID, 0xA4, Common_read_region},
	{S5K2LQSX_SENSOR_ID, 0xA0, Common_read_region},
	{S5KHM2SP_SENSOR_ID, 0xA0, Common_read_region},
	{IMX386_SENSOR_ID, 0xA0, Common_read_region},
	{S5K2L7_SENSOR_ID, 0xA0, Common_read_region},
	{IMX398_SENSOR_ID, 0xA0, Common_read_region},
	{IMX350_SENSOR_ID, 0xA0, Common_read_region},
	{IMX386_MONO_SENSOR_ID, 0xA0, Common_read_region},
	{IMX586_SENSOR_ID, 0xA0, Common_read_region, IMX586_MAX_EEPROM_SIZE},
	{IMX499_SENSOR_ID, 0xA0, Common_read_region},
	{OV8856_SENSOR_ID, 0x6C, Common_read_region, OV8856_MAX_EEPROM_SIZE},
	{S5K4H7_SENSOR_ID, 0x20, Common_read_region, S5K4H7_MAX_EEPROM_SIZE},
#endif
	/*  ADD before this line */
	{0, 0, 0}       /*end of list */
};

unsigned int cam_cal_get_sensor_list(
	struct stCAM_CAL_LIST_STRUCT **ppCamcalList)
{
	if (ppCamcalList == NULL)
		return 1;

	*ppCamcalList = &g_camCalList[0];
	return 0;
}


