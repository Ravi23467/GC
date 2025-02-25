#include<stdio.h>
#include<graphics.h>

void bresenhamLine(int x1, int y1, int x2, int y2)
{
	int dx= x2- x1;
	int dy = y2- y1;
	float pk= 2* dy - dx, x= x1, y= y1;
	putpixel(x,y, WHITE);
	while(x!=x2)
	{
		if(pk>0)
		{
			y++;
			pk+=2*dy-2*dx;
		}
		else
		{
			pk+=2*dy;
		}
		x++;
		putpixel(x,y, WHITE);
	}
}

int main()
{
	int gd= DETECT, gm;
	initgraph(&gd, &gm, "");
	int x1= 100, y1= 150, x2= 400, y2= 400;
	
	bresenhamLine(x1,y1,x2,y2);
	getch();
	closegraph();
	return 0;
}
