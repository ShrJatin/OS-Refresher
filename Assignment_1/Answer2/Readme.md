## Assignment 1-Answer 1
### Jatin Kumar Sharma
### Roll no: 2020563
### Cse -231 (OS)

### Please use the Unix command line or WSL with Ubuntu in windows for a better experinence of this Project.
The Zip file 2020563 after extraction gives 6 files which includes 3 C files, a asm file, a Makefile and a Readme file as follows:

### --> Readme

## Execution
### --> Makefile

### --> main.c 
### --> fileA.c
### --> fileB.asm
### --> fileC.c

### 1. Readme:
	This file contains important instructions to be followed to setup and run the files of the assignment.

## Execuion: 
    The compilatioon and Execution of this program is done using a single Makfile in the  directory.
    
### Makefile: 
  1. First install the make if not already installed using the following commands:
    $ sudo apt update
		$ sudo apt install make
		$ sudo apt install gcc
    
  2. Now run `$ make` in linux CLI opened at same directory where the files actually exists
    This will execute the following commands to compile the different files into a single executable `main` file along with the compilation files at each step and will run that executable file on its own.
        gcc -E main.c > main.i
        gcc -S main.i > main.s
        gcc -c main.s > main.o
        gcc -E fileA.c > fileA.i
        gcc -S fileA.i > fileA.s
        gcc -c fileA.s > fileA.o
        nasm -f elf64 fileB.asm -o fileB.o
        gcc -E fileC.c > fileC.i
        gcc -S fileC.i > fileC.s
        gcc -c fileC.s > fileC.o
        gcc -no-pie main.o fileA.o fileB.o fileC.o -o main
        ./main
        
   3. The file will exeute and prodeuce output as follows having dialogue that where the fuction actually executing:
        
        You are in main now.
        Before calling A function

        Type the Number:

        
   4. Now it will demand for input from user against the dialogue <Type the Number:>, Let the provided input as:- 2767959
   5. Just after providing the input the program will interpret that as a 8-byte ASCII string and print individual characters on screen the output can be presented as follows.
  
        Printing in  A: 55879
        You are in A before Call of B

        You are in function B now.
        The number interpreted as 8byte ASCII String:
        --------------------------------------
        W<*
        --------------------------------------
        In B before calling the function C

        In C before exit call
   6. Now to rerun the executable file one can directly execute it either using command `./main` or `make`.

## Brief Explnation: 
            
### 2. main.c:
            The file `main.c` contains a main() function and defintion of the function A() which is present in different file `fileA.c`. main() function calls the function A(). 

### 3. fileA.c:
            The file `fileA.c` contains a A() function and defintion of the function B() which is present in different file `fileB.c` written in Assembly language. A() function on call prints diathat the function A() had been called. This function then takes 64but integer as input and then calls the function B(). 

### 4. fileB.asm:
            This file `fileB.asm` contains contains 3 sections wiz:
            
            1. section .data: It contains some text defined in assembly language that is to be printed to point the different calls and showinterpretation
            2. section. bss: In this section a memory space of 8 bit is assigned with the varriable name as `name`.
            3. secction .text: This conains the function names `C` that is to be called from B and the function B declared as global.
            4. B: when the function B() is called from A, The assembly starts to execute from here.
            
                When a function is called with the argument the argument stores in the register `rdi`, so as the call for B been made the value stored in `rdi` moves to the location represeted by `name` and then it prints some statement representing that call for B have benn done. After which the value stored at location name been printed using syscall. for printing syscall we first move `1` into the register `rdi` and `rax` then moves the location `name` into `rsi` and then syscall, in this way syscall write the value stored at the location name interpreted as 8-byte ASCII string.
            
            5. The printing of argument passed is divided into parts labaled as _interpreter, _print and _printLoop.
            6. _interpreter: prints the as a 8-byte ASCII string as stated above.
            7. _print and _printLoop: These labels are used to print the text.
            8. After printing the text and argument as said the stack been manipulated by changing the base pointer.
                we first move the location of function C() in a unused register r9 here, now we stores that stored location into r9 to the location `rbp+8` so that the return address will be the location of function C().
            9. Now function B() returns and call the function C().
            
### 5. fileC.c:
            C() functionn on call print the statement that the call for C has been made, and calls for exit(0) to exit from C() as said in the problem statement.
            

## Clean directory:
	If you want to clear the directory that means delete all the generated files wg the make file. run the below command.

		$  make clean

