#include "algorithm.h"

static BST *parent = NULL;

Node *newNode(int key)
{
	Node *n = malloc(sizeof(Node));
	n->key = key;
	n->l = NULL;
	n->r = NULL;

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
			root = root->r;
		else
			root = root->l;
	}

	Node *n = newNode(key);

	if(key > pnt->key)
		pnt->r= n;
	else
		pnt->l= n;
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
		branch = &parent->r;
	else
		branch = &parent->l;

	if(target->l == NULL || target->r == NULL){
		*branch = (Node *)((long int)target->l + (long int)target->r);
		return;
	}

	//左子树的值都小于右子树，为什么不直接用右子树的根节点代替原节点，左子树加入右子树的最下一层
	/*
	 *barnch = target->r;
	 *Node *ptr = target->l;
	 *while(ptr->l != NULL){
	 *	ptr = ptr->l;
	 *}
	 *ptr->l = target->l;
	 *free(target);
	 * */

	//平衡性？
	if(target->r->l == NULL){
		*branch = target->r;
		target->r->l = target->l;
		free(target);
		return;
	}

	Node *ptr = target->r->l;
	parent = target->r;
	while(ptr->l != NULL){
		parent = ptr;
		ptr=ptr->l;
	}

	
	parent->l = ptr->r;
	ptr->r = target->r;
	ptr->l = target->l;

	*branch = ptr;
	

	free(target);


}

void BST_print(BST *root)
{
	Stack *stk = S_get();

	Node *ptr = root;

	push(stk, (void *)ptr);
	ptr = ptr->l;

	while(!S_isEmpty(stk) || ptr != NULL){
		while(ptr != NULL){
			push(stk, (void *)ptr);
			ptr = ptr->l;
		}

		ptr = (Node *)pop(stk);
		printf("%d ", ptr->key);

		ptr = ptr->r;
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
			root = root->r;
		else
			root = root->l;
	}

	return root;
}
