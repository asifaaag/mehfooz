#include<iostream.h>    //for cin, cout
#include<stdio.h>
#include<conio.h>       //for getche()
#include<ctype.h>       //for tolower() function
#include<stdlib.h>      //for itoa()
#include<GRAPHICS.H>    //to  load graphics driver
#include<dos.h>         //for delay() function
#include<string.h>
#include<graph.h>

/**========================================================================================**
 ** Member functions of class ConfGraph are defined here **
 **=======================================================================================**/

 /********************************************************************************
 ** function:		initGraph()
 ** developer:		Asif, asifiqbal.rs@gmail.com
 ** description: 	initializes graph driver and other related operations
 ** notes:			remember to specify the proper path to the graphics driver
 *******************************************************************************/
 void ConfGraph :: initGraph(){
	int driver = DETECT, mode, errorcode;
	initgraph(&driver, &mode, "c:\\tc\\bgi"); //specify the driver path
	errorcode = graphresult();

	if (errorcode != grOk){
		cout<<"Graphics error: \n"<<(grapherrormsg(errorcode));
		cout<<"Press any key to halt:";
		getch();
		exit(1);
	}
}

/********************************************************************************
 ** function:		closeGraph()
 ** developer:		Asif, asifiqbal.rs@gmail.com
 ** description: 	clears the console and closes the graphical driver
 ** notes:			
 *******************************************************************************/
void ConfGraph :: closeGraph(){
	cleardevice();
	closegraph();
}


/**========================================================================================**
 ** Member functions of class UtilGraph are defined here **
 **=======================================================================================**/

 /********************************************************************************
 ** function:		boundary()
 ** developer:		Asif, asifiqbal.rs@gmail.com
 ** description: 	draws a boundry (rectangle) at the edge of the screen 
 ** notes:			
 *******************************************************************************/
void UtilGraph :: boundary(){
	setfillstyle( 0, getmaxcolor());
	setcolor(YELLOW);
	rectangle( 6, 6, getmaxx()-6, getmaxy()-6);
}

/********************************************************************************
 ** function:		displayTitle()
 ** developer:		
 ** description: 	to display Project Title and author names
 ** notes:			
 *******************************************************************************/
void UtilGraph :: displayTitle(){
//Waiting for Mota's Input
}

/********************************************************************************
 ** function:		displayMenu()
 ** developer:		Asif, asifiqbal.rs@gmail.com
 ** description: 	to display Menu, user to select to the type of conversion
 ** notes:			
 *******************************************************************************/
char UtilGraph :: displayMenu(){
	cleardevice();
	setbkcolor(0);
	setcolor(2);

	//This do while; loop will execute untill character 'x' is not Entered
	outtextxy(30,5,"*==============*Menu*=============*");
	outtextxy(30,6,"Infix to Postfix				[1]");
	outtextxy(30,7,"Infix to Prefix     			[2]");
	outtextxy(30,8,"Exit							[x]");
	outtextxy(30,9,"*==============**==**=============*");
	//gotoxy(25,9);
	//cout<<"\t\t\t\t";
	outtextxy(30,10,"Enter Option      				[ ]");
	ch = tolower(( char) itoa(getche(), str, 10));
	//sprintf( str, "%c", ch);
	outtextxy( 63, 10, str);
	//gotoxy(30,15);
	return ch;
}

/**========================================================================================**
 ** Member functions of class StackGraph are defined here **
 **=======================================================================================**/
 
 /********************************************************************************
 ** function:		initStackGraph()
 ** developer:		Asif, asifiqbal.rs@gmail.com
 ** description: 	to initialize the stack on the console along with the in and outbox
 ** notes:			
 *******************************************************************************/
void StackGraph :: initStackGraph(){
	//Dislplays stack figure
	int x1 = 30, y1 = 40, x2 = x1+90, y2 = y1, size = 40, r;						//used as y-axis to draw lines within the rectangle
	char* string;

	setfillstyle( 0, getmaxcolor());
	setcolor( WHITE);
	outtextxy( x1+25, y1-14, "STACK");
	//rectangle( 30, 40, 110, 440);

	// This loop creates lines within Stacks outer rectangle
	for(int i = 1 ;i<11 ;i++){
		line( x1, y2, x2, y2);
		y2+=40;
	}

	y2-=40;
	line( x1, y1, x1, y2);
	line( x2, y1, x2, y2);

	r = 57;
	// This loop Displays stack's boxes Number
	for( i = 9 ;i>=1 ;i--){
		moveto(10,r);
		itoa(i,string,10);
		outtext(string)  ;
		r+=40;
	}

	y2+=20;
	//display boxes for poped and to be pushed values
	rectangle( 150, y2, 190, y2+24);
	outtextxy( 145, y2+30,"Outbox");
	rectangle( 200, y2, 240, y2+24);
	outtextxy( 200, y2+30,"Inbox");
//	setfillstyle( EMPTY_FILL, getmaxcolor());
	Xstack = ( x1+x2)/2-3;
	Ystack = y2-size/2-3+20; //y points out of the stack, so increment it before pushing and decrement after popping
	Xout = ( 150+190)/2-3;
	Yout = y2+24/2-3;
	Xin = ( 200+240)/2-3;
	Yin = Yout; 
}

/********************************************************************************
 ** function:		initStackGraph()
 ** developer:		Asif, asifiqbal.rs@gmail.com
 ** description: 	to initialize the stack on the console along with the in and outbox
 ** notes:			
 *******************************************************************************/
void StackGraph :: pushGraph( char data){
	
	char* dataStr;
	
	Ystack -= 40;
	
	//This will hide the character in the inbox with a bar, since each character is a 7X7 pixels
	setfillstyle( 0, getmaxcolor());
	bar( Xin, Yin, Xin+7, Yin+7);
	
	sprintf( dataStr, "%c", data);

	moveDataY2Y( Xin, Yin-30, Ystack, dataStr); //circle has to start from a specific distance
	moveDataX2X( Xin, Xstack+60, Ystack, dataStr);

	outtextxy( Xstack, Ystack, dataStr);
}

/********************************************************************************
 ** function:		initStackGraph()
 ** developer:		Asif, asifiqbal.rs@gmail.com
 ** description: 	to initialize the stack on the console along with the in and outbox
 ** notes:			
 *******************************************************************************/
void StackGraph :: popGraph( char data){
	
	char* dataStr;
	
	//This will hide the character in the inbox with a bar, since each character is a 7X7 pixels
	setfillstyle( 0, getmaxcolor());
	bar( Xstack, Ystack, Xstack+7, Ystack+7);
	
	sprintf( dataStr, "%c", data);

	moveDataX2X( Xstack+60, Xout, Ystack, dataStr); //circle has to start from a specific distance
	moveDataY2Y( Xout, Ystack, Yout-30, dataStr);

	outtextxy( Xout, Yout, dataStr);

	Ystack += 40;
}
/**========================================================================================**
 ** Member functions of class MoveGraph are defined here **
 **=======================================================================================**/

 /********************************************************************************
 ** function:		moveDataX2X()
 ** developer:		Asif, asifiqbal.rs@gmail.com
 ** description: 	to move a character within a circle from some X-axis to other 
					X-axis, takes care if either its a +ve or -ve movement
 ** notes:			
 *******************************************************************************/
 void MoveGraph :: moveDataX2X( int Xsrc, int Xdest, int Y, char* data){
	//outtextxy(Xdest,Y,"!");
	moveto( Xsrc, Y);
	while( getx()!=Xdest){
		setfillstyle( 0, getmaxcolor());
		setcolor( WHITE);
		circle( Xsrc+4, Y+3, 10);
		outtext( data);
		delay(10);
		setfillstyle( 0, getmaxcolor());
		bar( getx()-15, Y-7, getx()+7, Y+13);
		moveto( Xsrc, Y);
		Xsrc = Xsrc > Xdest? Xsrc-1 : Xsrc+1;
	}
}

 /********************************************************************************
 ** function:		moveDataY2Y()
 ** developer:		Asif, asifiqbal.rs@gmail.com
 ** description: 	to move a character within a circle from some Y-axis to other 
					Y-axis, takes care if either its a +ve or -ve movement
 ** notes:			
 *******************************************************************************/
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

/**========================================================================================**
 ** Member functions of class ExpressionGraph are defined here **
 **=======================================================================================**/

/********************************************************************************
** function:		initXY()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	to initialize all the XY co-ordinates of source, destination 
					and stack inbox and outbox
** notes:			hardcoded values subjected to change
*******************************************************************************/
void ExpressionGraph :: initXY(){
    Xsrc = XMID+9;
	Ysrc = YMID-125;
	Xdest = Xsrc;
	Ydest = YMID+118;
}

/********************************************************************************
** function:		getExpr()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	gets expression as an input from the user
** notes:			
*******************************************************************************/
char* ExpressionGraph :: getExpr(char* type){
	char* expr, *input;
	int x = XMID;
	int y = 30;
	
	settextstyle( 0, HORIZ_DIR, 1);
	setcolor(WHITE);
	sprintf( expr, "Enter the %s expression:", type);
	outtextxy(x, y, expr);
	//settextstyle( COMPLEX_FONT, HORIZ_DIR, 1);
	//setcolor(WHITE);
	gotoxy( 40, 4);
	cin.getline( input, 20);
	//outtextxy( 10, 20, input);
	//expr = "a+b+c+d+e+f+g\0";
	return input;
}

/********************************************************************************
** function:		initArray()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	initializes array according to the length of the expression 
** notes:			takes care if its either a source or destination array
*******************************************************************************/
void ExpressionGraph :: initArray(char* exprtype, int arrloc, int len){
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

/********************************************************************************
** function:		displayExprArray()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	displays an expression within the array
** notes:			
*******************************************************************************/
void ExpressionGraph :: displayExprArray(char* expr){
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

/********************************************************************************
** function:		moveCursor()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	to point to the current character in the source array
** notes:			
*******************************************************************************/
void ExpressionGraph :: moveCursor(){
	setcolor(YELLOW);
	outtextxy( Xsrc, Ysrc+20, "^");
}

/********************************************************************************
** function:		displayType()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	to display the type of each character in an expression
** notes:			blinks thrice
*******************************************************************************/
void ExpressionGraph :: displayType( char* type){
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

/********************************************************************************
** function:		moveDataExpr2Expr()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	moves data from source expression to destination expression
** notes:			
*******************************************************************************/
void ExpressionGraph :: moveDataExpr2Expr( char data){

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

/********************************************************************************
** function:		moveDataExpr2Stack()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	moves data from source expression to stack inbox
** notes:			
*******************************************************************************/
void ExpressionGraph :: moveDataExpr2Stack( char data){

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

/********************************************************************************
** function:		moveDataStack2Expr()
** developer:		Asif, asifiqbal.rs@gmail.com
** description: 	moves data from stack outbox to destination expression
** notes:			
*******************************************************************************/
void ExpressionGraph :: moveDataStack2Expr( char data){

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

