/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
int min, path;
/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key, jrk;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(int value, int j) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->jrk = j;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int j) {
    if (root == NULL) 
        return __bst__createNode(value, j);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, j);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, j);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

BSTNode* LCA(BSTNode* root, int n1, int n2)
{
    if (root == NULL) return NULL;
 
    
    if (root->key > n1 && root->key > n2)
        return LCA(root->left, n1, n2);
 
    
    if (root->key < n1 && root->key < n2)
        return LCA(root->right, n1, n2);
 
    return root;
}

int pathsum(BSTNode *root, int value)
{
    if (root == NULL) return path;
    
        if(value < root->key)
        {
            path += root->left->jrk;
            return pathsum(root->left, value);
        }
        else if(value > root->key)
        {
            path += root->right->jrk;
            return pathsum(root->right, value);
        }
        else{
            return path;
        }
}

void __bst__inorder(BST *bst, BSTNode *root, int f) {
    if (root) {
        __bst__inorder(bst, root->left, f);
        if(root->left == NULL && root->right == NULL)
        {
            BSTNode *res = LCA(bst->_root, f, root->key);
            path = 0;
            int paths = pathsum(res, f);
            printf("Paths1 : %d\n", paths);
            path = 0;
            paths += pathsum(res, root->key);
            printf("Paths2 : %d\n", paths);
            if(paths < min){
                min = paths;
                printf("--%d--\n", min);
            }
        }
        __bst__inorder(bst, root->right, f);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value, int j) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, j);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst, int f) {
    __bst__inorder(bst, bst->_root, f);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

int main(){
    BST set;
    bst_init(&set);
    int n, t, a, x, y;
    scanf("%d %d", &n, &a);
    bst_insert(&set, a, 0);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &x, &y);
        bst_insert(&set, x, y);
    }
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &a);
        if(!bst_find(&set, a))
        {
            printf("0\n");
        }
        else
        {
            min = 100000;
            bst_inorder(&set, a);
            printf("%d\n", min);
        }
    }
}
