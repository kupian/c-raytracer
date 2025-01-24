#include <stdio.h>

int main(void) {
    double cx, cy, cz, r2; // x,y,z, radius squared
    cx = 0.0 ; cy = 0.0 ; cz = 2.0 ; r2 = 1.5; 

    double ux, uy, uz, vx, vy, vz; // origin of line, unit vector direction
    ux = uy = uz = 0; // shoot ray from origin
    vx = vy = 0; vz = 1.0; // ray goes along z direction

    double Dx = ux - cx, Dy = uy - cy, Dz = uz - cz;
    double D2 = Dx*Dx + Dy*Dy + Dz * Dz;

    double vD = vx*Dx + vy*Dy + vz*Dz;

    double disc = vD*vD - D2 + r2;

    printf("The discriminant is %06.2f for the case of:\n", disc);
    printf("Ray\torigin: (%06.2f, %06.2f, %06.2f)\n", ux, uy, uz);
    printf("\tDirection: (%06.2f, %06.2f, %06.2f)\n", vx, vy, vz);
    printf("Sphere\tcentre: (%06.2f, %06.2f, %06.2f)\n", cx, cy, cz);
    printf("\tRadius squared: %06.2f\n", r2);
    return 0;
}