/**
  ******************************************************************************
  * @file    Secure/Src/secure_nsc.c
  * @author  MCD Application Team
  * @brief   This file contains the non-secure callable APIs (secure world)
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE BEGIN Non_Secure_CallLib */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "secure_nsc.h"
#include <stdio.h>
#include "secure_port_macros.h"  
#include "CtoCpp_callable.h"

/** @addtogroup STM32L5xx_HAL_Examples
  * @{
  */

/** @addtogroup Demonstrator
  * @{
  */

/* Global variables ----------------------------------------------------------*/
void *pSecureFaultCallback = NULL;   /* Pointer to secure fault callback in Non-secure */
void *pSecureErrorCallback = NULL;   /* Pointer to secure error callback in Non-secure */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Secure registration of non-secure callback.
  * @param  CallbackId  callback identifier
  * @param  func        pointer to non-secure function
  * @retval None
  */
CMSE_NS_ENTRY void SECURE_RegisterCallback(SECURE_CallbackIDTypeDef CallbackId, void *func)
{
  if(func != NULL)
  {
    switch(CallbackId)
    {
      case SECURE_FAULT_CB_ID:           /* SecureFault Interrupt occurred */
        pSecureFaultCallback = func;
        break;
      case GTZC_ERROR_CB_ID:             /* GTZC Interrupt occurred */
        pSecureErrorCallback = func;
        break;
      default:
        /* unknown */
        break;
    }
  }
}

secureportNON_SECURE_CALLABLE void SECURE_LEDS_setGreen(uint8_t brightness){
	//BSP_LED_Init(LED2);
	HAL_ResumeTick();
    struct RGB currentColor = LEDController_getColor();
    uint8_t r = currentColor.r;
    uint8_t g = currentColor.g;
    uint8_t b = currentColor.b;
    LEDController_setColor(r, brightness, b);
    HAL_SuspendTick();
    //BSP_LED_Toggle(LED2);
}

secureportNON_SECURE_CALLABLE void SECURE_LEDS_setRed(uint8_t brightness){
	//BSP_LED_Init(LED2);
	HAL_ResumeTick();
    struct RGB currentColor = LEDController_getColor();
    uint8_t r = currentColor.r;
    uint8_t g = currentColor.g;
    uint8_t b = currentColor.b;
    LEDController_setColor(brightness, g, b);
    HAL_SuspendTick();
    //BSP_LED_Toggle(LED2);
}

secureportNON_SECURE_CALLABLE void SECURE_LEDS_setBlue(uint8_t brightness){
	//BSP_LED_Init(LED2);
	HAL_ResumeTick();
    struct RGB currentColor = LEDController_getColor();
    uint8_t r = currentColor.r;
    uint8_t g = currentColor.g;
    uint8_t b = currentColor.b;
    LEDController_setColor(r, g, brightness);
    HAL_SuspendTick();
    //BSP_LED_Toggle(LED2);
}
/*CMSE_NS_ENTRY*/secureportNON_SECURE_CALLABLE void SECURE_LEDToggle(Led_TypeDef LED)
{
  BSP_LED_Toggle(LED);
}

/* USER CODE END Non_Secure_CallLib */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
