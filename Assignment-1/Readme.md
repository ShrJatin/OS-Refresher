# Assignment 2
## Jatin Kumar Sharma
## Roll no: 2020563
## Cse -231 (OS)

### Please use the Unix command line or WSL with Ubuntu in windows for a better experinence of this Project.

1. This Zip file 2020563 designates for Assignment2 of the refreher module.
2. The Zip file 2020563 after extraction gives 7 files which includes 5 c-Program files, a Makefile and a Readme file as follows:


### --> Readme
### --> Makefile
### --> cp
### --> 12
### --> 13 
### --> 14 
### --> 15


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



## 	cp:
		1. This executable file is for question-1. 
		2. The program works same as the default cp command.
		3. The program takes two arguments first a source file and other is a desstination file as the command line inputs.

####    Input:
		To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command ./cp <src> <dest>
		
			$ ./cp <src> <dest>
			src => address of the file you want to coppy
			dest => address of the file where to copy


####	Example Input:

		if i want to copy this filename Readme.md from 

		jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass2$ ./21a

		for incorrect inputs:

		jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass1$ ./cp
		Please give command in the below format.
		Usage: ./cp <src> <dest>

		correct inputs:
                                                                                                                                                                                                                                                  
		jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass1$ ./cp

		Please give command in the below format.
		Usage: ./cp <src> <dest>



##	12:
		1. This executable file is for question-2. 
		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command ./12
			
			$ ./12


####    Input:
		To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command ./12 
		
			$ ./12
		
		Two integral inputs will be demanded:

		Type the first number: 64532184 (An Integer)
		Type the second number: 3265329 (An Integer)
		

####	Example Input:

		jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass1$ ./12
		Type the first number: 64532184
		Type the second number: 3265329 
		sum: 67797513



##	13
		1. This executable file is of question-3.
		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command ./13
			$ ./13
		
####    3. Input: 
		Now the program will demand to select the function number[one value from (1, 2)] , you want to impliment.


			on input <1>: function to swap varriabl will invoke.
				give first input, then second input.

####		Input Example for var swaap:
				jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass1$ ./13

				Type 1 to swap elements of varriable
				Type 2 to swap elements of array
				your choice: 1

				type first no 'a': 5
				type second no 'b': 6

				elements before swaping
				a = 5, b = 6
				elements after swaping
				a = 6, b = 5



			on inout <2>:  function to swap elements of the array will invoke.

				give size of the array = 5 (An integer)
				Type element of first arraay:
				Type element of second arraay:


####		Input Example for array swap:
				jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass1$ ./13
				Type 1 to swap elements of varriable
				Type 2 to swap elements of array
				your choice: 2

				Size of the array: 5
				Type elements of first array
				54789
				5
				6
				2
				2
				Type elements of second array
				1 
				 6 5 8 6 

				elements of first array before swaping: 54789 5 6 2 2 
				elements of second array before swaping: 1 6 5 8 6 

				elements of first array after swaping: 1 6 5 8 6 
				elements of second array after swaping: 54789 5 6 2 2 
								





##	14: 
		1. This executable file is for a part of question-4. 

		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command <./14>

				$ ./14	

####    3. Input: 
			Enter the string: hello world (An string)

####	Input Example
			jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass1$ ./14
			Enter the string: hello world
			The reversd string is: dlrow olleh



##  15:
		1. This executable file is for a part of question-5. 

		2. To run this file open the UNIX or WSL CLI in the same directory whhere the file is, and run command <./15>

				$ ./15

####    3. Input: 
			Enter the no of total elements: 5(An 8bit integer i.e integer of range from 0 to 4294967295)
			Enter the elements for array.
			10400 4294967290 4294967295 50000 100020

			Enter the element want to search for: 10400 (An 8bit integer i.e integer of range from 0 to 4294967295)


####	Input Example
		jatin@jatin-Lenovo-G50-80:~/Desktop/assmt/ass1$ ./15
		Enter the no of total elements: 5
		Enter the elements for array.
		10400 4294967290 4294967295 50000 100020
		10400
		4294967290
		4294967295
		50000
		100020
		Enter the element want to search for: 10400
		10400 is present in the array


## Clean directory:
	If you want to clear the directory that means delete all the generated files wg the make file. run the below command.

		$  make clean

