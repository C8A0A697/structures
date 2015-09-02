/*
 * =====================================================================================
 *
 *      Filename:       stack.h
 *
 *      Description:    
 *
 *      Version:        1.0
 *      Created:        24/08/15 10:50:05 AM
 *      Revision:       none
 *      Compiler:       gcc 4.9.2
 *
 *      Author:         Hristiyan Vasilev
 *      Email:          HristyanVasilev@gmail.com
 *
 * =====================================================================================
 */

#ifndef StackElement
#define StackElement int
#endif

#ifndef STACK_H
#define STACK_H
typedef struct {
	StackElement* elements;
	int n;
	int maxElements;
} Stack;


Stack *newStack();

void freeStack(Stack *stack);

void push(Stack *stack, StackElement element);

StackElement pop(Stack *stack);
#endif
