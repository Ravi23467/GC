#include<stdio.h>
#include<graphics.h>
#include<math.h>

void simple_circle()
{
	int rad= 100;
	float x, y;
	for(int x=0 ; x<=rad; x++)
	{
		float y =sqrt(rad * rad -x*x);
		putpixel(x+200,y+200, 15);
		putpixel(x+200,-y+200, 15);
		putpixel(-x+200,y+200, 15);
		putpixel(-x+200,-y+200, 15);
		
		delay(25);
	}
}

int main()
{
	int gd= DETECT, gm;
	
	
	initgraph(&gd, &gm, "");
	simple_circle();
	getch();
	closegraph();
	return 0;
	
}
