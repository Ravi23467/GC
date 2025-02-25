#include<stdio.h>
#include<graphics.h>
#include<math.h>

#define PI 3.14159265

void polar_circle(int radius, int xc, int yc) {
    float theta, x, y;

    for (theta = 0; theta <= 360; theta += 1) {
        x = radius * cos(theta * PI / 180);
        y = radius * sin(theta * PI / 180);
        putpixel(xc + x, yc + y, WHITE); // Adjust the coordinate system for screen coordinates
         // Adjust delay as needed
    }
}

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");
    
    int radius = 100; // Radius of the circle
    int xc = 200, yc = 200; // Center coordinates of the circle

    polar_circle(radius, xc, yc);

    getch();
    closegraph();
    return 0;
}

