#include "../syslib/syslib.h"
#include <stdlib.h>

void main()
{
#asm
	di
#endasm

	COBUF("This is a test of the console output\n\r");
	COBUF("Type characters and see echo\n\r");

	while(1){
		CO(CI());
	}
}
