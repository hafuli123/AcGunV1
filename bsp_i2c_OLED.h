#ifndef __I2C_OLED_H__
#define	__I2C_OLED_H__

#include "stm32f4xx_hal.h"

#define OLED_DEV_ADDR			   0x78

void OLED_Init(void);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data);
void OLED_CLS(void);
void OLED_ON(void);
void OLED_OFF(void);
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize);
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N,unsigned char * words) ;
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);
void OLED_Clear(void);

void OLED_ShowCNX32(unsigned char x, unsigned char y, unsigned char N,unsigned char * words)  ;
void OLED_ShowWordX32(unsigned char x, unsigned char y, unsigned char N,unsigned char * words, uint8_t w_size, uint8_t h_size)  ;
void OLED_IntShowNumX32( uint8_t x , uint8_t y ,uint32_t value );
#endif /* __I2C_OLED_H__ */

