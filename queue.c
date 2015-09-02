/*
 * =====================================================================================
 *
 *      Filename:       queue.c
 *
 *      Description:    queue, array implementation
 *
 *      Version:        1.0
 *      Created:        26/08/15 09:28:42 AM
 *      Revision:       none
 *      Compiler:       gcc 4.9.2
 *
 *      Author:         Hristiyan Vasilev
 *      Email:          HristyanVasilev@gmail.com
 *
 * =====================================================================================
 */
#include<stdlib.h>
#include"queue.h"


//add an element to a queue
void enqueue(Queue *queue, QueueElement element)
{
	if(queue->maxElements < queue->n + 1) {
		queue->elements = (QueueElement *)realloc(queue->elements,sizeof(Queue) * queue->maxElements * 2);
		if(queue->elements == NULL) {
			exit(1);
		}
		queue->maxElements *= 2;
	}
	queue->elements[queue->n++] = element;
}

QueueElement dequeue(Queue *queue)
{
	if(queue->n == 0) {
		return -1;
	}

	QueueElement element = queue->elements[0];
	for(int i=1;i<queue->n;i++) {
		queue->elements[i-1] = queue->elements[i];
	}
	queue->n--;
	return element;
}

//destoys an existing queue
void destroyQueue(Queue *queue)
{
	if(queue != NULL) {
		queue->n = 0;
		queue->maxElements = 0;
		if(queue->elements != NULL) {
			free(queue->elements);
		}
		free(queue);
	}
}

//creates a new queue
Queue *newQueue()
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));

	if(queue == NULL) {
		exit(1);
	}
	
	queue->elements = (QueueElement *)malloc(sizeof(QueueElement));
	
	if(queue->elements == NULL) {
		exit(1);
	}
	
	queue->maxElements = 1;
	return queue;
}

