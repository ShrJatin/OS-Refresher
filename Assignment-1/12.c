#include <stdio.h>
#include <string.h>


void strrev(char *ptr, int i, int j) {
   char c;

   if (i >= j)
      return;

   char temp = *(ptr+i);
   *(ptr + i) = *(ptr + j);
   *(ptr + j)   = temp;
   i++;
   j--;

   strrev(ptr, i, j);
}



int store(char dec[], char *store) {

	dec[strlen(dec)-1] = '\0';

	for(int i = 0; i < 32; i++) {
		*(store + i ) = 48;
	}

	*(store + 32 ) = '\0';

	char st[strlen(dec)];
	for(int i = 0; i < strlen(dec); i++) {
		st[i] = 48;
	}

	st[strlen(dec)] = '\0';

	int k = 0;
	while(strcmp(st, dec)) {

		int p_rem = 0;
		for(int i = 0; i < strlen(dec); i++) {
			int temp = (dec[i] - 48 + p_rem*10);
			p_rem = temp % 256;
			dec[i] = temp / 256 + 48;

		}


		*(store + k) = p_rem;
		k++;
	}
	
	return k;

}


int adder(char a[], int la, char b[], int lb, char *c){
		
	int i = 0;
	int j = 0;
	int k = 0;

	int carry = 0;
	while( i < la && j < lb){
		int n1 = a[i];
		int n2 = b[j];

		if(n1 < 0) n1+=256;
		if(n2 < 0) n2+=256;

		
		// %D
		// printf("n1: %d, n2: %d, carry: %d\n",n1, n2, carry);
		int n3 = n1 + n2 + carry;

		carry = n3 < 256 ? 0: 1;
		*(c+k) = n3 < 256? n3: n3 - 256;

		i++;
		j++;
		k++;
				
	}

	while( i < la){
		int n1 = a[i];

		if(n1 < 0) n1+=256;
	
		int n3 = n1 + carry;

		carry = n3 < 256 ? 0: 1;
		*(c+k) = n3 < 256? n3: n3 - 256;

		i++;
		k++;
	}

	while( j < lb){
		int n2 = b[i];

		if(n2 < 0) n2+=256;
	
		int n3 = n2 + carry;

		carry = n3 < 256 ? 0: 1;
		*(c+k) = n3 < 256? n3: n3 - 256;

		j++;
		k++;
	} 


	if(carry > 0 && k > 32){
		printf("Overflow Detected.\n");
		k = -1;
	}

	return k;

}

unsigned long long int power(unsigned long long int a, unsigned long long int b){
	if(b == 1){
		return a;
	}

	unsigned long long int x = power(a,b/2);

	if(b%2 == 0) return x*x;
	else return a*x*x;
}

unsigned long long int  decimal(char num[], int k){

	unsigned long long int  x = num[0];

	for(int i = 1; i < k; i++){

		unsigned long long int n = num[i] < 0? 256 + num[i]: num[i];
		x = x + n*power(256, i);
	}
	
	return x;
}


int main() {

	/* code */

	char num1[79];
	printf("Type the first number: ");
	fgets(num1, 79, stdin);

	char num2[79];
	printf("Type the second number: ");
	fgets(num2, 79, stdin);

	char a[33];
	char b[33];
	char c[33];

	int la = store(num1, a);
	int lb = store(num2, b);


	int k = adder(a, la, b, lb, c);
	c[k] = '\0';


	if(k == -1) return 0;

	printf("sum: %llu\n", decimal(c, k));
	
	return 0;
}
