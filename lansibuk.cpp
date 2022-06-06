#include <iostream>
using namespace std;

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_init(SinglyList *list){
    list->_head = NULL;
    list->_size = 0;
}
void slist_pushBack(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
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
void slist_pushFront(SinglyList *list, int value) 
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        
        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

int slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

int slist_getTop(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        return temp->data;
    }
    return 0;
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

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_remove(SinglyList *list, int value)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (temp->data == value) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}
void slist_insertAt(SinglyList *list, int index, int value)
{
    if (slist_isEmpty(list) || index >= list->_size) {
        slist_pushBack(list, value);
        return;    
    }
    else if (index == 0) {
        slist_pushFront(list, value);
        return;
    }
    
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}
void reverse(SinglyList *list)
{
    // Initialize current, previous and
    // next pointers
    SListNode *current = list->_head;
    SListNode *prev = NULL, *next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    list->_head = prev;
}

void printLinkedList(SinglyList *list){
    SListNode *temp;
    temp = list->_head;

    while(temp != NULL){
        cout<<temp->data;
        cout<<" ";
        temp = temp->next;
    }
}

int main(int argc, char const *argv[]){
    SinglyList myList;
    slist_init(&myList);

    int n;
    cin>>n;

    // reverse(&myList);
    // printLinkedList(&myList);
    for(int i=0; i<n; i++){
        string cmd;
        cin>>cmd;

        if(cmd == "KeBelakang"){//pushback
            int value;
            cin>>value;
            slist_pushBack(&myList,value);

        }else if(cmd == "TaruhDepan"){//pushfront
            int value;
            cin>>value;
            slist_pushFront(&myList,value);

        }else if(cmd == "Putar"){//reverse
            reverse(&myList);

        }else if(slist_isEmpty(&myList)){
            cout<<"Yah gabut...";

        }else if(cmd == "Urgent"){//print paling atas dan popfront
            int result;
            result = slist_getTop(&myList);
            cout<<result<<endl;
            slist_popFront(&myList);
            
        }else if(cmd == "GakPenting"){//print paling belakakng dan popback
            int result;
            result = slist_back(&myList);
            cout<<result<<endl;
            slist_popBack(&myList);
        }    
    }
}