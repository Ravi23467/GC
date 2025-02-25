#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int main() {
    int gd = DETECT, gm;
    int x = 1;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "c\\turbo c3\\bgi");

    while (x <= 150) {
        cleardevice();
        delay(10);
        
        // Draw road
        setcolor(BLACK);
        line(0, 250, 600, 250);

        // Fill road with black color
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(1, 251, BLACK);

        // Draw car
        setcolor(GREEN);
        line(150 + x, 100, 242 + x, 100);
        ellipse(242 + x, 105, 0, 90, 10, 5);
        line(150 + x, 100, 120 + x, 150);
        line(252 + x, 105, 280 + x, 150);
        line(100 + x, 150, 320 + x, 150);
        line(100 + x, 150, 100 + x, 200);
        line(320 + x, 150, 320 + x, 200);
        line(100 + x, 200, 110 + x, 200);
        line(320 + x, 200, 310 + x, 200);
        arc(130 + x, 200, 0, 180, 20);
        arc(290 + x, 200, 0, 180, 20);
        line(270 + x, 200, 150 + x, 200);
        circle(130 + x, 200, 17);
        circle(290 + x, 200, 17);
        
        // Fill car with red color
        setfillstyle(SOLID_FILL, GREEN);
        floodfill(151 + x, 201,GREEN);

        x++;
    }
    getch();
    closegraph();
    return 0;
}

