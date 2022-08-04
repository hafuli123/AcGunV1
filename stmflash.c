#include "stmflash.h"

/* 要擦除内部FLASH的起始地址 */
#define FLASH_USER_START_ADDR   ADDR_FLASH_SECTOR_5
/* 要擦除内部FLASH的结束地址 */
#define FLASH_USER_END_ADDR     ADDR_FLASH_SECTOR_5  +  GetSectorSize(ADDR_FLASH_SECTOR_5) -1

static FLASH_EraseInitTypeDef EraseInitStruct;
static uint32_t GetSector(uint32_t Address);
static uint32_t GetSectorSize(uint32_t Sector);

uint32_t FirstSector = 0, NbOfSectors = 0;
void FLASH_EEPROM_Write(uint32_t addrpos,uint32_t n)
{
    HAL_FLASH_Unlock();
    uint32_t PageError = 0;

    FirstSector = GetSector(FLASH_USER_START_ADDR);
    NbOfSectors = GetSector(FLASH_USER_END_ADDR) - FirstSector + 1;
    EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;//扇区擦除
    EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;
    EraseInitStruct.Sector = FirstSector;
    EraseInitStruct.NbSectors = NbOfSectors;

    HAL_FLASHEx_Erase(&EraseInitStruct,&PageError);

    uint32_t writeFlashData = n;
    uint32_t addr = ADDR_FLASH_SECTOR_5+addrpos;
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addr, writeFlashData);
    HAL_FLASH_Lock();

}

uint32_t FLASH_EEPROM_Read(uint32_t addrpos)
{
    HAL_FLASH_Unlock();
    uint32_t Page = 0;
    uint32_t addr = ADDR_FLASH_SECTOR_5+addrpos;                  //写入的地址
    Page=*(__IO uint32_t*)addr;
    return Page;
}

/**
  * 函数功能: 根据输入的地址给出它所在的sector
  * 输入参数: Address flash地址
  * 返 回 值: 无
  * 说    明: 无
  */
static uint32_t GetSector(uint32_t Address)
{
  uint32_t sector = 0;

  if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
  {
    sector = FLASH_SECTOR_0;
  }
  else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
  {
    sector = FLASH_SECTOR_1;
  }
  else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
  {
    sector = FLASH_SECTOR_2;
  }
  else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
  {
    sector = FLASH_SECTOR_3;
  }
  else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
  {
    sector = FLASH_SECTOR_4;
  }
  else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
  {
    sector = FLASH_SECTOR_5;
  }


  return sector;
}

/**
  * 函数功能: 根据扇区编号获取扇区大小
  * 输入参数: Sector
  * 返 回 值: 无
  * 说    明: 无
  */
static uint32_t GetSectorSize(uint32_t Sector)
{
  uint32_t sectorsize = 0x00;

  if((Sector == FLASH_SECTOR_0) || (Sector == FLASH_SECTOR_1) || (Sector == FLASH_SECTOR_2) || (Sector == FLASH_SECTOR_3))
  {
    sectorsize = 16 * 1024;
  }
  else if(Sector == FLASH_SECTOR_4)
  {
    sectorsize = 64 * 1024;
  }
  else
  {
    sectorsize = 128 * 1024;
  }
  return sectorsize;
}
