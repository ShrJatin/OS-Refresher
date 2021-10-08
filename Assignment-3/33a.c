#include <stdlib.h>
#include <stdio.h>
struct Node {

    int data;
    struct Node* left;
    struct Node* right;

};

struct Node* root = NULL;


struct Node* construct(int arr[], int lo, int hi) {

    if (lo > hi)
        return NULL;

    int mid = (lo + hi) / 2;

    struct Node* lp = construct(arr, lo, mid - 1);
    struct Node* rp = construct(arr, mid + 1, hi);

    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = arr[mid];
    temp->left = lp;
    temp->right = rp;

    return temp;
}


void display(struct Node* node) {
    if (node != NULL){
       

        if(node->left == NULL){
            printf(".");
        } else {
            printf("%d", node->left->data);
        }
        
        printf(" <= %d => ", node->data);

        if(node->right == NULL){
            printf(".");
        } else {
            printf("%d", node->right->data);
        }

        printf("\n");

        display(node->left);
        display(node->right);
        }
    }

void inorder(struct Node *node) {
    if(node!=NULL) {
        inorder(node->left); 
        printf(" %d ", node->data);
        inorder(node->right);
    }
}


int size(struct Node* node) {

    if (node == NULL)
        return 0;

    int ls = size(node->left);
    int rs = size(node->right);

    return 1 + ls + rs;
}


int sum(struct Node* node) {

    if (node == NULL)
        return 0;

    int ls = sum(node->left);
    int rs = sum(node->right);

    return node->data + ls + rs;
}


int max(struct Node* node) {

    if (node  == NULL) return -1;
    if (node->right == NULL)
        return node->data;

    int rm = max(node->right);
    return rm;
}


int min(struct Node* node) {
    if (node  == NULL) return -1;
    if (node->left == NULL)
        return node->data;

    int rm = min(node->left);
    return rm;
}

_Bool find(struct Node* node, int data) {
    if (node == NULL) {
        return 0;
    }

    return node->data == data || find(node->left, data) || find(node->right, data);
}


struct Node* newn(int data) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct Node* add(struct Node* node, int data){

    if (node == NULL) {
        return newn(data);
    }

    if (data > node->data) {
        node->right = add(node->right, data);

    } else if (data < node->data) {
        node->left = add(node->left, data);
    }

    return node;
}

struct Node* delete(struct Node* node, int data){
    if(node == NULL) return NULL;

    if(data == node->data){
        if(node->left == NULL && node->right == NULL){
            free(node);
            return NULL;

        } else if(node->left == NULL && node->right != NULL){
            return node->right;

        } else if(node->left != NULL && node->right == NULL){
            return node->left;

        } else{
            int el = min(node->left);
            node->data = el;
            node->left = delete(node->left, el);
            return node;
        }
        
    } else if(data > node->data){
        node->right  = delete(node->right,data);

    } else {
        node->left = delete(node->left,data);
         
    }
    return node;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char const *argv[]) {

    /* code */
    printf("\n**********Solution-3a: Binary Search Tree**********\n");

    while (1){
        int ch, num, n;
        
        printf("\n-1) Quit.\n1) construct Bst by giving all elements in a run.\n2) Add an element.\n3) Delete an element.\n4) Find an element.\n5) size of tree.\n6) Display.\n7) Inorder.\n\nEnter function number you want: ");
        printf("\nType your choice from(-1, 1, 2, 3, 4, 5, 6, 7): ");
        scanf("%d%*c", &ch);

        if(ch == -1){
            printf("\nQuitting the program...\n");
            return 0;   

        } else if (ch == 1 ) {

            printf("\nType numbers of elements: ");
            scanf("%d", &n);

            int arr[n];
            printf("\nType all elements: ");

            for(int i = 0; i < n; i++){
                scanf("%d", &arr[i]);    
            }
            qsort(arr, n, sizeof(int), cmpfunc);
            root = construct(arr, 0, n-1);
            

        } else if (ch == 2) {
            printf("\nType value of element you want to add: ");
            scanf("%d", &num);
            root = add(root, num);

        } else if (ch == 3) {
            printf("\nType value of element you want to delete: ");
            scanf("%d", &num);
            root = delete(root, num);

        } else if (ch == 4) {
            printf("\nType value of element you want to find: ");
            scanf("%d", &num);
            if(find(root, num)){
                printf("Element exist\n");
            } else {
                printf("Element not exist\n");
            }

        } else if (ch == 5) {
            printf("\nsize of the BST: %d\n", size(root));

        } else if (ch == 6) {
           display(root);
            printf("\n");
        }  else if (ch == 7) {
           inorder(root);
           printf("\n");

        } else {
            printf("\nInvalid Choice\n");
        }

    }

    return 0;
}



