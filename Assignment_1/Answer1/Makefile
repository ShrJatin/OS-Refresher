#Makefile for Answer-1
all: student_fork student_pthread


# pause the compile process step for student_fork
student_fork: student_fork.o
	gcc  student_fork.o -o student_fork
	./student_fork

student_fork.o: student_fork.s
	gcc -c student_fork.s > student_fork.o

student_fork.s: student_fork.i
	gcc -S student_fork.i > student_fork.s

student_fork.i:
	gcc -E student_fork.c > student_fork.i


# pause the compile process for step student_pthread
student_pthread: student_pthread.o
	gcc  student_pthread.o -lpthread -o student_pthread
	./student_pthread

student_pthread.o: student_pthread.s
	gcc -c student_pthread.s -lpthread > student_pthread.o

student_pthread.s: student_pthread.i
	gcc -S student_pthread.i -lpthread > student_pthread.s

student_pthread.i:
	gcc -E student_pthread.c -lpthread > student_pthread.i


#cleaning the dierectory
.PHONY : clean
clean :
	\rm -fr student_fork.s student_fork.i student_fork.o student_fork fork_Dumb.txt \
	student_pthread.s student_pthread.i student_pthread.o student_pthread Thread_Dump.txt
	
	