/*
Data: 2020/01/25
Author: Ian
Object: implement stack with linked list.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}Node;

Node* create(void);
int isEmpty(Node*);
Node* push(Node*, int);
Node* pop(Node*);

Node* create(void){ // return null pointer to top.
    return NULL;
}

int isEmpty(Node *top){ // To determine if stack is empty.
    return top==NULL ? 1 : 0;
}

Node* push(Node *top, int item){ // push an item into stack
    Node *temp = (Node *)malloc(sizeof(Node));
    if(temp == NULL){
        printf("memory is unavailable!!\n");
        return;
    }
    temp->data = item;
    printf("push %d into stack.\n", temp->data);
    temp->link = top;

    return temp;
}

Node* pop(Node *top){ // pop an item from stack and release memory
    if(isEmpty(top)){
        printf("Stack is empty!!\n");
        return NULL;
    }
    Node *temp;
    int item = top->data;
    printf("pop %d from stack.\n", item);
    temp = top;
    top = top->link;
    free(temp);
    return top;
}
int main()
{
    Node *top;
    top = create();
    top = push(top, 2);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = push(top, 1);
    top = push(top, 4);
    top = pop(top);
    top = push(top, 3);
    Node *t = top;
    printf("---------------------show stack data from top\n");
    while(t != NULL){
        printf("%d\n", t->data);
        t = t->link;
    }


    return 0;
}
