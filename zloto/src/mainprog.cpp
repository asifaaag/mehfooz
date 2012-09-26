#include<iostream.h>    //for cin, cout
#include<conio.h>       //for getche()
#include<ctype.h>       //for tolower() function
#include<stdlib.h>      //for itoa()
#include<GRAPHICS.H>    //to  load graphics driver
#include<dos.h>         //for delay() function


int col=60 , row = 417 ,n ,x=60 , y=417  ,size=10 ,arr[10]={12,56,23,46,32,89,11,99,12,66} , count = 0, top = 0;

char stack[45];
void push( );
void pop( );
void stack();
void loadgraph();

//This function loads , graph driver and mode
void loadgraph()
{
  clrscr();
  int driver = DETECT, mode, errorcode;
  initgraph(&driver, &mode, "c:\\tc\\bgi");
  errorcode = graphresult();
  if (errorcode != grOk)
     {
    cout<<"Graphics error: \n"<<(grapherrormsg(errorcode));
    cout<<"Press any key to halt:";
    getch();
    exit(1);
    }
}
////////////////////////////END OF LOAD GRAPH FUNCTION //////////////////////////////////////////////////// //////////////////////////////////////////////////////////////////////////////// ////////////////////////////////////////////////////////////////////////////////

void main()
{
	cleardevice();
	char ch;
	loadgraph();
	setbkcolor(0);
	setcolor(2);
	
}