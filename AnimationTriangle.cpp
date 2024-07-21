#include<graphics.h>
#include<stdio.h>
#include<conio.h>
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi"); 
		setcolor(10);
		int x1=100,y1=200;
		int x2=300,y2=200;
		int x3=200,y3=50;
		line(x1,y1,x2,y2);
		line(x2,y2,x3,y3);
		line(x3,y3,x1,y1);
		setfillstyle(1,4);
		floodfill(202,348,10);
 getch();
 closegraph();
}
