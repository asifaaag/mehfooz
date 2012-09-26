/* This is Stack module, includes the neccessary functions required for basic stack operations */

#include <stdio.h>
#include <iostream.h>

#define STACKMAX 10;  //decide on the size based on the size that can be displayed in the graphics module
#define STACKMIN -1; 
using namespace std;

class Stack{
	private:
	int top;
	unsigned char stack[STACKMAX];

	public:
	Stack();
	void push( unsigned char sym);
	unsigned char pop();
	bool isEmpty();
	bool isFull();
}

void Stack::Stack(){
	top = STACKMIN;
}

bool Stack::isEmpty(){
	if( top == STACKMIN)
		return true;
}

bool Stack::isFull(){
	if( top == STACKMAX)
		return true;
}

void Stack::push( unsigned char sym){
	if(isFull()){
		cout << " STACK OVERFLOW...!!!\n"; //replace later using the grahics API dispError();
		return 0;		
	}
	else{
		stack[++top] = sym;		
	}	
}

unsigned char Stack::pop(){
	unsigned char sym;
	if(isEmpty()){
		cout << " STACK UNDERFLOW...!!!\n"; //replace later using the graphics API dispError();
		return 0;
	}
	else{
		sym = stack[top--];
		return sym;
	}
}
