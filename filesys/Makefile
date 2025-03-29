CFLAGS = +cpm -Wall --c-code-in-asm -mz80 --list

all: ff.o diskio.o bios.o

ff.o:	ff.c
	zcc $(CFLAGS) -c ff.c

diskio.o: diskio.c
	zcc $(CFLAGS) -c diskio.c 

bios.o: bios.c
	zcc $(CFLAGS) -c bios.c

fstest: fstest.c ff.c
	zcc $(CFLAGS) -create-app fstest.c ff.o diskio.o
	
clean:
	rm *.o
