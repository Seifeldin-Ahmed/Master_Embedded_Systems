/*
 File: Linker script CortexM3
 Name: Seifeldin Ahmed Ismail
*/

MEMORY
{
   flash(RX) : ORIGIN = 0X08000000, LENGTH = 128K
   sram(RWX) : ORIGIN = 0X20000000, LENGTH = 20K
}

SECTIONS
{
  .text : {
            *(.vectors*)
			*(.text*)
			*(.rodata)
			_E_text = . ;
   }> flash
   .data : {
           _S_DATA = . ;
           *(.data)
		   _E_DATA = . ; 
		   . = ALIGN(4) ;
		  
   }> sram AT> flash
   
   .bss : {
          _S_bss = . ;
           *(.bss*)
		  _E_bss = . ; 
		  . = ALIGN(4) ; 
		  . = . + 0x1000;
		  _stack_top = . ;
   }> sram
}