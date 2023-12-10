/**
 ******************************************************************************
 * @file           : Startup.c
 * @author         : Seifeldin Ahmed Ismail
 ******************************************************************************
*/
#include "Platform_types.h"

int main(void);
void Reset_Handler();
void NMI_Handler() __attribute__((weak,alias("Default_Handler")));
void H_fault_Handler() __attribute__((weak,alias("Default_Handler")));

//booking 1024Byte located by .bss through un intialized array of int 256 Element(256*4=1024) 
static unsigned long Stack_top[256] ;

void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) = 
{
	(void (*)())    ((unsigned long)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler
};


extern uint32 _E_text ;
extern uint32 _S_DATA ;
extern uint32 _E_DATA ;
extern uint32 _S_bss ;
extern uint32 _E_bss ;



void Reset_Handler()
{
  // copy data section from flash to sram 
   uint32 DATA_size = (uint8 *)&_E_DATA - (uint8 *)&_S_DATA ;
   uint8 * P_src = (uint8 *)&_E_text;
   uint8 * P_des = (uint8 *)&_S_DATA;
   for (int i = 0 ; i< DATA_size ; i++)
   {
  	*((uint8 *)P_des++) = *((uint8 *)P_src++)  ;
   }
   
   // init .bss section in SRAM = 0
   uint32 BSS_size = (uint8 *)&_E_bss - (uint8 *)&_S_bss ;
   P_des = (uint8 *)&_S_bss;
   for (int i = 0 ; i< DATA_size ; i++)
   {
  	*((uint8 *)P_des++) = (uint8)0 ;
   }
   
   //jump main
   main();
}

void Default_Handler()
{
	Reset_Handler();
}

