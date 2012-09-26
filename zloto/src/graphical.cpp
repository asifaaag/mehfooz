#include<iostream.h>    //for cin, cout
#include<stdio.h>
#include<conio.h>       //for getche()
#include<ctype.h>       //for tolower() function
#include<stdlib.h>      //for itoa()
#include<GRAPHICS.H>    //to  load graphics driver
#include<dos.h>         //for delay() function

/***********************************************************
 ** Member functions of class ConfGraph are defined here **
 *********************************************************/
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


/***********************************************************
 ** Member functions of class UtilGraph are defined here **
 *********************************************************/
void UtilGraph :: displayTitle(){
//Waiting for Mota's Input
}

char UtilGraph :: dislpayMenu(){
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
	outtextxy(30,10,"Enter Option      				[ ]\b\b");
	ch = tolower(itoa(getche()));
	sprintf( str, "%c", ch);
	outtextxy( 63, 10, str);
	//gotoxy(30,15);
	return ch
}

/***********************************************************
 ** Member functions of class StackGraph are defined here **
 *********************************************************/
 
void StackGraph :: initStackGraph(){
	//Dislplays stack figure
	int r=40;						//used as y-axis to draw lines within the rectangle
	
	setbkcolor(0);
	setcolor(14);
	outtextxy( 55, 26, "STACK");
	rectangle( 30, 40, 110, 440);
	
	// This loop creates lines within Stacks outer rectangle
	for(int i = 1 ;i<12 ;i++){
		line(30,r,110,r);
		r+=40;
	}
	
	r = 55;
	// This loop Displays stack's boxes Number
	for( i = 10 ;i>=1 ;i--){
		moveto(10,r);
		itoa(i,string,10);
		outtext(string)  ;
		r+=40;
	}
	
	//display boxes for poped and to be pushed values
	rectangle(145,430,180,460);
	outtextxy(145,470,"postF");
	rectangle(195,430,230,460);
	outtextxy(198,470,"inF");
	setfillstyle( EMPTY_FILL, getmaxcolor());
}

/***********************************************************
 ** Member functions of class InfixGraph are defined here **
 *********************************************************/
char* ExprGraph :: inputExpr(char* str){
	char *buffer;
	sprintf( buffer,"Enter a %s expression:\n",str);
	outtextxy( 300, 10, buffer);
    fflush( stdin);
    cin.getline( str, 20);
	return str;
}

/***********************************************************
 ** Member functions of class InfixGraph are defined here **
 *********************************************************/

 char* InfixGraph :: inputInfixExpr(){
	return( inputExpr( "Infix"));
 }