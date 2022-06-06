#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */
long long a[1000000];

typedef struct dnode_t {
    long long data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT Deque */
/* Implementasi didasarkan pada Doubly-Linked List */

typedef struct deque_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} Deque;

/* Definisi Fungsi */

DListNode* __dlist_createNode(long long value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, long long value)
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

void deq_pushBack(Deque *deque, long long value)
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

long long deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

long long deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
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
void printKMax(Deque *deque, long long arr[], long long n, long long k)
{

    // std::deque<long long> Qi(k);
    long long total = 0;
    long long i;
    for (i = 0; i < k; ++i)
    {
        while ((!deq_isEmpty(deque)) && arr[i] >=arr[deq_back(deque)])
            deq_popBack(deque);
        deq_pushBack(deque,i);
    }

    for (; i < n; ++i)
    {
        total += arr[deq_front(deque)];
        // cout << arr[Qi.front()] << " ";

        while ((!deq_isEmpty(deque)) && (deq_front(deque)) <=i - k)
            deq_popFront(deque);

        while ((!deq_isEmpty(deque)) && arr[i] >=arr[deq_back(deque)])
            deq_popBack(deque);
        // Add current element at the rear of Qi
        deq_pushBack(deque,i);
    }

    total += arr[deq_front(deque)];
    printf("%lld\n",total);
}

// Driver code
int main()
{
    Deque myDeque;
    deq_init(&myDeque);
    
    long long n;
    scanf("%lld", &n);
    long long k;
    scanf("%lld", &k);

    // long long a[n];

    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }

    printKMax(&myDeque,a, n, k);

    return 0;
}