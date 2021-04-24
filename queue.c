//
//  algorithm.c
//  AlgorithmRepository
//
//  Created by 水小水 on 2021/4/23.
//

#include "algorithm.h"

static int QUEUE = 128;

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
    
    Q->data = (int *)malloc(sizeof(int) * QUEUE);
    memset(Q->data, RETURNERR, sizeof(int) * QUEUE);
    
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

int DEQUEUE(Queue *Q)
{
    if(Q_isEmpty(Q)) return RETURNERR;
    
    int ret = Q->data[Q->front];
    Q->data[Q->front] = RETURNERR;
    Q->front = (Q->front + 1) % QUEUE;
    
    return ret;
}

int ENQUEUE(Queue *Q, int data)
{
    if(Q_isFull(Q)) return RETURNERR;
    
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % QUEUE;
    
    return 0;
}

void Q_print(Queue *Q)
{
    printf("Queue(Length: %d) :", (Q->front + Q->rear + QUEUE) % QUEUE);
    
    int s = Q->front;
    int e = Q->rear;
    for(int i=s; i!=e; i=(i+1)%QUEUE){
        printf("%d ", Q->data[i]);
    }
    printf("\n");
}
