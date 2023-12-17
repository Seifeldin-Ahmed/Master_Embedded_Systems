/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Seifeldin Ahmed Ismail
 * @brief          : Learn-in-depth
 ******************************************************************************
*/

#include "Platform_types.h"
#include "stdlib.h"
/********************* Register Address *******************/
#define RCC_BASE     	 0x40021000
#define GPIOA_BASE  	 0X40010800
#define RCC_APB2ENR      *(vuint32_t *)(RCC_BASE   + 0X18)
#define GPIOA_CRH      	 *(vuint32_t *)(GPIOA_BASE + 0X04)
#define GPIOA_ODR     	 *(vuint32_t *)(GPIOA_BASE + 0X0C)

/************************ Bit Fields **********************/
#define RCC_IOPAEN       (1<<2)
#define GPIOA13        	 (1UL<<13)

typedef union{
	vuint32_t all_fields;
	struct {
		vuint32_t reserved:13 ;
		vuint32_t P_13:1 ;
	}Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR =  (volatile R_ODR_t* )(GPIOA_BASE + 0X0C);
unsigned char data_var[2]= {1,2}; 
unsigned char bss_var[3]= {0};

void* _sbrk(int incr)
{   
	 unsigned char* heap_ptr = NULL ;
	unsigned char * prev_heap_ptr = NULL;
	extern unsigned int _E_bss; // symbol
	extern unsigned int _heap_End; //symbol 
	//first time intialized 
	if (heap_ptr == NULL)
		heap_ptr = (unsigned char *)&_E_bss;
	
	prev_heap_ptr = heap_ptr ;
	
	// protect stack 
	if((heap_ptr + incr) > ((unsigned char*)&_heap_End))
		return (void*)NULL;
	
	//Booking inc size
	heap_ptr  += incr ; 
	
	return (void*)prev_heap_ptr;
}

int main(void)
{	
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH   &= 0xFF0FFFFF; /*clear bits from bit20 --> bit23*/
	GPIOA_CRH   |= 0x00200000;
    while(1)
    {
    	R_ODR->Pin.P_13 = 1; 		//GPIOA_ODR |= GPIOA13;
    	for(int i=0;i<5000;i++);

    	R_ODR->Pin.P_13 = 0;		//GPIOA_ODR &= ~GPIOA13;
    	for(int i=0;i<5000;i++);
    }
	return 0;
}


void NMI_Handler()
{
	
}
