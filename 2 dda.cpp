#include <stdio.h>
#include <graphics.h>

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float xIncrement, yIncrement, x = x1, y = y1;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    xIncrement = (float)dx / (float)steps;
    yIncrement = (float)dy / (float)steps;

    putpixel(x, y, WHITE);

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    int x1 = 50, y1 = 50, x2 = 100, y2 = 300;

    drawLineDDA(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

