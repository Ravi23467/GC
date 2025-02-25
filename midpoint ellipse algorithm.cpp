#include <stdio.h>
#include <graphics.h>

void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    int p1 = ry*ry - rx*rx*ry + rx*rx/4;

    while (2 * ry * ry * x < 2 * rx * rx * y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        x++;
        if (p1 < 0)
            p1 += 2 * ry * ry * x + ry * ry;
        else {
            y--;
            p1 += 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
        }
    }

    int p2 = ry*ry*(x + 0.5)*(x + 0.5) + rx*rx*(y - 1)*(y - 1) - rx*rx*ry*ry;

    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        y--;
        if (p2 > 0)
            p2 += -2 * rx * rx * y + rx * rx;
        else {
            x++;
            p2 += 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
        }
    }

    delay(5000);
}

int main() {
    int xc = 300, yc = 200;  // Center coordinates
    int rx = 150, ry = 100;  // Radii
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawEllipse(xc, yc, rx, ry);
    closegraph();
    return 0;
}

