#include<stdio.h>

void bubble(int *arr, int n){

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-i-1; j++){

			if(*(arr+j) > *(arr+j + 1)){

				int temp = *(arr+j+1);
				*(arr+j+1) = *(arr+j);
				*(arr+j) = temp;

			}
		}	
	}
}

void selection(int *arr, int n){
	for(int i = 0; i < n; i++){

		int min = i;
		for(int j = i+1; j < n; j++){

			if(*(arr+min) > *(arr+j)){
				min = j;
			}
		}

		int temp = *(arr+min);  
		*(arr+min) = *(arr+i);
		*(arr +i) = temp;
	}
}

void print(int arr[], int n, char s[]){

	printf("Array %s sorting: ", s);
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);	
	}
	printf("\n");
}

int main() {
	
	/* code */
   printf("\n**********Solution-5: Bubble and Selection Sort**********\n");

	int n;
	printf("\nSize of the array: ");
	scanf("%d", &n);
	
	int  arr[n];
	printf("\nType the elements of the array.\n");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);	
	}

	int ch;
	printf("\nType your choice.\n1) Bubble Sort.\n2) Selection Sort.\nType your choice: ");
	scanf("%d", &ch);


	if(ch == 1){
		printf("\n");
		print(arr, n, "before bubble");
		bubble(arr, n);
		print(arr, n, "after bubble");

	} else if(ch == 2){
		printf("\n");
		print(arr, n, "before selection");
		selection(arr, n);
		print(arr, n, "after selection");

	} else {
		printf("Invlid choice");
	}

	return 0;
}