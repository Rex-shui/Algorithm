#include "algorithm.h"

typedef struct BinarySearchTree{
        int key;
        struct BinarySearchTree *left,*right;
}Node, BST;

static BST *parent = NULL;

Node *newNode(int key)
{
	Node *n = malloc(sizeof(Node));
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	return n;
}
BST *BST_create(int key)
{
	BST *root = newNode(key);
	return root;
}

int BST_isEmpty(BST *root)
{
	if(root == NULL){
		printf("BinarySearchTree is NULL\n");
		return 1;
	}
	return 0;
}

void BST_insert(BST *root, int key)
{
	if(root == NULL){
		printf("BST_create first\n");
		return;
	}

	if(NULL != BST_search(root, key)){
		return;
	}

	Node *pnt = NULL;

	while(root != NULL){
		pnt = root;
		if(key > root->key)
			root = root->right;
		else
			root = root->left;
	}

	Node *n = newNode(key);

	if(key > pnt->key)
		pnt->right= n;
	else
		pnt->left= n;
}

void BST_delete(BST *root, int key)
{
	Node *target = BST_search(root, key);
	if(target == NULL){
		return;
	}

	if(target == root){
		return;
	}

	Node **branch;
	if(key > parent->key)
		branch = &parent->right;
	else
		branch = &parent->left;

	if(target->left == NULL || target->right == NULL){
		*branch = (Node *)((long int)target->left + (long int)target->right);
		return;
	}

	//左子树的值都小于右子树，为什么不直接用右子树的根节点代替原节点，左子树加入右子树的最下一层
	/*
	 *barnch = target->right;
	 *Node *ptr = target->left;
	 *while(ptr->left != NULL){
	 *	ptr = ptr->left;
	 *}
	 *ptr->left = target->left;
	 *free(target);
	 * */

	//平衡性？
	if(target->right->left == NULL){
		*branch = target->right;
		target->right->left = target->left;
		free(target);
		return;
	}

	Node *ptr = target->right->left;
	parent = target->right;
	while(ptr->left != NULL){
		parent = ptr;
		ptr=ptr->left;
	}

	
	parent->left = ptr->right;
	ptr->right = target->right;
	ptr->left = target->left;

	*branch = ptr;
	

	free(target);


}

void BST_print(BST *root)
{
	Stack *stk = S_get();

	Node *ptr = root;

	push(stk, (void *)ptr);
	ptr = ptr->left;

	while(!S_isEmpty(stk) || ptr != NULL){
		while(ptr != NULL){
			push(stk, (void *)ptr);
			ptr = ptr->left;
		}

		ptr = (Node *)pop(stk);
		printf("%d ", ptr->key);

		ptr = ptr->right;
	}

	printf("\n");
}

Node *BST_search(BST *root, int key)
{
	if(BST_isEmpty(root)) return NULL;

	while(root != NULL){
		if(key == root->key) break;

		parent = root;
		if(key > root->key)
			root = root->right;
		else
			root = root->left;
	}

	return root;
}
