#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int main() {
    int gd = DETECT, gm;
    int x = 1;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    while (x <= 150) {
        cleardevice();
        delay(2);

        // Fill the road with gray color
        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        rectangle(0, 250, 600, 400);
        floodfill(1, 300, LIGHTGRAY);

        // Draw the road markings
        setcolor(RED);
        for (int i = 0; i <= 600; i += 20) {
            line(i, 300, i + 10, 300);
        }

        // Draw the car
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
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
        floodfill(200 + x, 175, YELLOW);

        x++;
    }

    getch();
    closegraph();
    return 0;
}

