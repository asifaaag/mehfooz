#ifndef __CONV_H
#define __CONV_H

#define N 64

#define LP 10
#define RP 20
#define OPERATOR 30
#define OPERAND 40

// Left parentheses precedence. Minimum of all
#define LPP 0
#define RPP 0

// Addition Subtraction precedence. Minimum among all operator precedence
#define AP 1
#define SP AP

// Multiplication divisor precedence.
#define MP 2
#define DP MP

// Remainder precedence.
#define REMP 2
#define NONE 9

class Expression : public Stack, public ExpressionGraph{
	public:
		int getType(char);             /** TYPE OF EXPRESSION GENERATOR **/
		int getPrec(char);             /** PRECEDENCE CHECKER FUNCTION **/
};

class Infix : public virtual Expression{
	protected:
		char infix[20];

	public:
		void displayInfix();
};

class Postfix : public virtual Expression{
	protected:
		char postfix[20];

	public:
		void displayPostfix();
};

class Prefix : public virtual Expression{
	protected:
		char prefix[20];

	public:
		void displayPrefix();
};

class InfixPostfix : public Infix, public Postfix{
	
	public:
		void infix2postfix();
		void postfix2infix();

};

class InfixPrefix : public Infix, public Prefix{

	public:
		void infix2prefix();
		void postfix2infix();
};
#endif 