#ifndef __OLED_H__
#define __OLED_H__

#include "main.h"

/* OLED I2C 从机地址（7 位，0.96 寸常见 0x3C，左移一位 = 8位写地址 0x78） */
#define OLED_ADDR 0x3C

/* 控制字节：0x00 = 命令，0x40 = 数据 */
#define OLED_CMD  0x00
#define OLED_DATA 0x40

/* 屏幕尺寸 */
#define OLED_WIDTH  128
#define OLED_HEIGHT 64


static uint8_t OLED_GRAM[8][128];

/* 对外接口 */
void OLED_Init(void);                          /* 初始化 OLED（发初始化序列 + 清屏） */
void OLED_Clear(void);                         /* 清屏 */
void OLED_ShowChar(uint8_t x, uint8_t y, char ch);   /* 在 (x,y) 显示一个字符 */
void OLED_ShowString(uint8_t x, uint8_t y, char *str); /* 在 (x,y) 显示字符串 */
void I2C_Scan(void);                           /* I2C 地址扫描（调试用） */

void OLED_DrawPoint(uint8_t x, uint8_t y); //发送一个点，到显存缓冲区（如果想要显示需要调用OLED_Refresh，将缓冲区上传）
void OLED_Refresh(void);  //将缓冲区内容发送到OLED上

#endif
