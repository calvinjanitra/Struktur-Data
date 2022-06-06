#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
using namespace std;

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
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

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
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

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
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

int bst_findheight(BSTNode *root){
	if(root == NULL){
		return -1;
	}
	else{
		int lheight = bst_findheight(root->left);
		printf("LHEIGHT : %d\n", lheight);
		int rheight = bst_findheight(root->right);
		printf("RHEIGHT : %d\n", rheight);
		if(lheight > rheight){
			//printf(" %d \n", lheight);
			return (lheight + 1);
		}
		else{
			//printf(" %d \n", rheight);
			return (rheight + 1);
		}
	}
}

int bst_fheight(BST *bst){
	int height = bst_findheight(bst->_root);
	return height;
}


int bst_findminmax(BSTNode *root, int res[], int level,int rev){
	if(root != NULL){
		bst_findminmax(root->left, res, level + 1, rev);
		if(rev){
			if(res[level] == 0) res[level] = root->key;
			if(root->key < res[level]) res[level] = root->key;
			//printf("--%d--%d\n", res[level], level);
		}
		else{
			if(res[level] == 0) res[level] = root->key;
			if(root->key > res[level]) res[level] = root->key;
			//printf("**%d**%d\n", res[level], level);
		}
		bst_findminmax(root->right, res, level+ 1, rev);
	}
}

int bst_fminmax(BST *bst, int rev, int h){
	int res[h];
	int i;
	for(i = h; i >= 0; i--){
		if(rev){
			bst_findminmax(bst->_root, res, 0, rev);
			printf("%d ", res[i]);
			rev = 0;
		}
		else{
			bst_findminmax(bst->_root, res, 0, rev);
			printf("%d ", res[i]);
			rev = 1;
		}
	}
}
 
int main()
{
    BST set;
    bst_init(&set);

	int n, a, i, rev = 1;
	cin>>n;
	for(i = 1; i <= n; i++){
		cin>>a;
		bst_insert(&set, a);
	}
	int level = bst_fheight(&set);
	bst_fminmax(&set, rev, level);
    
    return 0;
}