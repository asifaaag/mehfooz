#ifndef __CONV_H
#define __CONV_H

#define N 64

#define LP 10
#define RP 20
#define OPERATOR 30
#define OPERAND 40

// Left parentheses precedence. Minimum of all
#define LPP 0

// Addition Subtraction precedence. Minimum among all operator precedence
#define AP 1
#define SP AP

// Multiplication divisor precedence.
#define MP 2


#define DP MP

// Remainder precedence.
#define REMP 2

#define NONE 9


/******************************************
 ** Conversion classes are defined here **
 ****************************************/
class Expression{
		public:
			int getType(char);             /** TYPE OF EXPRESSION GENERATOR **/
			int getPrec(char);             /** PRECEDENCE CHECKER FUNCTION **/
};

class Infix : public Stack{
	protected:
		char infix[N+1], 
	
	public:
		void displayInfix();
};

class Postfix : public Infix{
	private:
		char postfix[N+1];
		
	public:
		void infixtopostfix(void);     /** POSTFIX CONVERSION FUNCTION **/
		void displayPostfix();
};

#endif 