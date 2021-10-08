#include <stdlib.h>
#include <stdio.h>
struct Node {

    int data;
    int height;
    struct Node* left;
    struct Node* right;

};


struct Node* root = NULL;


int height(struct Node* node) {

    int hl = (node != NULL) && (node->left != NULL) ? node->left->height : 0;
    int hr = (node != NULL) && (node->right != NULL) ? node->right->height : 0;

    return 1 + (hl > hr ? hl : hr);
}


int balno(struct Node* node) {

   int hl = (node != NULL) && (node->left != NULL) ? node->left->height : 0;
    int hr = (node != NULL) && (node->right != NULL) ? node->right->height : 0;

    return hl - hr;
}


int size(struct Node* node) {

    if (node == NULL)
        return 0;

    int ls = size(node->left);
    int rs = size(node->right);

    return 1 + ls + rs;
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


struct Node* LLrot(struct Node* node) {
    struct Node* lc = node->left;
    struct Node* lr = lc->right;

    lc->right = node;
    node->left = lr;

    node->height = height(node);
    lc->height = height(lc);

    if (root == node)
        root = lc;

    return lc;
}


struct Node* LRrot(struct Node* node) {

    struct Node* lc = node->left;
    struct Node* lcrc = lc->right;

    node->left = lcrc->right;
    lc->right = lcrc->left;

    lcrc->left = lc;
    lcrc->right = node;

    lc->height = height(lc);
    node->height = height(node);
    lcrc->height = height(lcrc);

    if (root == node)
        root = lcrc;

    return lcrc;
}


struct Node* RLrot(struct Node* node) {

    struct Node* rc = node->right;
    struct Node* rl = rc->left;

    node->right = rl->left;
    rc->left = rl->right;

    rl->left = node;
    rl->right = rc;

    rc->height = height(rc);
    node->height = height(node);
    rl->height = height(rl);

    if (root == node)
        root = rl;

    return rl;
}


struct Node* RRrot(struct Node* node) {

    struct Node* rc = node->right;
    struct Node* rl = rc->left;

    rc->left = node;
    node->right = rl;

    node->height = height(node);
    rc->height = height(rc);

    if (root == node)
        root = rc;

    return rc;
}



struct Node* newn(int data) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}


struct Node* add(struct Node* node, int data) {

    
    if (node == NULL) {
        return newn(data);
    }

    if (data > node->data) {
        node->right = add(node->right, data);

    } else if (data < node->data) {
        node->left = add(node->left, data);
    }

    node->height = height(node);

    if (balno(node) == 2 && balno(node->left) == 1) {
        return LLrot(node);
    }

    if (balno(node) == 2 && balno(node->left) == -1) {
        return LRrot(node);
    }

    if (balno(node) == -2 && balno(node->right) == 1) {
        return RLrot(node);
    }

    if (balno(node) == -2 && balno(node->right) == -1) {
        return RRrot(node);
    }

    return node;
}


struct Node* delete(struct Node* node, int data) {
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

    
    node->height = height(node);

    if (balno(node) == 2 && balno(node->left) == 1) {
        return LLrot(node);
    }

    if (balno(node) == 2 && balno(node->left) == -1) {
        return LRrot(node);
    }

    if (balno(node) == -2 && balno(node->right) == 1) {
        return RLrot(node);
    }

    if (balno(node) == -2 && balno(node->right) == -1) {
        return RRrot(node);
    }

    return node;
}


int main(int argc, char const *argv[]) {
    /* code */

    printf("\n**********Solution-3b: Height Balanced Binary Search Tree**********\n");


    while (1){
        int ch, num, n;
        
        printf("\n-1) Quit.\n1) Add an element.\n2) Delete an element.\n3) Find an element.\n4) size of tree.\n5) Display.\n6) Inorder.\n\nEnter function number you want: ");
        printf("\nType your choice from(-1, 1, 2, 3, 4, 5, 6): ");
        scanf("%d%*c", &ch);

        if(ch == -1){
            printf("\nQuitting the program...\n");
            return 0;   

        } else if (ch == 1) {
            printf("\nType value of element you want to add: ");
            scanf("%d", &num);
            root = add(root, num);

        } else if (ch == 2) {
            printf("\nType value of element you want to delete: ");
            scanf("%d", &num);
            root = delete(root, num);

        } else if (ch == 3) {
            printf("\nType value of element you want to find: ");
            scanf("%d", &num);
            if(find(root, num)){
                printf("Element exist\n");
            } else {
                printf("Element not exist\n");
            }

        } else if (ch == 4) {
            printf("\nsize of the BST: %d\n", size(root));

        } else if (ch == 5) {
           display(root);

            printf("\n");
        }  else if (ch == 6) {
           inorder(root);
           printf("\n");

        } else {
            printf("\nInvalid Choice\n");
        }

    }

    return 0;
}

