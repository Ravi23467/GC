#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>

// Structure to represent a particle
struct particle {
    int x, y;
    int speedX, speedY;
    int color;
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Initialize random number generator
    srand(time(NULL));

    // Create an array of particles
    int numParticles = 1000;
    struct particle particles[numParticles];

    // Initialize particles with random positions, velocities, and colors
    for (int i = 0; i < numParticles; i++) {
        particles[i].x = rand() % getmaxx();
        particles[i].y = rand() % getmaxy();
        particles[i].speedX = rand() % 5 + 1;
        particles[i].speedY = rand() % 5 + 1;
        particles[i].color = rand() % 15 + 1;
    }

    // Main simulation loop
    while (!kbhit()) {
        // Clear the screen
        cleardevice();

        // Update and draw particles
        for (int i = 0; i < numParticles; i++) {
            // Update particle positions
            particles[i].x += particles[i].speedX;
            particles[i].y += particles[i].speedY;

            // Boundary conditions
            if (particles[i].x < 0) particles[i].x = getmaxx();
            if (particles[i].x > getmaxx()) particles[i].x = 0;
            if (particles[i].y < 0) particles[i].y = getmaxy();
            if (particles[i].y > getmaxy()) particles[i].y = 0;

            // Draw particles
            setcolor(particles[i].color);
            putpixel(particles[i].x, particles[i].y, particles[i].color);
        }

        delay(50);
    }

    closegraph();
    return 0;
}

