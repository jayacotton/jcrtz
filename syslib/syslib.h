/* every body uses this header. */

/* io disk and console and printer */

#define IOBUF 1
#define IOCHAR 2

extern void InitSIO();
extern void CO(char );
extern void COBUF(char *);
extern int CIBUF(char *);
extern char CI();

/* the user is responcible for the size of buffer
Make sure you have the correct nr of bytes */

extern void ConsInit();  /* should call this befor trying I/O */
extern int ConsWrite(char *,int);
extern int ConsRead(char *,int);

/* error codes from i/o to errno. */

extern int errno;

#define NOERR 0
#define CONSIOERROR 1	/* I need a valid io select */
#define CONSWERROR  2	/* cant write 0 bytes */ 

