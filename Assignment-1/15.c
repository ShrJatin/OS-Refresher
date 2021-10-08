#include<stdio.h>
#include<stdlib.h>

void binary_search(unsigned long arr[], unsigned long n, unsigned long x){

    int i = 0;
    int j = n-1;

    while(i <= j){

        int mid = j + (i - j)/2;

        if(arr[mid] == x) {
            printf("%lu is present in the array\n", x);
            return;


        } else if(arr[mid] < x) {
            i = mid+1;

        } else {
            j = mid-1;

        }
    }

    printf("%lu is not present in the array\n", x);
    return;

}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void main(){

    unsigned long n, x;
    printf("Enter the no of total elements: ");
    scanf("%lu", &n);
    
    unsigned long arr[n], ans;

    printf("Enter the elements for array.\n");
    for(int i=0;i<n;i++){

        unsigned long el;
        scanf("%lu", &el);
        printf("%lu\n", el);

        if(el > 4294967295){
            printf("Overflow occured.\nInput is out of range");
            return;
        }

        arr[i] = el;
    }

    printf("Enter the element want to search for: ");
    scanf("%lu", &x);

    if(x > 4294967295){
        printf("Overflow occured.\nInput is out of range\n");
        return;
    }

    qsort(arr, n, sizeof(int), cmpfunc);
 
    binary_search(arr, n, x);
    return;
}