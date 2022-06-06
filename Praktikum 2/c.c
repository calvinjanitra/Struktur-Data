#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int a;
int cek = 1;
/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    int nama;
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

BSTNode* __bst__createNode(int value, int c) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->nama = c;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int c) {
    if (root == NULL) 
        return __bst__createNode(value, c);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, c);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, c);
    
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

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
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

void bst_insert(BST *bst, int value, int c) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, c);
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

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

int levelranker(BSTNode *root){
    if(root != NULL){
        if(a >= root->nama && cek == 1){
        a += root->nama;
        // cout<<a<<endl;
        printf("Lantai %d sudah ditaklukan. Jumlah nama bertambah menjadi %d.\n", root->key, a);
    }
    else if(a < root->nama && cek == 1){
        cek = 0;
        // cout<<a<<endl;
        printf("Langkahku berhenti di lantai %d.\n", root->key);
        return 0;
    }
    levelranker(root->left);
    levelranker(root->right);

    }
    return 1;
}

void firstranker(BST *bst){
    if(levelranker(bst->_root)){
        cek = 1;
    }else cek = 0;
}

int main(int argc, char const *argv[])
{
    BST set;
    bst_init(&set);
    int n, f, l, s;

    scanf("%d %d %d", &n, &a, &f);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &l, &s);
        bst_insert(&set, l, s);
    }
    firstranker(&set);
    printf("\n");
    if(a > f){
        printf("Foolish Chaos sudah musnah. Masa damai telah dimulai...\n");
    }
    else if(a < f){
        printf("Kehancuran akan terus berlanjut tanpa akhir...\n");
    }
    else if(a==f){
        printf("Akan aku akhiri pertempuran ini, bagaimanapun caranya...\n");
    }
    return 0;
}