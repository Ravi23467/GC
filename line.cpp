#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\TurboC3\\BGI");
	line(500,400,200,200);
	getch();
}

