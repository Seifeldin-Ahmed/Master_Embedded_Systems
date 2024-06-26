/*
 * seifeldin Ahmed Ismail
 * */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

/**********************************
 * Includes
 **********************************
*/
#include "stm32f103x6.h"

/*==================================================*/

/**********************************
 * config structure
 **********************************
*/
typedef struct
{
	uint16_t GPIO_PinNumber   ; /* Specifies the GPIO Pins to be Configured
	                               This Parameter must be set based on a value of @ref GPIO_PIN_define */

	uint8_t GPIO_Mode	      ; /* Specifies the operating mode for the selected pins
     	 	 	 	  	  	  	   This Parameter must be set based on a value of @ref GPIO_MODE_define */

	uint8_t GPIO_Output_Speed ; /* Specifies the speed for the selected pins
	                               This Parameter must be set based on a value of @ref GPIO_SPEED_define */

}GPIO_PinConfig_t;



/**********************************
 * Macros Configuration References
 **********************************
*/

/* @ref GPIO_PINS_define*/
#define GPIO_PIN_0           ((uint16_t)0x0001)  /* Pin 0 selected */
#define GPIO_PIN_1           ((uint16_t)0x0002)  /* Pin 1 selected */
#define GPIO_PIN_2           ((uint16_t)0x0004)  /* Pin 2 selected */
#define GPIO_PIN_3           ((uint16_t)0x0008)  /* Pin 3 selected */
#define GPIO_PIN_4           ((uint16_t)0x0010)  /* Pin 4 selected */
#define GPIO_PIN_5           ((uint16_t)0x0020)  /* Pin 5 selected */
#define GPIO_PIN_6           ((uint16_t)0x0040)  /* Pin 6 selected */
#define GPIO_PIN_7           ((uint16_t)0x0080)  /* Pin 7 selected */
#define GPIO_PIN_8           ((uint16_t)0x0100)  /* Pin 8 selected */
#define GPIO_PIN_9           ((uint16_t)0x0200)  /* Pin 9 selected */
#define GPIO_PIN_10          ((uint16_t)0x0400)  /* Pin 10 selected */
#define GPIO_PIN_11          ((uint16_t)0x0800)  /* Pin 11 selected */
#define GPIO_PIN_12          ((uint16_t)0x1000)  /* Pin 12 selected */
#define GPIO_PIN_13          ((uint16_t)0x2000)  /* Pin 13 selected */
#define GPIO_PIN_14          ((uint16_t)0x4000)  /* Pin 14 selected */
#define GPIO_PIN_15          ((uint16_t)0x8000)  /* Pin 15 selected */
#define GPIO_PIN_ALL         ((uint16_t)0xffff)  /* All pins selected */

#define GPIO_PIN_MASK        0x0000FFFFUL        /* PIN mask for assert test */


/* @ref GPIO_MODE_define */
/* 0 : Analog mode
 * 1 : Floating input(reset)
 * 2 : Input with pull up
 * 3 : Pull-down
 * 4 : General purpose output push-pull
 * 5 : General purpose output Open-drain
 * 6 : Alternative function output push-pull
 * 7 : Alternative function output Open-drain
 * 8 : Alternative function INPUT
 * */
#define GPIO_MODE_Analog       		 0x00000000u /* Analog Mode*/
#define GPIO_MODE_INPUT_FLO    		 0x00000001u /* Floating input Mode*/
#define GPIO_MODE_INPUT_PU	   		 0x00000002u /* Input with pull-up Mode */
#define GPIO_MODE_INPUT_PD     	     0x00000003u /* Input with pull-down Mode */
#define GPIO_MODE_OUTPUT_PP    		 0x00000004u /* General purpose output push-pull Mode */
#define GPIO_MODE_OUTPUT_OD    		 0x00000005u /* General purpose output Open-drain Mode */
#define GPIO_MODE_AF_OUTPUT_PP    	 0x00000006u /* Alternate function output Push-pull Mode*/
#define GPIO_MODE_AF_OUTPUT_OD       0x00000007u /* Alternate function output Open-drain Mode*/
#define GPIO_MODE_AF_INPUT    		 0x00000008u /* Alternate function INPUT Mode*/


/* @ref GPIO_SPEED_define */
/* 1 : Output mode, max speed 10 MHz
 * 2 : Output mode, max speed 2 MHz
 * 3 : Output mode, max speed 50 MHz
 * */
#define GPIO_SPEED_10M     0x00000001u  /* Output mode, max speed 10 MHz */
#define GPIO_SPEED_2M      0x00000002u  /* Output mode, max speed 2 MHz */
#define GPIO_SPEED_50M     0x00000003u  /* Output mode, max speed 50 MHz */


/* @ref GPIO_PIN_state */
#define GPIO_PIN_SET    1
#define GPIO_PIN_RESET  0


/* @ref GPIO_RETURN_lock */
#define GPIO_RETURN_LOCK_Enabled    1
#define GPIO_RETURN_LOCK_ERROR      0

/*
 * ===============================================================================
 * 						APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================================================
 */

void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx);

void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx, uint16_t Value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t PinNumber);

#endif INC_STM32F103C6_GPIO_DRIVER_H_
