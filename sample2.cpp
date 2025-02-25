
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main()
{

	int dx,dy,xend;
	int x0,y0,x1,y1;
	int x,y;
	float pk;	
	int gd=DETECT,gm;
	
	printf("\nEnter the value of Initial points (x0, y0) = ");
	scanf("%d%d",&x0,&y0);
	printf("\nEnter the value of final end points (x1,y1) = ");
	scanf("%d%d",&x1,&y1);
	
	//calculate delta x and delta y;
	dx=fabs(x1-x0);
	dy=fabs(y1-y0);
	float slope=(float)(y1-y0)/(x1-x0);
	//determine among (x0,y0) and (x1,y1) , which one is initial and which one is final point
	if(x0>x1)
	{
		x=x1;
		y=y1;
		xend=x0;
	 } 
	 if(x0<x1)
	 {
	 	x=x0;
	 	y=y0;
	 	xend=x1;
	 }
	 initgraph(&gd,&gm,(char*)" ");
	 
	 //plot the first point
	 putpixel(x,y,WHITE);
	 
	 if(slope<1)
	 {
	
	 //calculating the initial decision parameter for positive slope less than 1
	 pk=(2*dy)-dx;
	 
	 while(x<=xend)
	 {
	 	if(pk<0)
	 	{
	 		x=x+1;  //x always increases by 1 in positive slope less than 1 case
	 		y=y;
	 		pk=pk+2*dy;  //updating the value of pk+1
		 }
		 
		 if(pk>0)
		 {
	 	x=x+1; //x always increases by 1 in positive slope less than 1 case
	 	y=y+1; 
	 	pk=pk+2*dy-2*dx; //updating the value of pk+1
	 }
	putpixel(x,y,WHITE);
	}
}

if(slope>=1)  //positive slope greater than or equal to 1
{
	//calculating the initial decision parameter for positive slope greater than or equal to 1
	pk=(2*dx)-dy;
	 
	while(x<=xend)
	{
		if(pk<0)
		{
			x=x+1;  //y always increases by 1 in positive slope greater than or equal to 1 case
			y=y+1;
			pk=pk+2*dx;  //updating the value of pk+1
		}
		if(pk>=0)
		{
			x=x; //x remains the same in this case
			y=y+1;
			pk=pk+2*dx-2*dy; //updating the value of pk+1
		}
		putpixel(x,y,WHITE);
	}
}

getch();
closegraph();
return 0;

}
