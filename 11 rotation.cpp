#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define PI 3.1415

void multiplyMatrix(float a[][3], float b[][3], float result[][3]) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (k = 0; k < 3; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    float theta = 45 * PI / 180;
    float a[3][3] = {{cos(theta), -sin(theta), 0},
                   {sin(theta), cos(theta), 0},  // Rotation by 45 degrees
                   {0, 0, 1}};
    float b[3][3] = {{300, 400, 1},
                   {100, 250, 1},
                   {1, 1, 1}}; // Added 1 for homogeneous coordinates
    float result[3][3];

    float x1 = 300, x2 = 100, y1 = 400, y2 = 250;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set text color and font
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

    // Draw the original line
    line(x1, y1, x2, y2);
    outtextxy(x1 + 10, y1 - 20, "Original");

    // Perform matrix multiplication
    multiplyMatrix(a, b, result);

    // Apply transformation to coordinates and convert to Cartesian coordinates
      x1 = result[0][0];
    y1 = result[1][0];
    x2 = result[0][1];
    y2 = result[1][1];


    // Draw the transformed line
    line(x1, y1, x2, y2);
    printf("x1:%f \ny1: %f \nx2:%f \ny2: %f \n", x1, y1, x2,y2);
    printf("%f", cos(theta));
    outtextxy(x1, y1 + 100, "Transformed");

    getch();
    closegraph();

    return 0;
}

