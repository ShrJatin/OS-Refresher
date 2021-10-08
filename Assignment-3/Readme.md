# Assignment 3
## Jatin Kumar Sharma
## Roll no: 2020563
## Cse -231 (OS)

### Please use the Unix command line or WSL with Ubuntu in windows for a better experinence of this Project.

1. This Zip file 2020563 designates for Assignment3 of the refreher module.
2. The Zip file 2020563 after extraction gives 7 files which includes 2 bash files, 3 C-Program files, a Makefile and a Readme file as follows:


### --> Readme
### --> 31.sh 
### --> 32.sh 
### --> Makefile
### --> ./33a 
### --> ./33b
### --> ./34


## 1. Readme:
	This file contains the important instructions to be followed to setup and run the files of the assignment.


## 2. 31.sh:

### Brief Dscription: 
	1. This is a bash file, containing the solution of the question-1 of the given Assignmnt-3.

	2. The file takes Command line arguments of date, on execution file prints the Calender of the entire month of the provided date as asked in the Assignment iff the date is valid else shows the proper error in the given input,  on output window.


###  Setup:- 
	1. Run the command <cal> in the Unix command line and check if the calender appears.

		$ cal

	2. If you are using the <cal> command first time then it may pop a dialogue and install some dependecies for the command to run, we will consider that <cal> command runs in your terminal perfectly and prints the calender of current month else you can refer for inline resources.

### Execution:
	1. Open the Unix or WSL-CLI and move to the directory where this bash file actually resides.

	2. Type below command to enable the permissions for all the bash file. in the []
			$ chmod -R 777 ./

	3. Type the commands in the below format to get the result:-
			 ./31.sh <Date(dd)> <Month(mm)> <Year(yyyy)>


	Example: To print the calender for the entire month of the date: 14 oct, 2021,  command should be as follows:
			$ ./31.sh 14 10 2021

	4. The file will print the calender of entire month of the given date, iff the input is in correct format and valid, otherwise it will show appropriate  error meessages.

####  Example input:

	jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/assmt3/Assignment3$ ./31.sh 14 10 2021
	    October 2021      
	Su Mo Tu We Th Fr Sa  
	                1  2  
	 3  4  5  6  7  8  9  
	10 11 12 13 14 15 16  
	17 18 19 20 21 22 23  
	24 25 26 27 28 29 30  
	31  


## 3. 32.sh:

### Brief Dscription: 
	1. This is a bash file, containing the solution of the question-2 of the given Assignmnt-3.

	2. This file takes two arguments as command-line arguments for the arithmetic operations (add, sub, mul, div and exp). The first argument it takes is the name of the operations, ie. -- ‘add’, ‘sub’, ‘div’, 'mul' and ‘exp’. The subsequent two arguments are two operands. Thus, depending upon the operations requested, you may call the appropriate function (bash subroutine), which should perform the corresponding arithmetic operation, using the supplied arguments. 



###  Setup:- 
	1. Run the command <bc --version> in the Unix command and check the output, if it shows the output as shown beloow.

		$ bc -version

		output:-
		bc 1.07.1
		Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006, 2008, 2012-2017 Free Software Foundation, Inc.
		This is free software with ABSOLUTELY NO WARRANTY.
		For details type `warranty'. 

	2. If the above output showed up in terminal then you can skip this. 

	3. If the above output not showed up, then run <sudo apt update> type the password and then <sudo apt install bc>.

		$ sudo apt update
		$ sudo apt install bc

	4. Now follow from the step and check for output
 
	5. Untnill now if you have follwed, then you are good to go further.  


### Execution:
	1. Open the Unix or WSL-CLI and move to the directory where this bash file actually resides.

	2. Type below command to enable the permissions for this bash file.
			$ chmod -R 777 ./

	3. Type the command in the below format to get the result for various option(Two or more than two operands are possible):-
 			$ ./32.sh <options> <operand1> <operand2> ......"
			 options -- [add, sub, mul, div, exp]


####	Examples: To perform different options 14 and 10:

 			$ ./32.sh add 14 10	12 11
 				47

			$ ./32.sh sub 44 10 4		
				30

 			$ ./32.sh div 14 5 2		
 			 	1.400

 			$ ./32.sh mul 4 5 7		
 				140

 			$ ./32.sh exp 3 2 3 4		
 				289254654976	

##			Note: The range of the input should be valid as if the answer exceeds the range the result  will be wrong(1 in CLI), as the range of the integer that can be stored is limited. :( 


## 7. Makefile:

### Brief Description:
	 1. This is the makefile for c language file of this assignment.
	 2. This file compiles to generate the executable file and execute them itself.

### Setup:
	1. Open the Unix or WSL-CLI and type the command <make --version>  and <gcc --version> one after another to check if make and gcc is installed in your system or not.

		$ gcc --version
		$ make --version

	2. After running these commands, if CLI shows the version of make and gcc then you are good to go and can skip after this step to execution heading.

	3. It may possible that commands of step-1 don't show the version of the make and gcc as you will be using make and gcc first time probably also wsl don't have these preinstalled in it., in that case you need to install them by running below commands one after another.

		$ sudo apt update
		$ sudo apt install make
		$ sudo apt install gcc

	4. After running these commands again follow the step-1 and check if commands shows version or not, if it shows the version then move to execution heading else you reiterate over the process once again, better. 


### Execution:
	1. Open the Unix or WSL-CLI and move to the directory where the make file of these c-program actually resides.

	2. Run make in CLI

	 	$ make

	3. The makefile starts to execute, it first compile all the .c files to generate machine code files one after another then execute them.

	4. Every file will be taking its inputs when it start to execute.


## 33a:
	1. This executable file is for a part of question-3a(Binary Search Tree). 

		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command <./33a>	

				$ ./33a		

####    3. Input: 
		Now the program will demand to select the function number[one value from (-1, 1, 2, 3, 4, 5, 6, 7)] , you want to impliment.

			on input <-1>: program will quit.

			on input <1>: construct Bst by giving all elements in a run.
				Type numbers of elements: 5
				Type all elements: 1 2 3 4 5


			on inout <2>: Add an element.
				Type value of element you want to add: 1 (An Integer)


			on input <3>:  Delete an element.
				Type value of element you want to Delete: 4 (An Integer)				

	
			on input <4>:  To Find an element.
				Type value of element you want to find: 5 (An Integer)


			on input <5>:  Size of the Tree will be printed

			on inout <6>: Display the BST.

			on inout <7>: print the Inorder of BST.


## 33b:
	1. This executable file is for a part of question-3b(AVL Binary Search Tree). 

		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command <./33b>	

				$ ./33b

####    3. Input: 
		Now the program will demand to select the function number[one value from (-1, 1, 2, 3, 4, 5, 6)] , you want to impliment.

			on input <-1>: program will quit.


			on inout <1>: Add an element.
				Type value of element you want to add: 1 (An Integer)


			on input <2>:  Delete an element.
				Type value of element you want to Delete: 4 (An Integer)				

	
			on input <3>:  To Find an element.
				Type value of element you want to find: 5 (An Integer)


			on input <4>:  Size of the Tree will be printed

			on inout <5>: Display the AVL-BST.

			on inout <6>: print the Inorder of AVL-BST.



## 34: 
		1. This executable file is for a part of question-4. 

		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command <./34>	

				$ ./34

		
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

			jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass2$ ./34

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

			jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass2$ ./34

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

