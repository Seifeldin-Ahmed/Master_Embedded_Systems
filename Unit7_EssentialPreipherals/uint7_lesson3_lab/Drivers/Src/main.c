
//Learn-in-depth
//Seifeldin Ahmed Ismail
//Mastering_EmbeddedSystem online diploma


#include "Stm32_F103C6_gpio_driver.h"
#include "stm32f103x6.h"



void clock_init()
{
	// INIT CLOCK FOR GPIOA
	RCC_GPIOA_CLK_EN();

	// INIT CLOCK FOR GPIOB
	RCC_GPIOB_CLK_EN();
}
void GPIO_init()
{
	GPIO_PinConfig_t PinCfg;

	//PA1: input floating
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	//PB1: output PUSH PULL
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PB1: output PUSH PULL
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PA13: input floating
	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	//PB13: output PUSH PULL
	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

}

void wait(int x){
	unsigned int i , j;
	for(i=0 ; i < x ; i++)
		for(j=0; j < 255 ; j++);
}
int main(void)
{
	clock_init();
	GPIO_init();

	while(1){
       //PA1 >>> Connected by external PUR
	   if( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0 ) // single press
	   {
		    MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0 );
	   }
       //PA13 >>> Connected by external PDR
	   if( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1 ) // Multi press
	   {
		    MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
	   }
	   wait(1);
	}
}



