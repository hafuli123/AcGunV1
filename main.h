/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <rtthread.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef struct {
    rt_thread_t keyon_th; //开关机线程
    rt_thread_t nrf_th; //无线模块线程
    rt_thread_t oled_th; //显示器线程
    rt_thread_t soundcard_th; //枪声线程

    struct MOTOR_Struct{
        rt_thread_t motor_th; //振动电机
        uint8_t motor_stat;
#define MOTOR_SHCOK_ON 0
#define MOTOR_SHCOK_OFF 1
    }motor_struct;

    struct MRS_Struct{
        rt_thread_t mrs_th; //磁阻开关开枪线程
#define MRS_GPIO_GET    GPIO_PIN_RESET
#define MRS_GPIO_NORMAL    GPIO_PIN_SET
        uint8_t mrs_stat;
#define MRS_NORMAL  0
#define MRS_LOADED  1 //上膛
#define MRS_SHOOT   2 //开枪完成
#define MRS_END     3 //最后采集
#define MRS_LIGHTOFF 4 //关灯
    }mrs_struct;

    struct PT_Struct{
        rt_thread_t pt_th; //压力传感器执行线程
        //ADC
        float adc_local;
        float press_val;
        float press_val_record; //不会被程序清零的VAL
        float adc_val[10];
        float adc_val_avg;
        uint16_t adc_converted_val;

        //滤波
        int arr[10];
        int max, min;
        int maxnum, minnum;

    }pt_struct;

    struct SELECT_Struct{
        rt_thread_t select_th; //菜单选择线程
        uint8_t sel_stat;
        uint8_t serialnum_bit;
        uint8_t serialnum_val[5];
        int serialnum_sum;
#define SEL_STAT_ELSE 0
#define SEL_STAT_SERIALNUM 1
#define SEL_STAT_LASER 2
    }select_struct;

    //红点激光
    struct REDL_struct{
        rt_thread_t redl_th;
        void(*redl_th_entry)(void*parameter);
        uint8_t redl_stat;
#define REDL_ALWAYS_OFF     0
#define REDL_ALWAYS_ON  1
#define REDL_TRIGGER_ON     2
#define REDL_SHOOT_ON   3
    } redl_struct;

    //OLED
    struct OLED_struct{
        rt_thread_t oled_th;
        void(*oled_th_entry)(void*parameter);
        uint8_t key2_stat;
#define KEY2_STAT_ON    0
#define KEY2_STAT_OFF   1
        struct OLED_screen{
            uint8_t screen;
            uint8_t state;
        }oled_screen;
        //OLED screen
#define OLED_SCREEN_SLEEP   0
#define OLED_SCREEN_MAIN    1
#define OLED_SCREEN_SHOOTNUM    2
#define OLED_SCREEN_SERIALNUM   3
#define OLED_SCREEN_LASER   4
#define OLED_SCREEN_SHOCK   5
#define OLED_SCREEN_VOICE   6
        //OLED situation
#define OLED_STAT_START     0
#define OLED_STAT_DYNAMIC   1

        uint8_t oled_serialnum_ascii[5];
    } oled_struct;

    void(*motor_th_entry)(void*parameter);
    void(*keyon_th_entry)(void*parameter);
    void(*pt_th_entry)(void *parameter);
    void(*nrf_th_entry)(void*parameter);
    void(*oled_th_entry)(void*parameter);
    void(*soundcard_th_entry)(void*parameter);
    void(*tim_th_entry)(void*parameter);
    void(*select_th_entry)(void*parameter);
    void(*mrs_th_entry)(void*parameter);
} Thread_Struct;

extern Thread_Struct thread_struct;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
