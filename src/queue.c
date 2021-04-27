//
//  algorithm.c
//  AlgorithmRepository
//
//  Created by 水小水 on 2021/4/23.
//

#include "algorithm.h"

static int QUEUE = 128;

typedef struct queue{
    void **data;
    int front;
    int rear;
}Queue;

/*
 循环队列
 front指向队列头，rear指向队列尾的下一个元素（损失一个空间，见判断队列空）
 
 */

void Q_setLength(int length)
{
    QUEUE = length;
}

Queue *Q_get(void)
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    memset(Q, 0, sizeof(Queue));
    
    Q->data = malloc(sizeof(int) * QUEUE);
    memset(Q->data, 0, sizeof(int) * QUEUE);
    
    return Q;
}

void Q_free(Queue *Q)
{
    free(Q->data);
    free(Q);
}

int Q_isEmpty(Queue *Q)
{
    return Q->front == Q->rear ? 1 : 0;
}

int Q_isFull(Queue *Q)
{
    if( (Q->rear+1) % QUEUE == Q->front) return 1;
    return 0;
}

void *DEQUEUE(Queue *Q)
{
    if(Q_isEmpty(Q)) return NULL;
    
    void *ret = Q->data[Q->front];
    Q->data[Q->front] = NULL;
    Q->front = (Q->front + 1) % QUEUE;
    
    return ret;
}

void *ENQUEUE(Queue *Q, void *data)
{
    if(Q_isFull(Q)) return NULL;
    
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % QUEUE;
    
    return data;
}
