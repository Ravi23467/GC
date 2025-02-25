#include <stdio.h>
#include <graphics.h>

void drawLineEquation(int x1, int y1, int x2, int y2) {
    float m = (float)(y2 - y1) / (float)(x2 - x1);
    float c = y1 - m * x1;


    int minX = x1 < x2 ? x1 : x2;
    int maxX = x1 > x2 ? x1 : x2;

    for (int x = minX; x <= maxX; x++) {
        int y = m * x + c;
        putpixel(x, y, WHITE);
    }

    getch();
    closegraph();
}

int main() {
    int x1 = 50, y1 = 50; // First endpoint
    int x2 = 400, y2 = 200; // Second endpoint
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawLineEquation(x1, y1, x2, y2);

    return 0;
}

