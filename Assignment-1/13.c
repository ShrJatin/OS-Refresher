#include <stdio.h>


void util_swap(int *p, int *q){
	int temp = *q;
	*q = *p;
	*p = temp;
}


void print_arr(int a[], int b[], int n, char s[]){

	printf("\nelements of first array %s swaping: ", s);
	for(int i = 0; i < n; i++) printf("%d ",a[i]);
	printf("\nelements of second array %s swaping: ", s);
	for(int i = 0; i < n; i++) printf("%d ",b[i]);

	printf("\n");
	
}
 

int main() {
	/* code */

	int ch;	

	printf("\n");	

	printf("Type 1 to swap elements of varriable\n");
	printf("Type 2 to swap elements of array\n");

	printf("your choice: ");
	scanf("%d", &ch);
	
	if(ch == 1) {

		int a, b, *p, *q;

		printf("\ntype first no 'a': ");
		scanf("%d", &a);
		printf("type second no 'b': ");
		scanf("%d", &b);

		p = &a;
		q = &b;

		printf("\nelements before swaping\na = %d, b = %d\n", a, b);
		util_swap(p,q);
		printf("elements after swaping\na = %d, b = %d\n", a, b);
		printf("\n");


	} else if(ch == 2){

		int n, *p, *q;

		printf("\n");

		printf("Size of the array: ");
		scanf("%d", &n);

		int a[n];
		int b[n];

		printf("Type elements of first array\n");
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);


		printf("Type elements of second array\n");
		for(int i = 0; i < n; i++) scanf("%d", &b[i]);

		print_arr(a, b, n, "before");

		for(int i = 0; i < n; i++) {
			int *p, *q;
			p = &a[i];
			q = &b[i];
			util_swap(p,q);
		}

		print_arr(a, b, n, "after");


	} else {
		printf("Invalid input");

	}

	return 0;	
}