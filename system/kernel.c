/* the grand kernel for this program */

/* goals:  translate a terminal, storate, timer interrupt
	into a valid user and schedule that user to start
	running.  
*/

/* terminal interrupts are sent here */

/* storage interrupts are sent here */
/* timer interrupts are sent here */

/* goals:  The mmu and user can generate software interrupts
	that end up here.  These need to be parsed out into 
	system service or error states and performed for the
	user or mmu.

/* mmu signals are sent here */
/* user level signals are sent here */


/* Here we define the kernel users memory pages and user storage
	
*/

