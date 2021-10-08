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

    printf("\n[Tail<-- ");
    while(temp != NULL) {
      printf("%d ",temp->data);
      temp = temp->next;
    }
    printf("-->Front]\n");

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


struct node* delfirst(){
    
    struct node *temp = head;

    if(head == NULL || size == 0){
        printf("\nQueue is Empty\n");
        return NULL;

    } else if( size == 1){
        head = NULL;
        tail = NULL;

    } else {
        head = head->next;
        head->prev = NULL;
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

   printf("\n**********Solution-2cq: Queue**********\n");

   
    while (1){
        int ch, data;

        printf("\n-1) Quit.\n1) Enqueue.\n2) Dequeue.\n3) size.\n4) isempty.\n5) Print.\n\nEnter function number you want: ");
        printf("\nType your choice from(-1, 1, 2, 3, 4, 5): ");
        scanf("%d%*c", &ch);

        if(ch == -1){
            printf("\nQuiting the program...\n\n");
            return 0;   

        } else if (ch == 1) {

            printf("\nType value to Enqueue: ");
            scanf("%d%*c", &data);

            addlast(data);
            printf("Enqueued value: %d\n.", data);

        } else if (ch == 2) {
            struct node *temp = delfirst();

            if(temp == NULL){
                printf("\n");
            } else {
                printf("\nDequeued element: %d\n", temp->data);   
            }
            
        
        } else if (ch == 3) {
            printf("\nsize of the Queue: %d\n", length());

        } else if (ch == 4) {
            if(isempty()) {
                printf("\nEmpty Queue\n");
            } else {
                printf("\nNot Empty Queue\n");
            }
        } else if (ch == 5) {
            print();

        } else {
            printf("\nInvalid Choice\n");
        }

    }
  
    return 0;
}