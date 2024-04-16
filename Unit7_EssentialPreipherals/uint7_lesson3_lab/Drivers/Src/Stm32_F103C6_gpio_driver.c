/*
 * Seifeldin Ahmed Ismail
 * */
#include "Stm32_F103C6_gpio_driver.h"


static uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch (PinNumber)
	{
		case GPIO_PIN_0:  return 0;   break;
		case GPIO_PIN_1:  return 4;   break;
		case GPIO_PIN_2:  return 8;   break;
		case GPIO_PIN_3:  return 12;  break;
		case GPIO_PIN_4:  return 16;  break;
		case GPIO_PIN_5:  return 20;  break;
		case GPIO_PIN_6:  return 24;  break;
		case GPIO_PIN_7:  return 28;  break;
		case GPIO_PIN_8:  return 0;   break;
		case GPIO_PIN_9:  return 4;   break;
		case GPIO_PIN_10: return 8;   break;
		case GPIO_PIN_11: return 12;  break;
		case GPIO_PIN_12: return 16;  break;
		case GPIO_PIN_13: return 20;  break;
		case GPIO_PIN_14: return 24;  break;
		case GPIO_PIN_15: return 28;  break;
	}
	 return 0;
}

/**================================================================
* @Fn			 - MCAL_GPIO_Init
* @brief		 - Initializes the GPIOx PINy according to the specified parameters in the PinConfig
* @param[in]	 - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
* @param[in] 	 - PinConfig pointer to a GPIO_PinConfig_t structure that contains
*  				   the configuration information for the specified GPIO PIN
* @retval		 - none
* Note			 - Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
* 				   but LQFP48 Package has only GPIO A,B, PART of C,D exported as external PINS from the MCU
*/
void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx , GPIO_PinConfig_t* PinConfig)
{
	/* Port configuration register low (GPIOx_CRL) Configure PINS from 0 >>> 7
	 * Port configuration register high (GPIOx_CRH) Configure PINS from 8 >>> 15 */
	volatile uint32_t* ConfigRegister = NULL;
	ConfigRegister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH ;

	/* Clear CNF[1:0] MODE[1:0] */
	(*ConfigRegister) &= ~(0xf << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	// if Pin is output, MODE > 0:
	if(PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_OD || PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_PP || GPIO_MODE_AF_OUTPUT_OD || GPIO_MODE_AF_OUTPUT_PP)
	{
		(*ConfigRegister) |= ( (((PinConfig->GPIO_Mode - 4)<< 2 ) | (PinConfig->GPIO_Output_Speed) ) << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
	}
	// if pin is input
	else  // MODE == 00: Input Mode
	{
		if (PinConfig->GPIO_Mode == GPIO_MODE_INPUT_FLO || PinConfig->GPIO_Mode == GPIO_MODE_Analog)
		{
			(*ConfigRegister) |=   ((((PinConfig->GPIO_Mode)<< 2 ) | (0x00) ) << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
		}
		else if (PinConfig->GPIO_Mode == GPIO_MODE_AF_INPUT) // Consider it as input floating
		{
			(*ConfigRegister) |=   ((((GPIO_MODE_INPUT_FLO)<< 2 ) | (0x00) ) << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
		}
		else // PU or PD input
		{
			(*ConfigRegister) |=   ((((GPIO_MODE_INPUT_PU)<< 2 ) | (0x00) ) << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

			if(PinConfig->GPIO_Mode == GPIO_MODE_INPUT_PU)
			{
				GPIOx->ODR |= (PinConfig->GPIO_PinNumber);
			}
			else //PD
			{
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}
}
/**================================================================
* @Fn			 - MCAL_GPIO_DeInit
* @brief		 - reset all the GPIOx registers
* @param[in]	 - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
* @retval		 - none
* Note			 - none
*/
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx)
{

	/*Using Reset Values*/
	/*GPIOx->CRL  = 0x44444444; //Reset value
	GPIOx->CRH  = 0x44444444;
	GPIOx->BRR  = 0x00000000;
	GPIOx->BSRR = 0x00000000;
	GPIOx->LCKR = 0x00000000;
	GPIOx->ODR  = 0x00000000;*/
 // GPIOx->IDR read only

	/* OR using Reset Controller */
	switch ((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
			    		RCC->APB2RSTR |= (1<<2);
			    		RCC->APB2RSTR &= ~(1<<2);
		case (uint32_t)GPIOB:
					    RCC->APB2RSTR |= (1<<3);
			            RCC->APB2RSTR &= ~(1<<3);
		case (uint32_t)GPIOC:
					    RCC->APB2RSTR |= (1<<4);
			            RCC->APB2RSTR &= ~(1<<4);
		case (uint32_t)GPIOD:
					    RCC->APB2RSTR |= (1<<5);
			            RCC->APB2RSTR &= ~(1<<5);
		case (uint32_t)GPIOE:
					    RCC->APB2RSTR |= (1<<6);
			            RCC->APB2RSTR &= ~(1<<6);
	}
}


/**================================================================
* @Fn			 - MCAL_GPIO_ReadPin
* @brief		 - Read Specific PIN
* @param[in]	 - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
* @param[in]	 - PinNumber: Set Pin Number according @ref GPIO_PINS_define
* @retval		 - the input pin value (two values based on @ref GPIO_PIN_state)
* Note			 - none
*/
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t PinNumber)
{
	if ((GPIOx->IDR & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		return GPIO_PIN_SET;
	}
	else
	{
		return GPIO_PIN_RESET;
	}
}


/**================================================================
* @Fn			 - MCAL_GPIO_ReadPort
* @brief		 - Read the input port VALUE
* @param[in]	 - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
* @retval		 - the input port value
* Note			 - none
*/
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx)
{
    return (uint16_t)GPIOx->IDR;
}


/**================================================================
* @Fn			 - MCAL_GPIO_WritePin
* @brief		 - Write Specific PIN
* @param[in]	 - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
* @param[in]	 - PinNumber: Set Pin Number according @ref GPIO_PINS_define
* @param[in]	 - Value: pin value
* @retval		 - none
* Note			 - none
*/
void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t PinNumber, uint8_t Value)
{
	if (Value != (uint8_t)GPIO_PIN_RESET)
	{
		GPIOx->ODR |= (uint32_t)PinNumber;
	   /* Or
	    *
	    * GPIOx->BSRR = (uint32_t) PinNumber
	    * */
	}
	else
	{
		GPIOx->ODR &= ~(uint32_t)PinNumber;
	   /* Or
		*
		* GPIOx->BRR = (uint32_t)PinNumber;
		* */
	}
}

/**================================================================
* @Fn			 - MCAL_GPIO_WritePort
* @brief		 - write on output port
* @param[in]	 - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
* @param[in]	 - Value: port value
* @retval		 - none
* Note			 - none
*/
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx, uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value;
}



/**================================================================
* @Fn			 - MCAL_GPIO_TogglePin
* @brief		 - Toggle Specific PIN
* @param[in]	 - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
* @param[in]	 - PinNumber: Set Pin Number according @ref GPIO_PINS_define
* @retval		 - none
* Note			 - none
*/
void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^= (uint32_t)PinNumber;
}


/**================================================================
* @Fn			 - MCAL_GPIO_LockPin
* @brief		 - The locking mechanism allow the IO Configuration to be frozen
* @param[in]	 - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
* @param[in]	 - PinNumber: Set Pin Number according @ref GPIO_PINS_define
* @retval		 - OK if pin config is locked or ERROR if pin not locked (OK & ERROR are defined @ref GPIO_RETURN_lock
* Note			 - none
*/
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t PinNumber)
{
 // Each lock bit freezes the corresponding 4 bits of control register (CRL, CRH)
 /* LOCK Key writing Sequence:
    write 1
    write 0
    write 1
    Read  0
    Read  1
  */

	volatile uint32_t temp ;
	temp = (1<<16) | PinNumber;
	//write 1
	GPIOx->LCKR = temp;
	//write 0
	GPIOx->LCKR = PinNumber;
	//write 1
	GPIOx->LCKR = temp;
	//Read  0
	temp = GPIOx->LCKR;
	//Read  1
	if((uint32_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_RETURN_LOCK_Enabled;
	}
	else
	{
		return GPIO_RETURN_LOCK_ERROR;
	}

}


