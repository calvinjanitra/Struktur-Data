#include <iostream>
using namespace std;

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
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

int queue_frontnext(Queue *queue){
    QueueNode *temp = queue->_front;

    if(!queue_isEmpty(queue)){
        temp = temp->next;
        return temp->data;
    }
    return 0;
}
int queue_size(Queue *queue){
    return queue->_size;
}

void switchValue(Queue *queue){
    QueueNode *temp1 = queue->_front;
    QueueNode *temp2 = queue->_front->next;

    if(!queue_isEmpty(queue)){
        while(temp1 != NULL){
            if(temp1->data < temp2->data){
                temp1->data = temp2->data;
                queue->_front = temp1;
            }
        }
    }
}
void print_queue(Queue *queue){
    QueueNode *temp = queue->_front;

    if(!queue_isEmpty(queue)){
        while(temp != NULL){
            cout<<temp->data;
            cout<<" ";
            temp = temp->next;
        }
    }
}

int main(int argc, char const *argv[]){
    Queue myQueue;
    queue_init(&myQueue);

    int n,q,a,m;

    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a;
        queue_push(&myQueue,a);
    }
    for(int i=0;i<q;i++){
        int a;
        cin>>a;

        for(int i=0;i<a;i++){

        }
    }
    int value1,value2;

    value1 = queue_front(&myQueue);
    value2 = queue_frontnext(&myQueue);
    cout<<value1<<" "<<value2<<endl;
    // print_queue(&myQueue);
    return 0;
}
