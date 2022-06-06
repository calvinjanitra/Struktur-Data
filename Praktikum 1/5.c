#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    int id;
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

void stack_push(Stack *stack, int value1, int value2) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->id = value1;
        newNode->data = value2;

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

void printStack (Stack *stack){
    StackNode *temp = stack->_top;

    while(temp != NULL){
        printf("%d %d\n",temp->id,temp->data);
        temp = temp->next;
    }
}
int totalOrderA(Stack *stack){
    StackNode *temp = stack->_top;

    int total = 0;
    while(temp != NULL){
        total += temp->data;
        temp = temp->next;
    }
    return total;
}

typedef struct queueNode_t {
    int id;
    int data;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

/* Function definition below */

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value1, int value2)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->id = value1;
        newNode->data = value2;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

void printQueue(Queue *queue){
    QueueNode *temp = queue->_front;

    while(temp != NULL){
        printf("%d %d\n",temp->id,temp->data);
        temp = temp->next;
    }
}

int totalOrderB(Queue *queue){
    QueueNode *temp = queue->_front;

    int total = 0;
    while(temp != NULL){
        total += temp->data;
        temp = temp->next;
    }
    return total;
}

int main(int argc, char const *argv[])
{
    Stack stackA;
    Queue queueB;
    stack_init(&stackA);
    queue_init(&queueB);


    int isTokoA = 0; // START DARI TOKO B

    while(1){
        char cmd[100];
        scanf("%s",cmd);
        if(strcmp(cmd,"STEAL")==0){
            if(isTokoA == 1){ // TOKO A
                if(stack_isEmpty(&stackA)){
                    printf("TOKO A KOSONG\n");
                }else{
                    stack_pop(&stackA);
                }
            }else if(isTokoA == 0){ // TOKO B
                if(queue_isEmpty(&queueB)){
                    printf("TOKO B KOSONG\n");
                }else{
                    queue_pop(&queueB);
                }
            }
        }else if(strcmp(cmd,"TRADE")==0){
            if(isTokoA == 1){
                isTokoA = 0;
            }else if(isTokoA == 0){
                isTokoA = 1;
            }
        }else if(strcmp(cmd,"ORDER")==0){
            if(isTokoA == 1){
                int id;
                int order;
                scanf("%d %d",&id,&order);

                stack_push(&stackA,id,order);
            }else{
                int id;
                int order;
                scanf("%d %d",&id,&order);

                queue_push(&queueB,id,order);
            }
        }else if(strcmp(cmd,"CLOSED")==0){
            break;
        }
    }

    printf("TOKO A : \n");
    printStack(&stackA);
    if(stack_isEmpty(&stackA)){
        printf("TOKO A SEPI :(\n");
    }
    printf("TOKO A UNTUNG : %d\n",totalOrderA(&stackA));

    printf("TOKO B : \n");
    printQueue(&queueB);
    if(queue_isEmpty(&queueB)){
        printf("TOKO B SEPI :(\n");
    }
    printf("TOKO B UNTUNG : %d\n",totalOrderB(&queueB));
    return 0;
}


