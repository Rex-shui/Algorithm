//
//  algorithm.h
//  AlgorithmRepository
//
//  Created by 水小水 on 2021/4/23.
//

#ifndef algorithm_h
#define algorithm_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RETURNERR 0x80000000

//Circular Queue
//*********************************************
typedef struct queue Queue;
//设置获取的队列的长度，默认128
void Q_setLength(int length);
Queue *Q_get(void);
void Q_free(Queue *Q);

int Q_isEmpty(Queue *Q);
int Q_isFull(Queue *Q);
void *DEQUEUE(Queue *Q);
void *ENQUEUE(Queue *Q, void *data);
//*********************************************


//stack
//*********************************************
typedef struct stack Stack;

void S_setLength(int length);
Stack *S_get(void);
void S_free(Stack *s);

int S_isEmpty(Stack *s);
int S_isFull(Stack *s);

void *pop(Stack *s);
void *push(Stack *s, void *data);
//*********************************************


//Binary Search Tree
//*********************************************
typedef struct BinarySearchTree Node, BST;

BST *BST_create(int key);
int BST_isEmpty(BST *root);
Node *BST_search(BST *root, int key);
void BST_insert(BST *root, int key);
void BST_delete(BST *root, int key);
void BST_print(BST *root);
//*********************************************


//Breadth First Search
void BFS_print();

#endif /* algorithm_h */
