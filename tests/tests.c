/*
 * =====================================================================================
 *
 *      Filename:       tests.c
 *
 *      Description:    
 *
 *      Version:        1.0
 *      Created:        25/08/15 09:16:04 AM
 *      Revision:       none
 *      Compiler:       gcc 4.9.2
 *
 *      Author:         Hristiyan Vasilev
 *      Email:          HristyanVasilev@gmail.com
 *
 * =====================================================================================
 */

//int test
//#define StackElement int

//char
#define StackElement char
#define QueueElement char

#include<stdio.h>
#include"stack.h"
#include"queue.h"

//testing includes guards
#include"stack.h"
#include"queue.h"

int main()
{

	Stack *stack = newStack();
	Queue *queue = newQueue();
	StackElement popped;
	QueueElement eq;


	//int test
	/*
	
	enqueue(queue, 4);
	enqueue(queue, 5);
	enqueue(queue, 6);
	enqueue(queue, 7);
	enqueue(queue, 8);
	
	push(stack, 4);
	push(stack, 5);
	push(stack, 6);
	push(stack, 7);
	push(stack, 8);

	StackElement popped;

	while( (popped = pop(stack)) != -1) {
		printf("%d\n",popped);
	}
	*/

	//char test
	push(stack, 'a');
	push(stack, 'b');
	push(stack, 'c');
	push(stack, 'd');
	push(stack, 'f');

	enqueue(queue, 'a');
	enqueue(queue, 'b');
	enqueue(queue, 'c');
	enqueue(queue, 'd');
	enqueue(queue, 'f');
	
	printf("Stack:\n");
	while( (popped = pop(stack)) != -1) {
		printf("%c\n",popped);
	}

	printf("Queue:\n");
	while( (eq = dequeue(queue)) != -1) {
		printf("%c\n",eq);
	}

	freeStack(stack);
	freeQueue(queue);
	return 1;
}
