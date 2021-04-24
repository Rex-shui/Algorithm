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
typedef struct Queue{
    int *data;
    int front;
    int rear;
}Queue;

//设置获取的队列的长度，默认128
void Q_setLength(int length);
Queue *Q_get(void);
void Q_free(Queue *Q);

int Q_isEmpty(Queue *Q);
int Q_isFull(Queue *Q);
int DEQUEUE(Queue *Q);
int ENQUEUE(Queue *Q, int data);
void Q_print(Queue *Q);
//*********************************************

#endif /* algorithm_h */
