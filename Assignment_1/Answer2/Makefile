#Makefile for Answer-2
default: main.o fileA.o fileB.o fileC.o 
	gcc -no-pie main.o fileA.o fileB.o fileC.o -o main
	./main


# pause the compile process step for main.c
main.o: main.s
	gcc -c main.s > main.o

main.s: main.i
	gcc -S main.i > main.s

main.i:
	gcc -E main.c > main.i


# pause the compile process step for fileA.c
fileA.o: fileA.s
	gcc -c fileA.s > fileA.o

fileA.s: fileA.i
	gcc -S fileA.i > fileA.s

fileA.i:
	gcc -E fileA.c > fileA.i


# pause the compile process step for fileB.c
fileB.o:fileB.asm
	nasm -f elf64 fileB.asm -o fileB.o


# pause the compile process step for fileC.c
fileC.o: fileC.s
	gcc -c fileC.s > fileC.o

fileC.s: fileC.i
	gcc -S fileC.i > fileC.s

fileC.i:
	gcc -E fileC.c > fileC.i


#cleaning the dierectory
.PHONY : clean
clean :
	\rm -fr main.s main.i main.o main \
	fileA.s fileA.i fileA.o \
	fileB.o \
	fileC.s fileC.i fileC.o 
	