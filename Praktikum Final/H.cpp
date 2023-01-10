#include <bits/stdc++.h>
using namespace std;

 
/* Linked list node */
class Node {
public:
    int data;
    Node* next;
};
 
/* Function to create a
new node with given data */
Node* newNode(int data){
	
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
 
/* Function to insert a node at the
beginning of the Singly Linked List */
void push(Node** head_ref, int new_data){
    /* allocate node */
    Node* new_node = newNode(new_data);
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Adds contents of two linked lists and
return the head node of resultant list */
Node* sumAddition(Node* first, Node* second){
	
    // res is head node of the resultant list
    Node* res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;
 
    // while both lists exist
    while (first != NULL || second != NULL) {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
          // (i) Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        // update carry for next calculation
        carry = (sum >= 10) ? 1 : 0;
        // update sum if it is greater than 10
        sum = sum % 10;
        // Create a new node with sum as data
        temp = newNode(sum);
        // if this is the first node then set it as head of the resultant list
        if (res == NULL)
            res = temp;
        // If this is not the first node then connect it to the rest.
        else
            prev->next = temp;
       
        // Set prev for next insertion
        prev = temp;
 
        // Move first and second pointers to next nodes
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
    // return head of the resultant list
    return res;
}
 
Node* rev(Node* head){
	
    if (head == NULL || head->next == NULL)
        return head;
    Node* rest = rev(head->next);
    head->next->next = head;
    head->next = NULL;
    // fix the head pointer
    return rest;
}
void printList(Node* node){
	
    cout <<"[";
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
    cout << "]";
    
}
 
int main(void){
	
    Node* res = NULL;
    Node* node1 = NULL;
    Node* node2 = NULL;
    
    int m, n;
    int a, b;
    
    cin >> m;
    cin >> n;
    
    for(int i = 0 ; i < m ; ++i){
        cin >> a;
        push(&node1, a);
    }
    
    for(int i = 0 ; i < n ; ++i){
        cin >> b;
        push(&node2, b);
    }
    
    res = sumAddition(node1, node2);
    res = rev(res);
    printList(res);
    return 0;
}