#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
int  main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi"); 
	for(int i=100;i>=0;i--)
	{
		delay(10);
		setcolor(i/8);
		line(300-i,100,200-i,200);
		line(300-i,100,400-i,200);
		line(200-i,200,400-i,200);
	}
 getch();
 closegraph();
}
