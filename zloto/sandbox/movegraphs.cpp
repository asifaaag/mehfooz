#include<iostream.h>    //for cin, cout
#include<conio.h>       //for getche()
#include<ctype.h>       //for tolower() function
#include<stdlib.h>      //for itoa()
#include<GRAPHICS.H>    //to  load graphics driver
#include<dos.h>         //for delay() function
#include<stdio.h>
#include<string.h>
 
#define XMID (getmaxx()/2);
#define YMID (getmaxy()/2);
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
		void movDataX2X( int Xsrc, int Xdest, int Y);
		void movDataY2Y( int X, int Ysrc, int Ydest);
};

class Expression{
	private:
		int Xsrc;
		int Xdest;
		int Ysrc;
		int Ydest;
	public:
		char* getExpr(char* type);
		void displayExpr(int x, int y, char* expr);
		void initArray( char* type, int arrtype, int len);
		void boundary();
		void movDataE2E();
		void movDataE2S();
		void movDataS2E();
};

void Expression :: boundary(){
	setfillstyle( 0, getmaxcolor());
	setcolor(YELLOW);
	rectangle( 6, 6, getmaxx()-6, getmaxy()-6);
}

void Expression :: initArray(char* type, int arrtype, int len){
	int x1, y1, x2, y2;
	//len = strlen(expr);
	x1 = XMID+20;
	x2 = x1;
	y2 = arrtype? YMID-150: YMID+150;
	y1 = y2-20;//upper edge for the source array
	settextstyle( 0, HORIZ_DIR, 1);
	setcolor(WHITE);
	for(int i=0; i <= len; i++){
		line( x2, y1, x2, y2);
		x2 = x2+20;
	}
	x2 = x2 - 20;
	line( x1, y1, x2, y1);
	line( x1, y2, x2, y2);

}

char* Expression :: getExpr(char* type){
	char* expr;
	int x = XMID+20;
	int y = 20;
	//for(int i=0;i<10;i++){
	settextstyle( 0, HORIZ_DIR, 1);
	setcolor(WHITE);
	sprintf( expr, "Enter the %s expression:", type);
	//y=y+32;
	outtextxy(x, y, expr);
	//}
	settextstyle( COMPLEX_FONT, HORIZ_DIR, 1);
	setcolor(WHITE);
	gotoxy( 41, 3);
	cin.getline( expr, 20);
	return expr;
}

void MoveGraph :: movDataX2X( int Xsrc, int Xdest, int Y){
	//outtextxy(Xdest,Y,"!");
	moveto(Xsrc,Y);
	while(getx()!=Xdest){
		setfillstyle(0, getmaxcolor());
		circle(Xsrc+4,Y+3,10);
		///itoa(arr[count],string,10);
		outtext("/");
		delay(4);
		setfillstyle(0, getmaxcolor());
		bar(getx()-15 ,Y-7 ,getx()+7 ,Y+13);
		moveto(Xsrc,Y);
		Xsrc = Xsrc > Xdest? Xsrc-1 : Xsrc+1;
	}
}

void MoveGraph :: movDataY2Y( int X, int Ysrc, int Ydest){
	outtextxy(X,Ydest,"!");
	moveto(X,Ysrc);
	while(gety()!=Ydest){
		setfillstyle(0, getmaxcolor());
		circle(X+4,Ysrc+3,10);
		///itoa(arr[count],string,10);
		outtext("/");
		delay(4);
		setfillstyle(0, getmaxcolor());
		//setfillstyle( 1, BLUE);
		bar(X-6 ,gety()-8 ,X+14 ,gety()+14);
		moveto(X,Ysrc);
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


void main(){
	ConfGraph cg;
	MoveGraph mg;
	Expression eg;
	char* infix;
	cg.initGraph();
	eg.boundary();
	setbkcolor(BLUE);
	infix = eg.getExpr("Infix");
	outtextxy( 10, 40, infix);
	int len = strlen(infix);
	eg.initArray( "Infix", SRC, len);
	eg.initArray( "Postfix", DST, len);
	
/*	for(int i=0; i<=10; i++){
	mg.movDataX2X(10,300,40);
	mg.movDataY2Y(300,40,380);
	mg.movDataX2X(300,10,380);
	mg.movDataY2Y(10,380,40);
	}
	cg.closeGraph();*/
	getch();
}
