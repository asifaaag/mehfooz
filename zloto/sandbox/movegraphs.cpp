#include<iostream.h>    //for cin, cout
#include<stdio.h>
#include<stdlib.h>      //for itoa()
#include<conio.h>       //for getche()
#include<ctype.h>       //for tolower() function
#include<GRAPHICS.H>    //to  load graphics driver
#include<dos.h>         //for delay() function
#include<string.h>
#include<graph.h>
#include<stack.h>
#include<conv.h>

/*
#define XMID (getmaxx()/2)
#define YMID (getmaxy()/2)
#define SRC 1
#define DST 0

class ConfGraph{
	public:
		void initGraph();
		void closeGraph();	
};

class MoveGraph{
	protected:
		//int Xsrc;
		//int Xdest;
		//int Ysrc;

		//int Ydest;

	public:
		void moveDataX2X( int Xsrc, int Xdest, int Y, char* data);
		void moveDataY2Y( int X, int Ysrc, int Ydest, char* data);
};

class Expression : MoveGraph{
	private:
		int MIDX ;
		int MIDY ;
		int Xsrc;
		int Ysrc;
		int Xdest;
		int Ydest;
		int Xin;
		int Yin;
		int Xout;
		int Yout;


	public:
		//Expression();
		char* getExpr(char* type);
		void displayExpr(int x, int y, char* expr);
		void initArray( char* type, int arrtype, int len);
		void displayExprArray(char* expr);
		void moveCursor();
		void displayType( char* type);
		void boundary();
		void moveDataExpr2Expr( char data);
		void moveDataExpr2Stack( char data);
		void moveDataStack2Expr( char data);
		void initXY();
};

void Expression :: initXY(){
    Xsrc = XMID+9;
	Ysrc = YMID-125;
	Xdest = Xsrc;
	Ydest = YMID+118;
	Xin = XMID-69;
	Yin = YMID+125;
	Xout = XMID-89;
	Yout = Yin;
}

void Expression :: moveDataExpr2Expr( char data){

	char* dataStr;
	
	//This will hide the character in the source array with a bar, since each character is a 7X7 pixels
	setfillstyle( 0, getmaxcolor());
	bar( Xsrc, Ysrc, Xsrc+7, Ysrc+7);
	
	sprintf( dataStr, "%c", data);

	moveDataY2Y( Xsrc, Ysrc+37, YMID, dataStr);
	moveDataX2X( Xsrc, Xdest, YMID, dataStr);
	moveDataY2Y( Xdest, YMID, Ydest-30, dataStr);

	outtextxy( Xdest, Ydest, dataStr);

	Xsrc += 24;
	Xdest += 24;
}

void Expression :: moveDataExpr2Stack( char data){

	char* dataStr;
	
	//This will hide the character in the source array with a bar, since each character is a 7X7 pixels
	setfillstyle( 0, getmaxcolor());
	bar( Xsrc, Ysrc, Xsrc+7, Ysrc+7);
	
	sprintf( dataStr, "%c", data);

	moveDataY2Y( Xsrc, Ysrc+37, YMID, dataStr);
	moveDataX2X( Xsrc, Xin, YMID, dataStr);
	moveDataY2Y( Xin, YMID, Yin-30, dataStr);

	outtextxy( Xin, Yin, dataStr);

	Xsrc += 24;
}

void Expression :: moveDataStack2Expr( char data){

	//Add logic to hide the data in the outbox array with a bar
	char* dataStr;
	
	//This will hide the character in the source array with a bar, since each character is a 7X7 pixels
	setfillstyle( 0, getmaxcolor());
	bar( Xout, Yout, Xout+7, Yout+7);
	
	sprintf( dataStr, "%c", data);
	//moveto( Xout, Yout-14);
	moveDataY2Y( Xout, Yout-30, YMID, dataStr);
	moveDataX2X( Xout, Xdest, YMID, dataStr);
	moveDataY2Y( Xdest, YMID, Ydest-30, dataStr);

	outtextxy( Xdest, Ydest, dataStr);

	Xdest += 24;
}

void Expression :: moveCursor(){
	setcolor(YELLOW);
	outtextxy( Xsrc, Ysrc+20, "^");
}

void Expression :: boundary(){
	setfillstyle( 0, getmaxcolor());
	setcolor(YELLOW);
	rectangle( 6, 6, getmaxx()-6, getmaxy()-6);
}

void Expression :: displayType( char* type){
	char *str;
	settextstyle( 0, HORIZ_DIR, 1);
	setcolor( YELLOW);
	for( int i=0; i<3; i++){
		sprintf( str, "%s..!!", type);
		outtextxy( XMID, YMID-70, str);
		delay(500);
		setfillstyle( 0, getmaxcolor());
		bar( XMID, YMID-70, XMID+300 ,YMID-63);
		delay(500);
	}
}

void Expression :: initArray(char* exprtype, int arrloc, int len){
	int x1, y1, x2, y2, size = 24, yloc = 110;
	//len = strlen(expr);
	x1 = XMID;
	x2 = x1;

	settextstyle( 0, HORIZ_DIR, 1);
	setcolor(WHITE);
	if(arrloc){
		y2 = YMID-yloc; //set y-axis according to source or dest type
		y1 = y2-size;//upper edge for the source array
	}
	else{
		y1 = YMID+yloc;
		y2 = y1+size;
	}

	//draw internal lines for the array
	for(int i=0; i <= len; i++){
		line( x2, y1, x2, y2);
		x2 = x2+size;
	}
	x2 = x2 - size;

	//draw the two external lines for the array
	line( x1, y1, x2, y1);
	line( x1, y2, x2, y2);

	settextstyle( 0, HORIZ_DIR, 1);
	setcolor(WHITE);
	//to display the type of array
	if(arrloc)
		outtextxy( x1, y1-12, exprtype);
	else
		outtextxy( x1, y2+5, exprtype);
}

///***************************************************
//** Note: characters are always 7X7 pixel, x1, y1 **
//** denote the left-top corner of a character    **
//*************************************************
void Expression :: displayExprArray(char* expr){
	int x, y, charloc = 24;
	x = XMID+9;
	y = YMID-125;
	char* dump;
	int len = strlen( expr);
	settextstyle( 0, HORIZ_DIR, 1);
	setcolor(WHITE);
	
	for(int i=0; i<len; i++){
		sprintf( dump, "%c", expr[i]);
		outtextxy( x, y, dump);
		x = x+charloc;
	}
}

char* Expression :: getExpr(char* type){
	char* expr;
	int x = XMID;
	int y = 30;
	
	settextstyle( 0, HORIZ_DIR, 1);
	setcolor(WHITE);
	sprintf( expr, "Enter the %s expression:", type);
	outtextxy(x, y, expr);
	//settextstyle( COMPLEX_FONT, HORIZ_DIR, 1);
	//setcolor(WHITE);
	//gotoxy( 40, 4);
	//cin.getline( expr, 20);
	expr = "a+b+c+d+e+f+g\0";
	return expr;
}

void MoveGraph :: moveDataX2X( int Xsrc, int Xdest, int Y, char* data){
	//outtextxy(Xdest,Y,"!");
	moveto( Xsrc, Y);
	while( getx()!=Xdest){
		setfillstyle( 0, getmaxcolor());
		setcolor( WHITE);
		circle( Xsrc+4, Y+3, 10);
		///itoa(arr[count],string,10);
		outtext( data);
		delay(10);
		setfillstyle( 0, getmaxcolor());
		bar( getx()-15, Y-7, getx()+7, Y+13);
		moveto( Xsrc, Y);
		Xsrc = Xsrc > Xdest? Xsrc-1 : Xsrc+1;
	}
}

void MoveGraph :: moveDataY2Y( int X, int Ysrc, int Ydest, char* data){
	//outtextxy(X,Ydest,"!");
	moveto( X, Ysrc);
	while( gety()!=Ydest){
		setfillstyle( 0, getmaxcolor());
		setcolor( WHITE);
		circle( X+4, Ysrc+3, 10);
		///itoa(arr[count],string,10);
		outtext( data);
		delay(10);
		setfillstyle( 0, getmaxcolor());
		//setfillstyle( 1, BLUE);
		bar( X-6, gety()-8, X+14, gety()+14);
		moveto( X, Ysrc);
		Ysrc = Ysrc > Ydest? Ysrc-1 : Ysrc+1;
	}
}

void ConfGraph :: initGraph(){
	int driver = DETECT, mode, errorcode;
	initgraph(&driver, &mode, "c:\\tc\\bgi");
	errorcode = graphresult();

	if (errorcode != grOk){
		cout<<"Graphics error: \n"<<(grapherrormsg(errorcode));
		cout<<"Press any key to halt:";
		getch();
		exit(1);
	}
}

void ConfGraph :: closeGraph(){
	cleardevice();
	closegraph();
}
*/

void main(){
	ConfGraph cg;
	//MoveGraph mg;
	InfixPostfix in2post;
	//char* infix;
	cg.initGraph();
	in2post.initXY();
	//eg.boundary();
	//setbkcolor(BLUE);
	in2post.infix2postfix();
	
	//eg.initArray( "Infix", SRC, len);
	//eg.displayExprArray(infix);
	//eg.initArray( "Postfix", DST, len);
	//eg.initStackGraph();
	//eg.moveCursor();
	//eg.displayType("Operator");
	//eg.moveDataExpr2Expr( 'a');
	//eg.moveDataExpr2Stack( '+');
	//delay( 1000);
	//eg.pushGraph( '+');
	//eg.moveDataExpr2Expr( 'b');
	//eg.popGraph( '+');
	//delay( 1000);
	//eg.moveDataStack2Expr( '+');
	//delay( 1000);
	
	
	//eg.moveDataExpr2Expr( 'b');
	//int x=XMID+20;
	//int y=YMID-162;
	//outtextxy( XMID, YMID, "^");
//	for(int i=0; i<=10; i++){
//	mg.movDataX2X(10,300,40);
	//mg.movDataY2Y(x,y,380);
//	mg.movDataX2X(300,10,380);
 //	mg.movDataY2Y(10,380,40);
//	}
	//cg.closeGraph();
	//getch();
}