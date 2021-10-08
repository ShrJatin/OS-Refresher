objects = cp 12 13 14 15 
cc = gcc


all: $(objects)

cp: cp.c
	$(cc) -o cp cp.c

12: 12.c
	$(cc) -o 12 12.c

13: 13.c
	$(cc) -o 13 13.c

14: 14.c
	$(cc) -o 14 14.c

15: 15.c
	$(cc) -o 15 15.c


.PHONY : clean
clean :
	\rm -fr $(objects)
