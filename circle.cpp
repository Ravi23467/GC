#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
int main()
{
	int gd=DETECT,gm,i;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	setcolor(YELLOW);
	circle(250,250,110);
	getch();
}
