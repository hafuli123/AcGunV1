#ifndef __GUN_INFO_H__
#define __GUN_INFO_H__

#include "main.h"

typedef struct{
    uint32_t serialnum;
    uint32_t shootnum;
    float press_val;
    uint8_t batt_charge;
    uint8_t gun_type;
    uint8_t shootflg;
    uint32_t uwtick;
#define SHOOTFLAG_NORMAL 0
#define SHOOTFLAG_PRESS 1
#define SHOOTFLAG_SHOOT 2
#define SHOOTFLAG_RELEASE 4
#define SHOOTFLAG_LIGHTOFF 8
}GunInfo_Struct;

extern GunInfo_Struct guninfo_struct;

void guninfo_send(void);

void Guninfo_GetPressVal(void);
void Guninfo_GetSerialNum(void);
void Guninfo_GetShootNum(void);
void Guninfo_GetShoot(void);
void Guninfo_GetTick(void);

#endif
