/*
 * =====================================================================================
 *
 *      Filename:       queue.h
 *
 *      Description:    
 *
 *      Version:        1.0
 *      Created:        26/08/15 09:28:25 AM
 *      Revision:       none
 *      Compiler:       gcc 4.9.2
 *
 *      Author:         Hristiyan Vasilev
 *      Email:          HristyanVasilev@gmail.com
 *
 * =====================================================================================
 */

#ifndef QueueElement
#define QueueElement int
#endif

#ifndef QUEUE_H
#define QUEUE_H
typedef struct {
	QueueElement* elements;
	int n;
	int maxElements;
} Queue;


Queue *newQueue();

void freeQueue(Queue *queue);

void enqueue(Queue *queue, QueueElement element);

QueueElement dequeue(Queue *queue);
#endif
