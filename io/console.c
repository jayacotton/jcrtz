/*  Provide a dependable console interface to interact with the
system level code.  

All the system stuff will be over in system, this is just the i/o
provider.
*/

#include "../syslib/syslib.h"
#include <stdlib.h>

void ConsInit()
{
	InitSIO();
	errno = NOERR;
}
int ConsWrite(char *Buffer,int Count)
{
	errno = NOERR;
	if(Count == 0){
		errno = CONSWERROR;
	}
	else if(Count == 1){
		CO(*Buffer);
	}
	else if(Count >= 2) {
		COBUF(Buffer);
	}
	return (Count);
}
int ConsRead(char *Buffer,int type)
{
int Count;
	
/* read a byte or a record... */

	errno = NOERR;
	switch(type)
	{
		case IOBUF:
			Count = CIBUF(Buffer);
			break;
		case IOCHAR:
			*Buffer = CI();
			Count = 1; 
			break;
		default:
			errno = CONSIOERROR;
			Count = 0;
	}
	return (Count);
}
/* due to a lack of imagination the console character i/o code is 
here.  In the future, this will require abstraction to allow for
a variety of sio drivers. */

/* since I am building and running on an rc2014 with a KIO chip.  
Interrupt mode 2  I think copy the driver from ROMWbW.  */

#define KIOBASE 0x80
#define SIO0BASE KIOBASE+8
#define CTCBASE KIOBASE + 4
#define SIODATA SIO0BASE
#define SIOSTAT SIO0BASE+1
#define SIORX 1
#define SIOTX 4


char CI()
{
unsigned char Temp;
	while(Temp=inp(SIOSTAT)){	/* read status byte */
		if(Temp & SIORX){	/* check rx available */		
			return(inp(SIODATA));  /* read and return */
		}
	}
	return 0;
}
void CO(char c)
{
unsigned char Temp;
	while(Temp = inp(SIOSTAT)){
		if(Temp & SIOTX){
			outp(SIODATA,c);
			return;
		}
	}
}
/* null terminates a buffer */`
void COBUF(char *Buffer)
{
	while(*Buffer){
		CO(*Buffer++);
	}
}
/* CR or LF terminates a read */
int CIBUF(char *Buffer)
{
unsigned char Temp;
int count;
	count = 0;
/* if you enter a null then we will exit here */
	while(Temp = CI()){
		switch(Temp){
			case 0x0d:
			case 0x0a:
				*Buffer = 0;
				return count;
				break;
			default:
				*Buffer++=Temp;
				count++;
		}
	}
	return count;
}
void InitSIO()
{
}

