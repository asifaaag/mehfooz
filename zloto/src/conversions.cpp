#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<graph.h>
#include<stack.h>
#include<conv.h>

/**========================================================================================**
 ** Member functions of class Expression are defined here **
 **=======================================================================================**/

/********************************************************************************
** function:		initGraph()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	returns precedence of a particular operator/operand
** notes:			
*******************************************************************************/
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

/********************************************************************************
** function:		getType()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	returns the type of character withtin an expression
** notes:			
*******************************************************************************/
int Expression :: getType(char sym)
{
    switch(sym)
    {
    case '(':
		displayType("Left Paranthesis");
        return(LP);
    case ')':
		displayType("Right Paranthesis");
        return(RP);
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
		displayType("Operator");
        return(OPERATOR);
    default :
		displayType("Operand");
        return(OPERAND);
    }
}

/**========================================================================================**
 ** Member functions of class displayInfix are defined here **
 **=======================================================================================**/

/********************************************************************************
** function:		displayInfix()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	
** notes:			
*******************************************************************************/
 void Infix :: displayInfix(){
	cout << infix;
}
 
 
 /**========================================================================================**
 ** Member functions of class Postfix are defined here **
 **=======================================================================================**/

/********************************************************************************
** function:		displayPostfix()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	
** notes:			
*******************************************************************************/
void Postfix :: displayPostfix(){
	cout << postfix;
}

/**========================================================================================**
 ** Member functions of class InfixPostfix are defined here **
 **=======================================================================================**/
/********************************************************************************
** function:   		inifix2postfix()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	function for conversion from infix to postfix expression
** notes:			takes care of graphical illustration of the same
*******************************************************************************/
void InfixPostfix :: infix2postfix(void)
{
    int i, p, len, type, prec;
    char next, *intest;
	i=p=0;

	//cout <<" Enter infix expression:\n";
	//cin.getline( infix, 20);
	intest = getExpr( "Infix");
	//inG.displayInfixArray();
	//len = strlen( infix);
	//outtextxy( 10, 20, intest);
	//initArray( "Infix", SRC, len);
	//delay( 1000);
	//displayExprArray( infix);
	//initStackGraph();
	//initArray( "Postfix", DST, len);
    /*
	while(i<len)
    {
       // inG.navigateCursor();
		moveCursor();
		type = getType( infix[i]);
	switch( type)
	{
	case LP:
			moveDataExpr2Stack( infix[i]);
			pushGraph( infix[i]);
            push( infix[i]);
            break;
        case RP:
			//stG.popGraph();
            while((next=pop())!='(')
                postfix[p++]=next;
            break;
        case OPERAND:
			moveDataExpr2Expr( infix[i]);
            postfix[p++]=infix[i];
            break;
        case OPERATOR:
            prec = getPrec( infix[i]);
			while( !isEmpty() && prec <= getPrec( getStackEle()))
                postfix[p++] = pop();
            push( infix[i]);
            break;
        }
        i++;
    }
    while( !isEmpty())
        postfix[p++]=pop();
    postfix[p]='\0';*/
}

/*
void main()
{
    char ch;
	InfixPostfix post;
    do
    {        
	post.infix2postfix();
        cout <<"\ninfix = ";
		post.displayInfix();
		cout <<"\npostfix = ";
		post.displayPostfix();
	cout <<"\nDo you wish to continue\n";
        ch=getche();
    }while(ch=='Y' || ch=='y');
}

*/