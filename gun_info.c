#include "gun_info.h"
#include "bsp_nrf24l01.h"

GunInfo_Struct guninfo_struct;

void guninfo_send(void)
{
    tmp_buf[0]='g';tmp_buf[1]='i';tmp_buf[2]='{';
    Guninfo_GetSerialNum();
    Guninfo_GetShootNum();
    Guninfo_GetPressVal();
    Guninfo_GetShoot();
    Guninfo_GetTick();
    tmp_buf[31]='}';
    NRF24L01_TxPacket(tmp_buf);
}

void Guninfo_GetPressVal(void)
{
    uint8_t *pBuf=&tmp_buf[11];
    uint8_t *pSrc=(uint8_t*)&guninfo_struct.press_val;
    for(int i = 0; i < 4; i++) {
        pBuf[i] = pSrc[i];
    }
}

void Guninfo_GetSerialNum(void)
{
    uint8_t *pBuf=&tmp_buf[3];
    uint8_t *pSrc=(uint8_t*)&guninfo_struct.serialnum;
    for(int i = 0; i < 4; i++) {
        pBuf[i] = pSrc[i];
    }
}

void Guninfo_GetShootNum(void)
{
    uint8_t *pBuf=&tmp_buf[7];
    uint8_t *pSrc=(uint8_t*)&guninfo_struct.shootnum;
    for(int i = 0; i < 4; i++) {
        pBuf[i] = pSrc[i];
    }
}

void Guninfo_GetShoot(void)
{
    tmp_buf[17] = (uint8_t)guninfo_struct.shootflg;
}

void Guninfo_GetTick(void)
{
    uint8_t *pBuf=&tmp_buf[18];
    uint8_t *pSrc=(uint8_t*)&guninfo_struct.uwtick;
    for(int i = 0; i < 4; i++) {
        pBuf[i] = pSrc[i];
    }
}
