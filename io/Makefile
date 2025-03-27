CFLAGS = +cpm -Wall --c-code-in-asm -mz80 --list

all: console.o consoletest

console.o: console.c
	zcc $(CFLAGS) -c console.c

consoletest: consoletest.c console.c
	zcc $(CFLAGS) -create-app consoletest.c console.o
	
clean:
	rm *.o
