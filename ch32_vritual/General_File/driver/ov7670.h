#ifndef _OV7670_H_
#define _OV7670_H_

u8 Sccb_Write_Byte(u8 dat);

u8 Sccb_Read_Byte(void);
u8 Write_Sensor_Reg(u8 regID, u8 regDat);
u8 Readd_Sensor_Reg(u8 regID, u8 *regDat);

u8 Sensor_Init(void);//…„œÒÕ∑–æ∆¨≥ı ºªØ
#endif
