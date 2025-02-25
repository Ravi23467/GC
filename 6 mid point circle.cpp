#include<stdio.h>
#include<graphics.h>

void mid_point_circle(float r, float h, float k)
{
	float x=0, y=r, p0= 1-r;
	while(x<=y)
	{
		putpixel(x+h, y+k, 15);
		putpixel(-x+h, y+k,15);
		putpixel(x+h, -y+k, 15);
		putpixel(-x+h, -y+k, 15);
		putpixel(y+h, x+k, 15);
		putpixel(-y+h, x+k, 15);
		putpixel(y+h, -x+k,15);
		putpixel(-y+h, -x+k, 15);
		
		if(p0<0)
		{
			p0+=2*x+1;
		}
		else
		{
			p0+= 2*x-1-2*y;
			y--;
		}
		x++;
	}
}

int main()
{
	int gd= DETECT, gm;

	float r=100, h=200,k=200;
	
	initgraph(&gd, &gm, "");
	
	mid_point_circle(r, h, k);
	getch();
	closegraph();
	return 0;
	
}
