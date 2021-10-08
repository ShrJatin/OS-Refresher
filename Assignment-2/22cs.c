#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {

    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
int size = 0;


void print(){
    
    struct node *temp = head;

    printf("\n[Bottom<-- ");
    while(temp != NULL) {
      printf("%d ",temp->data);
      temp = temp->next;
    }
    printf("-->Top]\n");

}


void addlast(int data){

    struct node* temp = (struct node*) malloc(sizeof(struct node));    

    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    size++;

    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    } 

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    return;
}


struct node* dellast(){
    
    struct node *temp = tail;

    if(head == NULL || size == 0){
        printf("\nStack is Empty\n");
        return NULL;

    } else if( size == 1){
        head = NULL;
        tail = NULL;

    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    size--;
    return temp;
}

_Bool isempty(){
    return size == 0;
}


int length(){
    return size;
}


int main(int argc, char const *argv[]) {
    /* code */
   
    printf("\n**********Solution-2cs: Stack**********\n");


    while (1){
        int ch, data;

        printf("\n-1) Quit.\n1) Push.\n2) Pop.\n3) size.\n4) isempty.\n5) Print.\n\nEnter function number you want: ");
        printf("\nType your choice from(-1, 1, 2, 3, 4, 5): ");
        scanf("%d%*c", &ch);

        if(ch == -1){
            printf("\nQuiting the program...\n\n");
            return 0;   

        } else if (ch == 1) {

            printf("\nType value to push into the Stack: ");
            scanf("%d%*c", &data);

            addlast(data);
            printf("Pushed value: %d\n.", data);

        } else if (ch == 2) {
            struct node *temp = dellast();

            if(temp == NULL){
                printf("\n");
            } else {
                printf("Poped element: %d\n", temp->data);   
            }
            
        
        } else if (ch == 3) {
            printf("\nSize of the Stack: %d\n", length());

        } else if (ch == 4) {
            if(isempty()) {
                printf("\nEmpty Stack\n");
            } else {
                printf("\nNot Empty Stack\n");
            }
        } else if (ch == 5) {
            print();

        } else {
            printf("\nInvalid Choice\n");
        }

    }
  
    return 0;
}