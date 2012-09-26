#include<iostream.h>    //for cin, cout
#include<stdio.h>
#include<conio.h>       //for getche()
#include<ctype.h>       //for tolower() function
#include<stdlib.h>      //for itoa()
#include<GRAPHICS.H>    //to  load graphics driver
#include<dos.h>         //for delay() function

void initGraph(){
	int driver = DETECT, mode, errorcode;
	initgraph(&driver, &mode, "e:\\tc\\bgi");
	errorcode = graphresult();

	if (errorcode != grOk){
		cout<<"Graphics error: \n"<<(grapherrormsg(errorcode));
		cout<<"Press any key to halt:";
		getch();
		exit(1);
	}
}

void initGraphStack(){
	//Dislplays stack figure
	char string[20];
	setbkcolor(0);
	setcolor(14);
	outtextxy( 55, 26, "STACK");
	rectangle(30,40,110,440);
	//line(30,40,30,440);
	int r=40;
	for(int i = 1 ;i<12 ;i++)
	{
	 line(30,r,110,r);
	 r+=40;
	}
	//line(110,40,110,440);
	r = 55;
	// This loop Displays stack's boxes Number
	for( i = 10 ;i>=1 ;i--)
	{
	 moveto(10,r);
	 itoa(i,string,10);
	 outtext(string)  ;
	 r+=40;
	}
	//These four statements makes a box
	rectangle(145,430,180,460);
	outtextxy(145,470,"postF");
	rectangle(195,430,230,460);
	outtextxy(200,470,"inF");
	//line(165,440,210,440);
	//line(165,440,165,460);
	//line(210,440,210,460);
	//line(165,460,210,460);
	setfillstyle(0, getmaxcolor());
}

void main()
{

char ch;
initGraph();
initGraphStack();
for(int i = 0 ;i<4 ; i++){
	  moveto(420,170);
	  settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
	  outtext("Stack Overflow..!!");
	  delay(800);
	  setfillstyle(0, getmaxcolor());
	  bar(420 ,165 ,630 ,180);
	  delay(400);
	  }
getch();
}