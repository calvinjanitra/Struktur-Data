#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

// Node structure
struct StackNode {
    int data;
    StackNode *next;
};

/* Structure of Stack using List */
struct Stack
{
    StackNode *_top;
    unsigned _size;

    void init() 
    {
        _size = 0;
        _top = nullptr;
    }

    bool isEmpty() {
        return (_top == nullptr);
    }

    void push(int value)
    {
        StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
        if (newNode) {
            _size++;
            newNode->data = value;

            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _top;
            _top = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            StackNode *temp = _top;
            _top = _top->next;
            free(temp);
            _size--;
        }
    }

    int top()
    {
        if (!isEmpty())
            return _top->data;
        exit(-1);
    }
};

int main(int argc, char const *argv[])
{

    Stack s;
    s.init();
    int n, t;
    string cmd;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int i = 0, sum = 0;
    cin>>n>>t;
    for(int j = 0; j < n; j++){
        cin>>cmd;
        if(cmd == "beri"){
            s.push(arr[i]);
            sum += arr[i];
            i++;
        }
        else if(cmd == "nakam"){
            sum -= s.top();
            s.pop();
        }
    }
    if(sum > t || s._size == 0) printf("YAH KOSONG DONG\n");
    else printf("%d %d\n", sum, s._size);
}