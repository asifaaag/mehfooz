#include<iostream.h>    //for cin, cout
#include<stdio.h>
#include<stdlib.h>      //for itoa()
#include<conio.h>       //for getche()
#include<ctype.h>       //for tolower() function
#include<GRAPHICS.H>    //to  load graphics driver
#include<string.h>
#include<graph.h>
#include<stack.h>
#include<conv.h>
#include<dos.h>         //for delay() function

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
	case ')':
		return(RPP);
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
    switch( sym)
    {
		case '(':
			displayType( "Left Paranthesis");
			return(LP);
			
		case ')':
			displayType( "Right Paranthesis");
			return(RP);
			
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			displayType( "Operator");
			return(OPERATOR);
			
		default :
			displayType( "Operand");
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
	int i, p, len, op, prec;
	char next = 0, ele = 0;
	i=p=0;
	cleardevice();
	strcpy( infix, getExpr( "Infix"));
 	initStackGraph();
	initXY();
	len = strlen( infix);
	initArray( "Infix", SRC, len);
	displayExprArray( infix);
	initArray( "Postfix", DST, len);
 	while( i<len)
    {
        delay( 500);
		moveCursor();
		op = getType( infix[i]);
		
		switch( op)
 		{
			case LP:
				moveDataExpr2Stack( infix[i]);
				delay( 500);
				pushGraph( infix[i]);
				push( infix[i]);
				break;
			case RP:
				moveDataExpr2Stack( infix[i]);
				delay( 500);
				while((next=pop())!='('){
					popGraph( next);
					delay( 500);
					moveDataStack2Expr( next);
					postfix[p++]=next;
				}
				popGraph( next);
				delay( 500);
				ignorePar();
				break;
	 		case OPERAND:
				moveDataExpr2Expr( infix[i]);
				delay( 500);
				postfix[p++]=infix[i];
				break;
			case OPERATOR:
				moveDataExpr2Stack( infix[i]);
				delay( 500);
				prec = getPrec( infix[i]);
				while( !isEmpty() && prec <= getPrec( getStackEle())){
					checkPrec();
					ele = pop();
					postfix[p++] = ele;
					popGraph( ele);
					delay( 500);
					moveDataStack2Expr( ele);
				}
				push( infix[i]);
				pushGraph( infix[i]);
				break;
        }
	    i++;
	}
    while( !isEmpty()){
        ele = pop();
		postfix[p++]=ele;
		popGraph( ele);
		delay( 500);
		moveDataStack2Expr( ele);
	}
    postfix[p]='\0';
	delay( 1000);
	cleardevice();
	displayResult( "Infix", infix, "Postfix", postfix);
}


void InfixPrefix :: infix2prefix(void)
{
	int i, p, len, op, prec;
	char next = 0, ele = 0;
	i=p=0;
	cleardevice();
	strcpy( infix, getExpr( "Infix"));
	strcpy( infix, strrev( infix));
 	initStackGraph();
	initXY();
	len = strlen( infix);
	initArray( "Infix", SRC, len);
	displayExprArray( infix);
	initArray( "Prefix", DST, len);
 	while( i<len)
    {
        delay( 500);
		moveCursor();
		op = getType( infix[i]);
		
		switch( op)
 		{
			case RP:
				moveDataExpr2Stack( infix[i]);
				delay( 500);
				pushGraph( infix[i]);
				push( infix[i]);
				break;
			case LP:
				moveDataExpr2Stack( infix[i]);
				delay( 500);
				while((next=pop())!=')'){
					popGraph( next);
					delay( 500);
					moveDataStack2Expr( next);
					prefix[p++]=next;
				}
				popGraph( next);
				delay( 500);
				ignorePar();
				break;
	 		case OPERAND:
				moveDataExpr2Expr( infix[i]);
				delay( 500);
				prefix[p++]=infix[i];
				break;
			case OPERATOR:
				moveDataExpr2Stack( infix[i]);
				delay( 500);
				prec = getPrec( infix[i]);
				while( !isEmpty() && prec < getPrec( getStackEle())){
					checkPrec();
					ele = pop();
					prefix[p++] = ele;
					popGraph( ele);
					delay( 500);
					moveDataStack2Expr( ele);
				}
				push( infix[i]);
				pushGraph( infix[i]);
				break;
        }
	    i++;
	}
    while( !isEmpty()){
        ele = pop();
		prefix[p++]=ele;
		popGraph( ele);
		delay( 500);
		moveDataStack2Expr( ele);
	}
    prefix[p]='\0';
	delay( 1000);
	cleardevice();
	strcpy( infix, strrev( infix));
	strcpy( prefix, strrev( prefix));
	displayResult( "Infix", infix, "prefix", prefix);
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