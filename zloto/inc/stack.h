#ifndef __STACK_H
#define __STACK_H
#define SIZE 10
#define STACKTOP SIZE-1
#define STACKBASE -1

class Stack{
	private:
		int top;
		char stack[SIZE];

	public:
		Stack();
		int isEmpty();
		int isFull();
		//void initStack();
		void push(char data);
		char pop();
		char getStackEle();
};

#endif