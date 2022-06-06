#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
int q, n;
typedef struct AVLNode_t
{
    int data, dist, rot, cost;
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height=1;
    newNode->rot = 0;
    newNode->cost = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

int _max(int a,int b){
    return (a > b)? a : b;
}

void findRot(AVL *avl, int value){
    AVLNode* root = avl->_root;
    while(root != NULL){
        if(value < root->data){
            root = root->left;
        }
        else if(value > root->data){
            root = root->right;
        }
        else{
            root->rot += 1;
        }
    }
}

void find(AVLNode* temp){
    if(temp){
        temp->rot += 1;
        if(temp->rot >= n && temp->rot % n == 0){
            temp->cost++;
        }
    }
}

AVLNode* _rightRotate(AVL *avl, AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;
    if(newParrent->right != NULL){
        find(newParrent->right);
    }
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;
    pivotNode->rot += 1;
    newParrent->rot += 1;
    if(pivotNode->rot >= n && pivotNode->rot % n == 0){
        pivotNode->cost++;
    }
    if(newParrent->rot >= n && newParrent->rot % n == 0){
        newParrent->cost++;
    }
    //printf("Right: Pivot: %d, Parrent: %d\n", pivotNode->data, newParrent->data);
    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVL *avl, AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    if(newParrent->left != NULL){
        find(newParrent->left);
    }
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;
    pivotNode->rot += 1;
    newParrent->rot += 1;
    if(pivotNode->rot >= n && pivotNode->rot % n == 0){
        pivotNode->cost++;
    }
    if(newParrent->rot >= n && newParrent->rot % n == 0){
        newParrent->cost++;
    }
    //printf("Left: Pivot: %d, Parrent: %d\n", pivotNode->data, newParrent->data);
    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftCaseRotate(AVL *avl, AVLNode* node){
    return _rightRotate(avl, node);
}

AVLNode* _rightCaseRotate(AVL *avl, AVLNode* node){
    return _leftRotate(avl, node);
}

AVLNode* _leftRightCaseRotate(AVL *avl, AVLNode* node){
    node->left=_leftRotate(avl, node->left);
    return _rightRotate(avl, node);
}

AVLNode* _rightLeftCaseRotate(AVL *avl, AVLNode* node){
    node->right=_rightRotate(avl, node->right);
    return _leftRotate(avl, node);
}

int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value) {
    
    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value);
    else if(value > node->data)
        node->right = _insert_AVL(avl,node->right,value);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
    {
        return _leftCaseRotate(avl, node);   
    }
    if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
    {
        return _leftRightCaseRotate(avl, node);   
    }
    if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0) 
    {
        return _rightCaseRotate(avl, node);   
    }
    if(balanceFactor < -1 && _getBalanceFactor(node->right)>0) 
    {
        return _rightLeftCaseRotate(avl, node);   
    }
    
    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode* _remove_AVL(AVL *avl, AVLNode* node,int value){
    if(node==NULL)
        return node;
    if(value > node->data)
        node->right=_remove_AVL(avl, node->right,value);
    else if(value < node->data)
        node->left=_remove_AVL(avl, node->left,value);
    else{
        AVLNode *temp;
        if((node->left==NULL)||(node->right==NULL)){
            temp=NULL;
            if(node->left==NULL) temp=node->right;  
            else if(node->right==NULL) temp=node->left;
            
            if(temp==NULL){
                temp=node;
                node=NULL;
            }
            else
                *node=*temp;   
            
            free(temp);
        }
        else{
            temp = _findMinNode(node->right);
            node->data=temp->data;
            node->right=_remove_AVL(avl, node->right,temp->data);
        }    
    }

    if(node==NULL) return node;
    
    node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

    int balanceFactor= _getBalanceFactor(node);
    
    if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
    {
        
        return _leftCaseRotate(avl, node);   
    }
    if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
    {
        return _leftRightCaseRotate(avl, node);   
    }
    if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0) 
    {
        return _rightCaseRotate(avl, node);   
    }
    if(balanceFactor < -1 && _getBalanceFactor(node->right)>0) 
    {
        return _rightLeftCaseRotate(avl, node);   
    }
    
    return node;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,int value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
    }

}

void avl_remove(AVL *avl,int value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl, avl->_root,value);
        avl->_size--;
    }

}

void preorder(AVLNode *root) {
    if (root) {
        preorder(root->left);
        printf("%d ", root->data);
        preorder(root->right);
    }
}

void findpath(AVL *avl, AVLNode *root, int value)
{
    int c = 0;
    AVLNode *temp = avl->_root;
    while(temp != NULL){
        if(value < temp->data){
            ++c;
            temp = temp->left;
        }
        else if(value > temp->data){
            ++c;
            temp = temp->right;
        }
        else{
            temp->dist = c;
            break;
        }
    }
}

AVLNode* findX(AVL *avl, int x)
{
    AVLNode *temp = avl->_root;
    while(temp != NULL){
        if(x < temp->data){
            temp = temp->left;
        }
        else if(x > temp->data){
            temp = temp->right;
        }
        else{
            return temp;
        }
    }
    return temp;
}

void print(AVL *avl, int x, int n)
{
    AVLNode *root = findX(avl, x);
    printf("Planet %d\n", x);
    printf("Distance: %d\n", root->dist);
    printf("Condition: ");
    int c = n - root->rot;
    if(c < 0) c *= -1;
    if(c > n) c = c % n;
    //printf("rot: %d\n", root->rot);
    if(c == 0 || c == n){
        printf("%d/%d\n", n, n);
    }
    else if(c > 0 && c < n){
        //printf("+");
        printf("%d/%d\n", c, n);
    }
}

void portal(AVLNode *root){
    if(root){
        portal(root->left);
        printf("Planet %d ", root->data);
        printf("Cost: %d\n", root->cost);
        portal(root->right);
    }
}

int main(){
    AVL a;
    avl_init(&a);
    int x, y;
    scanf("%d %d", &q, &n);
    while(q--){
        scanf("%d %d", &x, &y);
        if(x == 1){
            if(!avl_find(&a, y)) {
                printf("Portal build at planet %d\n", y);
                avl_insert(&a, y);
                printf("\n");
            }
        }
        else{
            if(!avl_find(&a, y)) printf("No portal found in planet %d\n\n", y);
            else{
                findpath(&a, a._root, y);
                print(&a, y, n);
                printf("\n");
            }
        }
    }
    printf("Portal Costs:\n");
    portal(a._root);
}