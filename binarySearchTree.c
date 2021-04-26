#include "algorithm.h"

static BST *guard;

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

	Node *parent;

	while(root != NULL){
		parent = root;
		if(key > root->key)
			root = root->r;
		else
			root = root->l;
	}

	Node *n = newNode(key);

	if(key > parent->key)
		parent->r= n;
	else
		parent->l= n;
}

void BST_delete(BST *root, int key)
{}

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
