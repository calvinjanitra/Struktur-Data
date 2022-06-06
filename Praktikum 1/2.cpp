#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct pqueueNode_t {
	char name[100];
	int priority;
    int umurku;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, char *nama, int prioritas, int umur)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = (PQueueNode*) malloc (sizeof(PQueueNode));
    strcpy(newNode->name, nama);
    newNode->priority = prioritas;
    newNode->umurku = umur;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if(prioritas > pqueue->_top->priority) 
	{
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else if(prioritas == pqueue->_top->priority && umur >= pqueue->_top->umurku)
    {
    	newNode->next = pqueue->_top;
        pqueue->_top = newNode;
	}
    else {
        while(temp->next != NULL && temp->next->priority >= prioritas)
        {
        	if(prioritas == temp->next->priority && umur >= temp->next->umurku)
        		break;
			temp = temp->next;
		}
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

char *pqueue_topName(PriorityQueue *pqueue)
{
	if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->name;
    else return 0;
}

int pqueue_topPriority(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->priority;
    else return 0;
}

int pqueue_topUmur(PriorityQueue *pqueue)
{
	if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->umurku;
    else return 0;
}

int main(int argc, char const *argv[])
{
    PriorityQueue high,medium,low,another;
    pqueue_init(&high);
    pqueue_init(&medium);
    pqueue_init(&low);
    pqueue_init(&another);

    int a,b,c,n;
    char name[50];
    int prioritas,umur;
    int countA = 0, countB = 0, countC = 0, countD = 0;
    int capacity;

    scanf("%d %d %d %d",&a,&b,&c,&n);
    capacity = (a*2) + (b*3) + (4*c);

    while(n--){
        scanf("%s %d %d", name, &prioritas, &umur);

        if(prioritas>=8){
            if(countA < a*2){
                pqueue_push(&high,name,prioritas,umur);
                countA++;
                capacity--;
            }else{
                pqueue_push(&another,name,prioritas,umur);
                countD++;
            }
        }else if(prioritas>=5){
            if(countB < b*3){
                pqueue_push(&medium,name,prioritas,umur);
                countB++;
                capacity--;
            }else{
                pqueue_push(&another,name,prioritas,umur);
                countD++;
            }
        }else if(prioritas<5){
            if(capacity>0){
                pqueue_push(&low,name,prioritas,umur);
                countC++;
                capacity--;
            }else{
                pqueue_push(&another,name,prioritas,umur);
                countD++;
            }
        }
    }
    printf("Treated by Senior Doctor: %d\n",countA);
    if(!pqueue_isEmpty(&high)){
        while(!pqueue_isEmpty(&high)){
            printf("%s %d %d", pqueue_topName(&high), pqueue_topPriority(&high), pqueue_topUmur(&high));
			printf("\n");
			pqueue_pop(&high);
        }
    }
    printf("\n");

    printf("Treated by Resident: %d\n",countB);
    if(!pqueue_isEmpty(&medium)){
        while(!pqueue_isEmpty(&medium)){
            printf("%s %d %d", pqueue_topName(&medium), pqueue_topPriority(&medium), pqueue_topUmur(&medium));
			printf("\n");
			pqueue_pop(&medium);
        }
    }
    printf("\n");

    printf("Treated by Intern: %d\n",countC);
    if(!pqueue_isEmpty(&low)){
        while(!pqueue_isEmpty(&low)){
            printf("%s %d %d", pqueue_topName(&low), pqueue_topPriority(&low), pqueue_topUmur(&low));
			printf("\n");
			pqueue_pop(&low);
        }
    }
    printf("\n");

    printf("Sent to Another Hospital: %d\n",countD);
    if(!pqueue_isEmpty(&another)){
        while(!pqueue_isEmpty(&another)){
            printf("%s %d %d", pqueue_topName(&another), pqueue_topPriority(&another), pqueue_topUmur(&another));
			printf("\n");
			pqueue_pop(&another);
        }
    }  
    return 0;
}
