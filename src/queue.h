#ifndef __QUEUE_H
#define __QUEUE_H

typedef void* QueueInfo;
typedef void* Queue;

Queue createQueue();
int isQueueEmpty(Queue queue);
int getQueueSize(Queue queue);
void enqueue(Queue queue, QueueInfo info);
QueueInfo dequeue(Queue queue);
void deleteQueue(Queue queue);

#endif