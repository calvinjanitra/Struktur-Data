#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
using namespace std;

typedef struct dnode_t {
    int data;
    struct dnode_t      
        *next,
        *prev;
} DListNode;

typedef struct deque_t {
    DListNode           
        *_head, 
        *_tail;
    unsigned _size;
} Deque;

void init(Deque *deque){
	deque->_head = NULL;
	deque->_tail = NULL;
	deque->_size = 0;
}

DListNode* __dlist_createNode(int value)
{
	DListNode *newNode = (DListNode*) malloc(sizeof(DListNode));
	
	if(!newNode) return NULL;
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	return (DListNode*) newNode;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}
void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

void deq_pushFront(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

int deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

int deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head -> next;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_remove(Deque *deque, int value)
{
    if (!deq_isEmpty(deque) ){
        DListNode *temp, *prev;
        temp = deque->_head;

        if (temp->data == value) {
            deq_popFront(deque);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        deque->_size--;
    }
}

void deq_check(Deque *deque, int a){
	DListNode *temp = deque->_head->next;

	while(!deq_isEmpty(deque) && temp != NULL){
		if(temp->data <= a){
            int b = temp->data;
			deq_remove(deque, b);
		}
		temp = temp->next;
	}
}

void printDequeue(Deque *deque){
    DListNode *temp;
    temp = deque->_head;

    while(temp != NULL){
        cout<<temp->data;
        cout<<" ";
        temp = temp->next;
    }
}

int main(){
	Deque myDeque;
    deq_init(&myDeque);
	int n, k;
	int a ,e, i;

    cin>>n;
    for(int i=0; i<n;i++){
        deq_pushFront(&myDeque,i);
    }
    deq_remove(&myDeque,3);

    printDequeue(&myDeque);

	// while(1){
	// 	cin>>n>>k;
	// 	init(&myDeque);
	// 	if(n == 0 && k == 0) break;
	// 	for(i = 0; i < n; i++){
	// 		cin>>a>>e;
	// 		deq_pushFront(&myDeque, e);
	// 		deq_check(&myDeque, a);
	// 	}
	// 	if(myDeque._size <= k) printf ("Bisa boss\n");
	// 	else printf("Gimana nih boss\n");
	// }
}