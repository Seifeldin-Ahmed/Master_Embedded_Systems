/**
 ******************************************************************************
 * @file           : Startup.c
 * @author         : Seifeldin Ahmed Ismail
 ******************************************************************************
*/

#include "Platform_types.h"

#define Stack_Start_SP 0x20001000

int main(void);
void Reset_Handler();
void NMI_Handler() __attribute__((weak,alias("Default_Handler")));
void H_fault_Handler() __attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler() __attribute__((weak,alias("Default_Handler")));
void Bus_Fault() __attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler() __attribute__((weak,alias("Default_Handler")));

extern uint32 _stack_top ;

uint32 vectors[]  __attribute__((section(".vectors"))) = {
	(uint32) &_stack_top,
	(uint32) &Reset_Handler,
	(uint32) &NMI_Handler,
	(uint32) &H_fault_Handler,
	(uint32) &MM_Fault_Handler,
	(uint32) &Bus_Fault,
	(uint32) &Usage_Fault_Handler	
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
