#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {

    char name[100];
    int rollno;
    int year;
    char prog[100];

    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
int size = 0;


void print(){
    
    struct node *temp = head;

    printf("\n[.<-->");
    while(temp != NULL) {
      printf("(%s,%d,%d,%s)<-->",temp->name, temp->rollno, temp->year, temp->prog);
      temp = temp->next;
    }
    printf(".]\n");

}


void addfirst(char name[], int rollno, int year, char prog[]){

    struct node *temp = (struct node*) malloc(sizeof(struct node));

    strcpy(temp->name, name);
    temp->rollno = rollno;
    temp->year = year;
    strcpy(temp->prog, prog);
    temp->next = NULL;
    temp->prev = NULL;

    size++;

    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    } 

    temp->next = head;
    head->prev = temp;
    head = temp;
    return;
}


void addlast(char name[], int rollno, int year, char prog[]){

    struct node* temp = (struct node*) malloc(sizeof(struct node));    

    strcpy(temp->name, name);
    temp->rollno = rollno;
    temp->year = year;
    strcpy(temp->prog, prog);
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
        printf("\nLinked List is Empty\n");
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


struct node* dellast(){
    
    struct node *temp = tail;

    if(head == NULL || size == 0){
        printf("\nLinked List is Empty\n");
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
   
   printf("\n**********Solution-2b: Doubly Linked-List**********\n");


    while (1){
        int ch, rollno, year;
        char name[100], prog[100];
        printf("\n-1) Quit.\n1) Addfirst.\n2) Addlast.\n3) Deletefirst.\n4) Deletelast.\n5) size.\n6) isempty.\n7) Print.\n\nEnter function number you want: ");
        printf("\nType your choice from(-1, 1, 2, 3, 4, 5, 6, 7): ");
        scanf("%d%*c", &ch);

        if(ch == -1){
            printf("\nQuitting the program...\n\n");
            return 0;   

        } else if (ch == 1 || ch == 2) {
            printf("\nType your name: ");
            fgets(name, 100, stdin);
            printf("%s\n", name);

            printf("\nType your rollno: ");
            scanf("%d%*c", &rollno);
            printf("%d\n", rollno);

            printf("\nType your year of joining: ");
            scanf("%d%*c", &year);
            printf("%d\n", year);

            printf("\nType your enrolled program: ");
            fgets(prog, 100, stdin);
            printf("%s\n", prog);

            if(ch == 1){
                addfirst(name, rollno, year, prog);

            } else if(ch ==2){
                addlast(name, rollno, year, prog);

            }

        } else if (ch == 3) {
            struct node *temp = delfirst();
            if(temp == NULL){
                printf("\n");
            } else {
                printf("\nDeleted element: (%s, %d, %d, %s)\n", temp->name, temp->rollno, temp->year, temp->prog);   
            }

        } else if (ch == 4) {
            struct node *temp = dellast();
            if(temp == NULL){
                printf("\n");
            } else {
                printf("\nDeleted element: (%s, %d, %d, %s)\n", temp->name, temp->rollno, temp->year, temp->prog);   
            }

        } else if (ch == 5) {
            printf("\nsize of the linked list: %d\n", length());

        } else if (ch == 6) {
            if(isempty()) {
                printf("\nEmpty Linked List\n");
            } else {
                printf("\nNot Empty Linked List\n");
            }
        } else if (ch == 7) {
            print();

        } else {
            printf("\nInvalid Choice\n");
        }

    }
  
    return 0;
}