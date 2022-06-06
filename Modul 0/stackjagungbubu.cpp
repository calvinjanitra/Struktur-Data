#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

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

void init(Stack *stack){
    stack->_size = 0;
    stack->_top = NULL;
}

void print_stack(Stack *stack)
{
    StackNode *temp = stack->_top;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int hitung_ganjil(Stack *stack)
{
    int ganjil = 0;

    StackNode *temp = stack->_top;
    while(temp)
    {
        if (temp->data % 2 == 1 ){
            ganjil++;
        }
        temp = temp->next;
    }
    return ganjil;
}

int hitung_genap(Stack *stack)
{
    int genap = 0;

    StackNode *temp = stack->_top;
    
    while(temp)
    {
        if (temp->data % 2 == 0 ){
            genap++;
        }
        temp = temp->next;
    }
    //printf("%d", genap);
    return genap;
}

void print_genap(Stack *stack, int value)
{

    StackNode *temp = stack->_top;
    
    int  arr[value], index = 0;

    if (value == 0)
    {
        printf("Gak ada nih!\n");
    }else{
        printf("NUM =>");
        while (temp)
        {
            if (temp->data % 2 == 0){
                arr[index] = temp->data;
                index++;
                temp = temp->next;
            }else{
                temp = temp->next;
            }
        }

        for (int i = 0; i < value; i++)
        {
            printf("%d", arr[i]);
            if (i < value - 1)
            {
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }  
}

void print_ganjil(Stack *stack, int value)
{

    StackNode *temp = stack->_top;
    
    int  arr[value], index = 0;

    if (value == 0)
    {
        printf("Gak ada nih!\n");
    }else{
        printf("NUM =>");
        while (temp){
            if (temp->data % 2 == 1)
            {
                arr[index] = temp->data;
                index++;
                temp = temp->next;
            }else{
                temp = temp->next;
            }
        }

        for (int i = 0; i < value; i++)
        {
            printf("%d", arr[i]);
            if (i < value - 1)
            {
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }  
}

int main() {
    int n, P, nA, nB;

    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &P, &nA, &nB);

        Stack stackA, stackB, stackA1, stackB1;
        init(&stackA);
        init(&stackB);
        init(&stackA1);
        init(&stackB1);

        int arrA[nA], arrB[nB];
        int jagung = 0, temp = 0;

        //scan nA
        for (int j = 0; j < nA; j++)
        {
            scanf("%d", &arrA[j]);
        }

        //scan nB
        for (int j = 0; j < nB; j++)
        {
            scanf("%d", &arrB[j]);
        }

        //push A
        for (int j = nA - 1; j >= 0; j--)
        {
            stack_push(&stackA, arrA[j]);
            stack_push(&stackA1, arrA[j]);
        }

        //push B
        for (int j = nB - 1; j >= 0; j--)
        {
            stack_push(&stackB, arrB[j]);
            stack_push(&stackB1, arrB[j]);
        }
    
        for (int i = 0; i < nA + nB; i++)
        {
            if (stack_top(&stackA) < stack_top(&stackB))
            {
                if (temp + stack_top(&stackA) <= P)
                {
                    jagung++;
                    temp += stack_top(&stackA);
                    stack_pop(&stackA);
                }else{
                    break;
                }
                
            }else if(stack_top(&stackB) < stack_top(&stackA))
            {
                if (temp + stack_top(&stackB) <= P)
                {
                    jagung++;
                    temp += stack_top(&stackB);
                    stack_pop(&stackB);
                }else{
                    break;
                }

            }else if(stack_top(&stackA) == stack_top(&stackB)){
                if (temp + stack_top(&stackA) <= P)
                {
                    jagung++;
                    temp += stack_top(&stackA);
                    stack_pop(&stackA);
                }else{
                    break;
                }
            }
        }

        if (jagung == 0)
        {
            printf("%d Jahong\n", jagung);
            printf("Keciaaan :<\n");
        }
        else if (jagung % 2 == 0)
        {
            printf("%d Jahong\n", jagung);
            
            //genap ambil dari stack A genap
            print_genap(&stackA1, hitung_genap(&stackA1));
        }
        else if (jagung % 2 == 1)
        {
            printf("%d Jahong\n", jagung);
            
            //ganjil ambil dari stack B ganjil
            print_ganjil(&stackB1, hitung_ganjil(&stackB1));
        }

    }
    return 0;
}