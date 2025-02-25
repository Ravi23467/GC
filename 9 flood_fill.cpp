#include <stdio.h>
#include <graphics.h>

// Function to perform flood fill
void flood_fill(int x, int y, int b_color, int fill_color) {


    int current_color = getpixel(x, y);
    
    // Check if the current pixel color matches boundary color
    if (current_color == b_color) {        putpixel(x, y, fill_color);
        
        // Recursive flood fill in 4 directions
        flood_fill(x - 1, y, b_color, fill_color); // Left
        flood_fill(x + 1, y, b_color, fill_color); // Right
        flood_fill(x, y - 1, b_color, fill_color); // Up
        flood_fill(x, y + 1, b_color, fill_color); // Down
    }
}

int main() {
    int x = 150, y = 250; // Start point inside the rectangle
    int gd = DETECT, gm;
    
    initgraph(&gd, &gm, "");
    
    rectangle(100, 200, 300, 300); // Draw the rectangle
    int b_color1 = getpixel(150, 250); // Color inside the rectangle

    flood_fill(x, y, b_color1, 2); // Perform flood fill

    getch();
    closegraph();	
    
    return 0;
}

