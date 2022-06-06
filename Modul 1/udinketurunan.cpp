#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
using namespace std;


typedef struct pqueueNode_t {
    char nama[101];
    int asci;
    struct pqueueNode_t *next;
} PQueueNode;

typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

typedef struct snode_t {
    char nama[101];
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, char *value1, int value2)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    strcpy (newNode->nama, value1);    
    newNode->asci = value2;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value2 < pqueue->_top->asci) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->asci < value2)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// bool slist_isEmpty(SinglyList *list) {
//     return (list->_head == NULL);
// }

// void slist_pushBack(SinglyList *list, char *value1)
// {
//     SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
//     if (newNode) {
//         list->_size++;
//         strcpy (newNode->nama, value1); 
//         newNode->next = NULL;
        
//         if (slist_isEmpty(list)) 
//             list->_head = newNode;
//         else {
//             SListNode *temp = list->_head;
//             while (temp->next != NULL) 
//                 temp = temp->next;
//             temp->next = newNode;
//         }
//     }
// }

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->asci;
    else return 0;
}

int convertToASCII(string letter)
{
    int total = 0;
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        total += int(x);
    }
    return total;
    // cout <<total<< endl;
}

void printQueue(PriorityQueue* pqueue){
    PQueueNode *temp = pqueue->_top;

    while(temp != NULL){
        if(!pqueue_isEmpty(pqueue)){
            cout<<"Keturunan : "<<temp->asci<<" | "<<"Nama : "<<temp->nama<<endl;
            temp = temp->next;
        }
    }
    
}
int main()
{
    PriorityQueue queue;
    pqueue_init(&queue);

    char nama[101];
    // cin >> nama;
    
    while(scanf("%s", nama) != EOF){
        int temp = 0;
        temp = convertToASCII(nama);
        pqueue_push(&queue,nama,temp);
    }
    printQueue(&queue);
    // convertToASCII(nama);
    return 0;
}
