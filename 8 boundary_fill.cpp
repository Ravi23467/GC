#include<stdio.h>
#include<graphics.h>
void boundary_fill4(int x, int y, int b_color, int fill_color)
{
	int value= getpixel(x,y);
	if(value!= b_color && value!= fill_color)
	{
		putpixel(x,y, fill_color);
		boundary_fill4(x-1, y, b_color, fill_color);
		boundary_fill4(x+1, y, b_color, fill_color);
		boundary_fill4(x, y-1, b_color, fill_color);
		boundary_fill4(x, y+1, b_color, fill_color);
		
	}
}
int main()
{
	int x=101,y=250;
	int gd=DETECT, gm;
	
	initgraph(&gd, &gm, "");
	rectangle(100, 200, 300, 300);
	int b_color=getpixel(100,200);
	boundary_fill4(x,y, b_color, 5);
	getch();
	closegraph();	
}
