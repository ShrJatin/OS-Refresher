# Assignment 2
## Jatin Kumar Sharma
## Roll no: 2020563
## Cse -231 (OS)

### Please use the Unix command line or WSL with Ubuntu in windows for a better experinence of this Project.

1. This Zip file 2020563 designates for Assignment2 of the refreher module.
2. The Zip file 2020563 after extraction gives 10 files which includes 8 c-Program files, a Makefile and a Readme file as follows:


### --> Readme
### --> Makefile
### --> 21a
### --> 21b 
### --> 22a 
### --> 22b 
### --> 22cq 
### --> 22cs 
### --> 23
### --> 25


## 1. Readme:
	This file contains the important instructions to be followed to setup and run the files of the assignment.


## 2. Makelife:

### Brief Description:
	 1. This is the makefile for c program files of this assignment.
	 2. This makefile compiles all the c-programming files to generate the executable file for the same.

### Setup:
	1. Open the Unix or WSL-CLI and type the command <make --version>  and <gcc --version> one after another to check if make and gcc compiler is installed in your system or not.

		$ gcc --version
		$ make --version

	2. After running these commands, if CLI shows the version of make and gcc then you are good to go and can skip after this step to execution heading.

	3. It may possible that commands of step-1 don't show the version of the make and gcc in case you will be using make and gcc first time probably also wsl don't have these preinstalled in it., in that case you need to install them by running below commands one after another.

		$ sudo apt update
		$ sudo apt install make
		$ sudo apt install gcc

	4. After running these commands again follow the step-1 and check if commands shows version or not, if it shows the version then move to execution heading else you reiterate over the process once again, better. 


### Execution:
	1. Open the Unix or WSL-CLI and move to the directory where the makefile of this assignment actually resides.

	2. Run make command in CLI

	 	$ make

	3. The makefile starts to execute, and compiles all the .c files to generate machine code files or say executable files in the same directory.

	4. Now the exeecutable files can be run in the terminal as follows.

## 	21a:
		1. This executable file is for a part of question-1. 

		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command <./21a>	
		
			$ ./21a


####	Example Input:

		jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass2$ ./21a

		**********Solution-1a: Genrating given Matrix**********

		Required Matrix: 
		4  7  8  6  4  6  7  
		3  10  2  3  
		8  1  10  4  7  1  
		7  3  7  
		2  9  8  10  3  1  3  
		4  8  




##	21b:
		1. This executable file is for b part of question-1.
		
		2. This file accepts command line input.

		
####    3. Input: 
		To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command ./21b <R1> <R2> <R3> <R4> <R5> <R6>
			Here, 
				R1 -> is an integer and represents number of columns of row1.
				R2 -> is an integer and represents number of columns of row2.
				R3 -> is an integer and represents number of columns of row3.
				R4 -> is an integer and represents number of columns of row4.
				R5 -> is an integer and represents number of columns of row5.
				R6 -> is an integer and represents number of columns of row6.
 
			Suppose we want a matrix having:
				1. 1 columns in 1st row, 2 columns in 2nd row, 3 columns in 3rd row, 4 columns in 4th row, 5 columns in 5th row, 6 columns in 6th row.Run folloing command in CLI.
				
					$ ./21b	 1 2 3 4 5 6	
				2. 4 columns in 1st row, 2 columns in 2nd row, 5 columns in 3rd row, 8 columns in 4th row, 6 columns in 5th row, 9 columns in 6th row.Run folloing command in CLI.
					$ ./21b	 4 2 5 8 6 9

####	Example Input for wromng command line input:

			jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass2$ ./21b

			**********Solution-1b: Genrating Matrix with varriable nummber of columns**********

			Please give command in the below format.
			Usage: ./21b <R1> <R2> <R3> <R4> <R5> <R6>
			 Ri are integers that provides the no of columns in ith row.

####	Example Input for correct type of command line input:

			jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass2$ ./21b 1 2 3 4 5 6

			**********Solution-1b: Genrating Matrix with varriable nummber of columns**********

			Required Matrix: 
			4  
			7  8  
			6  4  6  
			7  3  10  2  
			3  8  1  10  4  
			7  1  7  3  7  2  



##	22a: 
		1. This executable file is for a part of question-2a(LInkedList). 

		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command <./22a>	

				$ ./22a		

####    3. Input: 
		Now the program will demand to select the function number[one value from (-1, 1, 2, 3, 4, 5, 6)] , you want to impliment.

			on -1 input: program will quit.

			on input <1>: program will add the student data in linked list and it will demands for
					Type your name: Jatin (A string)
					Type your rollno: 2020563 (An Integer)
					Type your year of joining: 2020 (An Integer)
					Type your enrolled program: CSAI (A string)

					:- Similarly other elements can be added by opting the option.

			on inout <2>: 
					program will add the student data in linked list and it will demands for
					Type your name: Jatin (A string)
					Type your rollno: 2020563 (An Integer)
					Type your year of joining: 2020 (An Integer)
					Type your enrolled program: CSAI (A string)

					:- Similarly other elements can be added by opting the option.


			on input <3>:  the last elemnt of the linkkedlist will get deleted.
	
			on input <4>:  the first elemnt of the linkkedlist will get deleted.

			on input <5>:  Size of the Linked List will be printed

			on inout <6>: check if linked list is empty and prints the appropriate msg.

			on inout <7>: print the linkedlist.


##	22b: 
		1. This executable file is for a part of question-2a(Doubly-LInkedList). 

		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command <./22b>	

				$ ./22b		

####    3. Input: 
		Now the program will demand to select the function number[one value from (-1, 1, 2, 3, 4, 5, 6, 7)] , you want to impliment.

			on -1 input: program will quit.

			on input <1>: program will add the student data in doubly linked list and it will demands for
					Type your name: Jatin (A string)
					Type your rollno: 2020563 (An Integer)
					Type your year of joining: 2020 (An Integer)
					Type your enrolled program: CSAI (A string)

					:- Similarly other elements can be added by opting the option.


			on inout <2>: 
					program will add the student data in doubly linked list and it will demands for
					Type your name: Jatin (A string)
					Type your rollno: 2020563 (An Integer)
					Type your year of joining: 2020 (An Integer)
					Type your enrolled program: CSAI (A string)

					:- Similarly other elements can be added by opting the option.


			on input <3>:  the last elemnt of the doubly linked list will get deleted.
	
			on input <4>:  the first elemnt of the doubly linked list will get deleted.

			on input <5>:  Size of the arrays will be printed

			on inout <6>: check if doubly linked list is empty and prints the appropriate msg.

			on inout <7>: print the doubly linkedlist.


##	22cq: 
		1. This executable file is for a part of question-2c Queue. 

		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command <./22cs>	

				$ ./22cq	

####    3. Input: 
		Now the program will demand to select the function number[one value from (-1, 1, 2, 3, 4, 5)] , you want to impliment.

			on input <-1>: program will quit.

			on input <1>: program will enqueue data into the queue and it will demands: 

					Type value to Enqueue into the Queue: 2(An Integer).
					:- Similarly other elements can be enqueued by opting the option.


			on inout <2>: 
					Dequeue and print the element.

			on input <3>:  Size of the Queue will be printed

			on inout <4>: check if queue is empty and prints the appropriate msg.

			on inout <5>: print the queue.

##	22cs: 
		1. This executable file is for a part of question-2c Stack. 

		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command <./22cs>	

				$ ./22cs		

####    3. Input: 
		 	Now the program will demand to select the function number[one value from (-1, 1, 2, 3, 4, 5)] , you want to impliment.

			on input <-1>: program will quit.

			on input <1>: program will Push data into the stack and it will demands: 

					Type value to push into the Stack: 2(An Integer).
					:- Similarly other elements can be pushed by opting the option.


			on inout <2>: 
					Pop out and print the element.

			on input <3>:  Size of the stack will be printed

			on inout <4>: check if stack is empty and prints the appropriate msg.

			on inout <5>: print the stack.

##	23: 
		1. This executable file is for a part of question-3. 

		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command <./23a>	

				$ ./23a		

####    3. Input: 

			The program demands for two inputs as two operands <a> ans <b>.

			Input <a>: 4 (An Integer) 
			Input <b>: 5 (An Integer) 

		 	Now the program will demand to select the function number[one value from (1, 2, 3, 4, 5)], you want to impliment.

			on input <1>: Addition.
			on inout <2>: Subtraction.
			on inout <3>: Multiplication.
			on inout <4>: Division.
			on inout <5>: Exponential.

			Now the result will be printed.

####	Example Input:

			**********Solution-3: Array of function pointers**********

			Type a: 2   
			Type b: 3

			1) Addition.
			2) Subtraction.
			3) Multiplication.
			4) Division.
			5) Exponential.

			Enter function number you want: 
			Type your choice from(1, 2, 3, 4, 5): 1

			Result after addition: 5




##	25: 
		1. This executable file is for a part of question-5. 

		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command <./25a>	

				$ ./25		

		
####    3. Input: 

			The program demands for 

			1. Size of the array: 5 (An Integer)
			2. Type the elements of the array.
				5 3 1 6 4

		 	Now the program will demand to select the function number[one value from (1, 2)], you want to impliment.

			on input <1>: Bubble Sort.
			on inout <2>: Selection Sort.

			Now the result will be printed.


####	Example Input for Selection sort:

			jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass2$ ./25

			**********Solution-5: Bubble and Selection Sort**********

			Size of the array: 
			5

			Type the elements of the array.
			5 3 1 6 4

			Type your choice.
			1) Bubble Sort.
			2) Selection Sort.
			Type your choice: 1

			Array before bubble sorting: 5 3 1 6 4 
			Array after bubble sorting: 1 3 4 5 6 


####	Example Input for Bubble sort:

			jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass2$ ./25

			**********Solution-5: Bubble and Selection Sort**********

			Size of the array: 5

			Type the elements of the array.
			5 3 1 6 4

			Type your choice.
			1) Bubble Sort.
			2) Selection Sort.
			Type your choice: 2

			Array before selection sorting: 5 3 1 6 4 
			Array after selection sorting: 1 3 4 5 6 


## Clean directory:
	If you want to clear the directory that means delete all the generated files wg the make file. run the below command.

		$  make clean

