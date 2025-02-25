#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main()
{

	int dx,dy,xend;
	int x0=100,y0=100,x1=500,y1=400;
	int x,y;
	float pk;	
	int gd=DETECT,gm;
	
	//calculate delta x and delta y;
	dx=fabs(x1-x0);
	dy=fabs(y1-y0);
	float slope=(y1-y0)/(x1-x0);
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
	 printf("%f", slope);
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
	 		x=x+1;  //x alwys incressse by 1 in positive slope less than 1 case
	 		y=y;
	 		pk=pk+2*dy;  //updaating the value of pk+1
		 }
		 
		 if(pk>0)
		 {
	 	x=x+1;//x alwys incressse by 1 in positive slope less than 1 case
	 	y=y+1; 
	 	pk=pk+2*dy-dx; //updating the value of pk+1
	 }
putpixel(x,y,WHITE);

}
}

if(slope>1)  //positive slope greater than 1
{
//calculating the initial decision parameter for positive slope less than 1
	 pk=(2*dx)-dy;
	 
	 while(x<=xend)
	 {
	 	if(pk<0)
	 	{
	 		x=x+1;  //y alwys incressse by 1 in positive slope less than 1 case
	 		y=y+1;
	 		pk=pk+2*dx;  //updaating the value of pk+1
		 }
		 
		 if(pk>0)
		 {
	 	x=x;//y alwys incressse by 1 in positive slope less than 1 case
	 	y=y+1; 
	 	pk=pk+2*dx-dy; //updating the value of pk+1
	 } 
    putpixel(x,y,WHITE);
}
   }
	 getch();
	 closegraph();
	 return 0;
}
