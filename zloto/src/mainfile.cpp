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

void main(){
	char ch, debugstr[20];
	ConfGraph cg;
	UtilGraph ug;
	InfixPostfix in2post;
	InfixPrefix in2pre;
	
	cg.initGraph();
	cleardevice();
	ug.displayTitle();
	settextstyle( 0, HORIZ_DIR, 1);
	do{
		ch = ug.displayMenu();
		delay( 1000);
	
		switch( ch){
			case '1':
				in2post.infix2postfix();
				break;
			
			case '2':
				in2pre.infix2prefix();
				break;
				
			default:
				break;
		}
	
	}while( ch != 'x');
	
	ug.displayEnd();
	getch();
	cg.closeGraph();
	getch();

}