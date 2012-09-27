#include<graphics.h>

//to see if the issue linking feature really works..!!
//some dummy comment this is 

<<<<<<< HEAD
//second dummy comment
=======
//from manoj's system..!

//this is the third change..!
>>>>>>> 270ccaf8781d2ccf4ef5933c100f1047b65e289d
int main()
{
   int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 350,y=250,radius=50;
 
   initgraph(&gd, &gm, NULL);
 
//   rectangle(left, top, right, bottom);
   circle(x, y, radius);
//   bar(left + 300, top, right + 300, bottom);
 //  line(left - 10, top + 150, left + 410, top + 150);
 //  ellipse(x, y + 200, 0, 360, 100, 50);
   outtextxy(left + 100, top + 325, "My First C Graphics Program");
 
   getch();
   closegraph();
   return 0;
}
