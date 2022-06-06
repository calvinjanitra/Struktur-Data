#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int res[26];
int heights;
int level = 0;
bool flag = false;

typedef struct bstnode_t {
    int key,height,index;
    struct bstnode_t \
        *left, *right;
}BSTNode;

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
    newNode->height = heights;
    res[heights]++;
    newNode->index = res[heights];
    newNode->left = newNode->right = NULL;
    
    if(heights > level) level = heights;
    
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key){
    	heights++;
    	root->left = __bst__insert(root->left, value);
	}
        
    else if (value > root->key){
    	heights++;
    	root->right = __bst__insert(root->right, value);
	}
    
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
void findPos(BSTNode *root){
	if(root){
		findPos(root->left);
		if((root->height != 0 && root->height != 1) && (root->left != NULL || root->right != NULL)){
			if(root->index != 0 && root->index != res[root->height]){
				printf("%d ", root->key);
				flag = true;				
			}
		}
		findPos(root->right);
	}
	
}

int main(int argc, char const *argv[])
{
    BST set;
    bst_init(&set);
    memset(res, -1, sizeof(res));
    int x;
    int number;

    scanf("%d", &x);
    for(int i = 0; i < x; ++i){
        scanf("%d", &number);
        heights = 0;
        bst_insert(&set, number);
	}
    //cari posisi
	findPos(set._root);
	
	if(!flag){
        printf("It's not safe");
    } 
    return 0;
}