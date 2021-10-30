#include <stdio.h>

void B(unsigned long long int);

void A() {

	unsigned long long int num;
	printf("Type the Number: ");
	scanf("%llu",&num);

	printf("Printing in  A: %llu\n", num);

	printf("You are in A before Call of B\n\n");
	B(num);

}



