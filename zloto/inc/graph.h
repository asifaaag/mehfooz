#ifndef __GRAPH_H
#define __GRAPH_H



#define XMID (getmaxx()/2)
#define YMID (getmaxy()/2)
#define SRC 1
#define DST 0
#define STRINGSIZE 50

class ConfGraph{
	public:
		void initGraph();
		void closeGraph();	
};

class UtilGraph{
	private:
		char ch;
		char str[STRINGSIZE];
	
	public:
		void displayStart();
		void boundary();
		void displayTitle();
		char displayMenu();
		void displayTips();
		void displayTransition( int color);
		void displayEnd();	
};

class MoveGraph{
	public:
		void moveDataX2X( int Xsrc, int Xdest, int Y, char* data);
		void moveDataY2Y( int X, int Ysrc, int Ydest, char* data);
};

class StackGraph : public MoveGraph{
	private:
		char ch;
		char str[STRINGSIZE];
		int Xstack;
		int Ystack;
	
	protected:
		int Xin;
		int Yin;
		int Xout;
		int Yout;
		
	public:
		//StackGraph();
		void initStackGraph();
		void pushGraph( char data);
		void popGraph( char data);
		void checkPrec();
};

class ExpressionGraph : public StackGraph{
	private:
		int Xsrc;
		int Ysrc;
		int Xdest;
		int Ydest;
		
	public:
		void initXY();
		char* getExpr(char* type);
		void displayExpr(int x, int y, char* expr);
		void initArray( char* type, int arrtype, int len);
		void displayExprArray(char* expr);
		void moveCursor();
		void displayType( char* type);
		void moveDataExpr2Expr( char data);
		void moveDataExpr2Stack( char data);
		void moveDataStack2Expr( char data);
};

#endif