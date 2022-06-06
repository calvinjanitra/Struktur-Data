#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
// #include <iostream>
// using namespace std;

int check = 1;

typedef struct AVLNode_t
{
    int height;
    char arr[1001];
    struct AVLNode_t *left,*right;
} AVLNode;

typedef struct AVL_t
{
    AVLNode *_node;
    unsigned int _size;
} AVL;


void avl_init(AVL *avl)
{
    avl->_node = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl)
{
    return avl->_node == NULL;
}

AVLNode* _avl_createNode(char *name)
{
    AVLNode *newNode = (AVLNode*)malloc(sizeof(AVLNode));
    strcpy(newNode->arr, name);
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *node, char *name)
{
    while (node != NULL) {
        if (strcmp(node->arr, name) > 0)
            node = node->left;
        else if (strcmp(node->arr, name) < 0)
            node = node->right;
        else
            return node;
    }
    return node;
}

int _getHeight(AVLNode* node)
{
    if (node == NULL)
        return 0; 
    return node->height;
}

int _max(int a, int b)
{
    return (a > b) ? a : b;
}

AVLNode* _rightRotate(AVLNode* pivotNode)
{
    AVLNode* newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left), 
                      _getHeight(pivotNode->right)) + 1;
    newParrent->height = _max(_getHeight(newParrent->left), 
                       _getHeight(newParrent->right)) + 1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode)
{
    AVLNode* newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left), 
                      _getHeight(pivotNode->right)) + 1;
    newParrent->height = _max(_getHeight(newParrent->left), 
                       _getHeight(newParrent->right)) + 1;
    
    return newParrent;
}

AVLNode* _leftCaseRotate(AVLNode* node)
{
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node)
{
    return _leftRotate(node);
}

AVLNode* _leftRightCaseRotate(AVLNode* node)
{
    node->left = _leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node)
{
    node->right = _rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode* node)
{
    if (node == NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl, AVLNode *node, char *name)
{
    if (node == NULL)
        return _avl_createNode(name);

    if (strcmp(node->arr, name) > 0)
        node->left = _insert_AVL(avl, node->left, name);
    else if (strcmp(node->arr, name) < 0)
        node->right = _insert_AVL(avl, node->right, name);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    int balanceFactor = _getBalanceFactor(node);
    
    if (balanceFactor > 1 && strcmp(node->left->arr, name) > 0)
        return _leftCaseRotate(node);
    if (balanceFactor > 1 && strcmp(node->left->arr, name) < 0)
    return _leftRightCaseRotate(node);
    if (balanceFactor < -1 && strcmp(node->right->arr, name) < 0)
        return _rightCaseRotate(node);
    if (balanceFactor < -1 && strcmp(node->right->arr, name) > 0)
        return _rightLeftCaseRotate(node);
    
    return node;
}

bool avl_find(AVL *avl, char *name)
{
    AVLNode *temp = _search(avl->_node, name);
    if (temp == NULL)
        return false;
    
    if (!strcmp(temp->arr, name))
        return true;
    else
        return false;
}

void avl_insert(AVL *avl, char *name)
{
    avl->_node = _insert_AVL(avl, avl->_node, name);
    avl->_size++;
}

void _avl_inorder1(AVLNode *root)
{
    if(root) 
    {
        _avl_inorder1(root->left);
        printf("%d. %s\n", check, root->arr);
        check++;
        _avl_inorder1(root->right);
    }
}

void _avl_inorder2(AVLNode *root) {
    if(root) 
    {
        _avl_inorder2(root->left);
        if(check != 1)
        {
            printf("_");
        }
        printf("%s", root->arr);
        check++;
        _avl_inorder2(root->right);
    }
}

void avl_inorder(AVL *bst)
{
    _avl_inorder1(bst->_node);
    check = 1;
    _avl_inorder2(bst->_node);
}

int main()
{
    AVL avlku;
    avl_init(&avlku);
    
    char nama[1001];
    while(scanf("%s", nama) != EOF)
    {
        avl_insert(&avlku, nama);
    }

    avl_inorder(&avlku);

    return 0;
}