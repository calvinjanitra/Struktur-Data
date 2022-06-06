#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
using namespace std;

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int totalStack(Stack *stack){
    StackNode *temp = stack->_top;
    int total = 0;
    while(temp != NULL){
        total += temp->data;
        temp = temp->next;
    }
    return total;
}
void printStack (Stack *stack){
    StackNode *temp = stack->_top;

    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
int main(int argc, char const *argv[])
{
    Stack myStack;
    stack_init(&myStack);
    int n, query, capacity;
    char str[5];

    scanf("%d", &n);
    int a[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d %d", &query, &capacity);

    int total = 0;
    int i = 0;
    
    while(query--){
        scanf("%s", str);
        if(strcmp(str,"add")==0){
            stack_push(&myStack, a[i]);
            total += a[i];
            i++;
        }
        else if(strcmp(str,"eat")==0){
            total -= stack_top(&myStack);
            stack_pop(&myStack);
        }
    }
    if(total > capacity || myStack._size == 0){
        printf("-1\n");
    }
    else{
        printf("%d %d\n", total, myStack._size);
    }

    // if(stack_total(&myStack)>capacity){
    //     cout<<"-1";
    // }else{
    //     cout<<stack_total(&myStack);
    // }   
    return 0;
}
