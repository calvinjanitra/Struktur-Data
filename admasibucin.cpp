#include <iostream>
using namespace std;


typedef struct snode_t {
    int barang;
    int harga;
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

void slist_pushBack(SinglyList *list, int value1, int value2)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->barang = value1;
        newNode->harga = value2;
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

int slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->barang;
    }
    return 0;
}

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->barang;
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

void slist_remove(SinglyList *list, int value1)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (temp->barang == value1) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->barang != value1) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}
void printLinkedList(SinglyList *list){
    SListNode *temp;
    temp = list->_head;

    while(temp != NULL){
        cout<<temp->barang;
        cout<<" ";
        cout<<temp->harga<<endl;
        temp = temp->next;
    }
}
void sortList(SinglyList *list){  
    //Node current will point to head  
    SListNode *current = list->_head;
    SListNode *index = NULL;  
    int temp1,temp2;  
    if(list ->_head == NULL) {  
        return;  
    }  
    else {  
        while(current != NULL) {  
            //Node index will point to node next to current  
            index = current->next;  

            while(index != NULL) {  
                //If current node's data is greater than index's node data, swap the data between them  
                if(current->harga < index->harga){ 
                    temp1 = current->harga;
                    temp2 = current->barang;  
                    current->harga = index->harga;
                    current->barang = index->barang;  
                    index->harga = temp1;
                    index->barang = temp2;  
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    }
}
int findValue(SinglyList *list, int value1, int value2, int valueFind){
    SListNode *temp = list->_head;
    SListNode *index = list->_head;
    int count = 1;

    while(temp->barang != valueFind){
        if(temp->next == NULL){
            return 0;
        }
        count++;
        temp = temp->next;
    }
    return count;
}   
int main(int argc, char const *argv[]){
    SinglyList myList;
    slist_init(&myList);

    int n,pick,result;
    int value1,value2;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>value1>>value2;
        slist_pushBack(&myList,value1,value2);
    }
    cin>>pick;

    sortList(&myList);

    result = findValue(&myList,value1,value2,pick);
    
    if(result == 0){
        cout<<"Barangnya gak ada beb";
    }else{
        // cout<<result<<endl;
        cout<<n-result;
    }
    return 0;
}
