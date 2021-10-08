#include<stdio.h>

void print(int x, char s[]){
	printf("\nResult after %s: %d\n", s, x);
}

void add(int a, int b){
	print(a+b, "addition");
}

void mul(int a, int b){
	print(a*b, "multiplication");
}

void sub(int a, int b){
	print(a-b, "subtraction");
}

void div(int a, int b){

	if(b == 0){
		printf("\nInvlid operand value of divisor.\n");
		return;	
	}
j
	printf("\nResult after division: %f\n\n", (float)a/b);
	return;
}

int util(int a, int b){
	if(b == 1){
		return a;
	}

	int x = util(a,b/2);

	if(b%2 == 0) return x*x;
	else return a*x*x;
}

void expo(int a, int b){
	print(util(a,b), "exponentiation");
}

void (*type[5])(int, int) = {add, sub, mul, div, expo};

void main() {
	
	/* code */

   printf("\n**********Solution-3: Array of function pointers**********\n");


	int a,b;
	printf("\nType a: ");
	scanf("%d", &a);
	printf("Type b: ");
	scanf("%d", &b);

	int ch;

    printf("\n1) Addition.\n2) Subtraction.\n3) Multiplication.\n4) Division.\n5) Exponential.\n\nEnter function number you want: ");
    printf("\nType your choice from(1, 2, 3, 4, 5): "); /* because we have only 3 functions */
    scanf("%d",&ch);


    if(ch > 5 || ch < 1){
    	printf("\nInvalid Choice\n\n");
    	return;
    }

	type[ch-1](a,b);

	return;	
}

