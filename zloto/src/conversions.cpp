#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stack.h>
#include<conv.h>

/***********************************************************
 ** Member functions of class Expression are defined here **
 **********************************************************/
int Expression :: getPrec(char sym)
{
    switch(sym)
    {
    case '(':
        return(LPP);
    case '+':
        return(AP);
    case '-':
        return(SP);
    case '*':
        return(MP);
    case '/':
        return(DP);
    case '%':
        return(REMP);
    default :
        return(NONE);
    }
}

int Expression :: getType(char sym)
{
    switch(sym)
    {
    case '(':
        return(LP);
    case ')':
        return(RP);
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return(OPERATOR);
    default :
        return(OPERAND);
    }
}

/******************************************************
 ** Member functions of class Infix are defined here **
 *****************************************************/
void Infix :: displayInfix(){
	cout << infix;
}
 
 
 /*******************************************************
 ** Member functions of class Postfix are defined here **
 *******************************************************/
void Postfix :: displayPostfix(){
	cout << postfix;
}

void Postfix :: infixtopostfix(void)
{
    int i,p,l,type,prec;
    char next;
	InfixGraph inG;
	PostfixGraph poG;
    i=p=0;
	infix = inG.inputInfixExpr();
	inG.displayInfixArray();
	
	l=strlen(infix);
    while(i<l)
    {
        inG.navigateCursor();
		type=getType(infix[i]);
        switch(type)
        {
        case LP:
			stG.pushGraph(infix[i]);
            push(infix[i]);
            break;
        case RP:
			stG.popGraph();
            while((next=pop())!='(')
                postfix[p++]=next;
            break;
        case OPERAND:
            postfix[p++]=infix[i];
            break;
        case OPERATOR:
            prec=getPrec(infix[i]);
	    while(!isEmpty() && prec <= getPrec(getStackEle()))
                postfix[p++]=pop();
            push(infix[i]);
            break;
        }
        i++;
    }
    while(!isEmpty())
        postfix[p++]=pop();
    postfix[p]='\0';
}


void main()
{
    char ch;
	Postfix post;
    do
    {        
        post.infixtopostfix();
        cout <<"\ninfix = ";
		post.displayInfix();
		cout <<"\npostfix = ";
		post.displayPostfix();
	cout <<"\nDo you wish to continue\n";
        ch=getche();
    }while(ch=='Y' || ch=='y');
}


