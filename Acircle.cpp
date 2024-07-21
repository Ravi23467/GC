#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
int main()
{
	int gd=DETECT,gm,i;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	for(i=0;i<=90;i++)
	{
		setcolor(i/10);
		circle(319,219-i,20+i);
		delay(50);
	}
	getch();
}
