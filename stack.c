/*
 * =====================================================================================
 *
 *      Filename:       stack.c
 *
 *      Description:    stack, array implementation 
 *
 *      Version:        1.0
 *      Created:        24/08/15 10:49:00 AM
 *      Revision:       none
 *      Compiler:       gcc 4.9.2
 *
 *      Author:         Hristiyan Vasilev
 *      Email:          HristyanVasilev@gmail.com
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include "stack.h"

//pushesh an element on the top of a stack
void push(Stack *stack, StackElement element)
{
	if(stack->maxElements < stack->n + 1) { //new element can't fit
		stack->elements = (StackElement *)realloc(stack->elements,sizeof(Stack) * stack->maxElements * 2);
		if(stack->elements == NULL) {
			exit(1);
		}
		stack->maxElements *= 2;
	}
	stack->elements[stack->n++] = element;
}

//pops the top element of a stack
StackElement pop(Stack *stack)
{
	if(stack->n == 0) {
		return -1;
	}

	StackElement element = stack->elements[stack->n-1];
	stack->n--;
	return element;
}

//returns the top element of a stack, without removing it.
StackElement peek(Stack *stack)
{
	if(stack->n == 0) {
		return -1;
	}
	return stack->elements[stack->n];
}

//creates a new stack
Stack *newStack()
{
	Stack *stack =  (Stack *)malloc(sizeof(Stack));
	if(stack == NULL) {
		exit(1);
	}
	stack->n = 0;
	stack->maxElements = 1;
	stack->elements = (StackElement *)malloc(sizeof(StackElement));
	return stack;
}

//frees the memory of a dynamically allocated stack and it's elements.
void freeStack(Stack *stack)
{
	if(stack != NULL) {
		stack->n=0;
		stack->maxElements=0;
		if(stack->elements != NULL) {
			free(stack->elements);
		}
		free(stack);
	}
}
