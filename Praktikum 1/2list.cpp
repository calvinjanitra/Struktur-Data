
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
/* Struktur Node */

typedef struct snode_t {
    char nama[1001];
    int priority;
    int umur;
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* Function definition below */

void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, char value1[], int value2, int value3)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        strcpy(newNode->nama,value1);   
        newNode->priority = value2;
        newNode->umur = value3;
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->priority;
    }
    return 0;
}

void printList(SinglyList *list) {
    SListNode *temp = list->_head;

    while(temp != NULL) {
        cout<<temp->nama<<" "<<temp->priority<<" "<<temp->umur<<endl;
        temp  = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    // Buat objek SinglyList
    SinglyList myList;

    // PENTING! Jangan lupa diinisialisasi
    slist_init(&myList);
    int a,b,c,n;

    cin>>a>>b>>c>>n;

    while(n--){
        char nama[101];
        int priority;
        int umur;
        cin>>nama>>priority>>umur;
        slist_pushBack(&myList,nama,priority,umur);
    }

    if(slist_front(&myList)>=8){

    }else if(slist_front(&myList))
    printList(&myList);
}