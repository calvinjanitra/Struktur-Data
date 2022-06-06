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
void printLinkedList(SinglyList *list){
    SListNode *temp;
    temp = list->_head;

    while(temp != NULL){
        cout<<temp->data;
        cout<<" ";
        temp = temp->next;
    }
}
int findMax(SinglyList *list){
    SListNode *temp = list->_head;
    int max = INT_MIN;

    while(temp != NULL){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}
int main(int argc, char const *argv[]){
    SinglyList myList;
    slist_init(&myList);

    int n;
    int weight,result;
    cin>>n;
    if(n==0){
        cout<<"Oiya lupa gapunya kambing, hehe";
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>weight;
        slist_pushBack(&myList,weight);
    }
    result = findMax(&myList);
    cout<<result<<endl;
    return 0;
}
