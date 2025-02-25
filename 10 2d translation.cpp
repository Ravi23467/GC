#include <stdio.h>
#include <graphics.h>

void multiplyMatrix(int a[][3], int b[][3], int result[][3]) {
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
    int a[3][3] = {{1, 0, 500},
                   {0, 1, 0},  // Translation along the y-axis by 500 units
                   {0, 0, 1}};
    int b[3][3] = {{10, 100, 1},
                   {100, 100, 1},
                   {1, 1, 1}}; // Added 1 for homogenous coordinates
    int result[3][3];

    int x1 = 10, x2 = 100, y1 = 100, y2 = 100;
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

    // Apply transformation to coordinates
    x1 = result[0][0];
    y1 = result[1][0];
    x2 = result[0][1];
    y2 = result[1][1];

    // Draw the transformed line
    line(x1, y1, x2, y2);
    outtextxy(x1 + 10, y1 - 20, "Transformed");

    getch();
    closegraph();

    return 0;
}

