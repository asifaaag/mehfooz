#include<iostream.h>
#include<conio.h>
#include<stack.h>
/*******************************************************
 ** Member functions of class Stack are defined here **
 *****************************************************/
Stack :: Stack(){
	top = -1;
}

int Stack :: isEmpty(){
	return( top == STACKBASE ? 1 : 0);
}

int Stack:: isFull(){
	return( top == STACKTOP ? 1 : 0);
}

//void Stack :: initStack(){
//	initGraphStack();
//}
void Stack :: push( char data){
	if(isFull()){
		cout <<"\nStack Overflow\n";
		getch();
	}else{

		stack[++top] = data;
		cout<<" top:"<<top;
	}
}

char Stack :: pop(){
	char data;
	if(isEmpty()){
		cout <<" \nStack Empty...!!\n";
		getch();//exit(0);
	}else{
		data = stack[top--];
		//return poped;
	}
	return data;
}

char Stack :: getStackEle(){
	char data;
	if(isEmpty()){
		cout <<" \nStack Empty...!!\n";
		getch();//exit(0);
	}else{
		data = stack[top];
		//return poped;
	}
	return data;
}
/* DEBUG CODE
int main(){
	int arr[] = {10,20,30,40,50,60,70,80,90,100,101};
	int dummy;
	Stack st;
	clrscr();
	cout <<" Push:\n";
	for(int i = 0; i < 10; i++){
		cout<<" Push("<<arr[i]<<");\n";
		st.push(arr[i]);
	}

	cout <<" Pop:\n";
	for(i = 0; i <=10; i++){
		dummy = st.pop();
		cout<<" Pop("<<dummy<<");\n";
	}
	getch();
	return 0;
}

*/