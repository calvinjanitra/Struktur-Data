
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct stackNode_t {
    long long data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, long long value) 
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

long long stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

void print_max(Stack *stack, long long a[], long long n, long long k)
{
    long long max_upto[n];
    long long total = 0;

    stack_push(stack,0);

    for (int i = 1; i < n; i++) {
        while (!stack_isEmpty(stack) && a[stack_top(stack)] < a[i]) {
            max_upto[stack_top(stack)] = i-1;
            stack_pop(stack);
        }
        stack_push(stack,i);
    }
    while (!stack_isEmpty(stack)) {
        max_upto[stack_top(stack)] = n-1;
        stack_pop(stack);
    }
    long long j = 0;
    for (int i = 0; i <= n - k; i++) {

        while (j < i || max_upto[j] < i + k - 1)
            j++;
        total += a[j];
    }
    printf("%lld\n", total);
}

long long a[1000000];

// Driver code
int main()
{
    Stack myStack;
    stack_init(&myStack);
    long long n;
    scanf("%lld", &n);
    long long k;
    scanf("%lld", &k);


    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }

    print_max(&myStack,a, n, k);

    return 0;
}