#include <stdio.h>

// horizontal and vertical rays
#define N 30
#define M 30

int main(void)
{
    double cx, cy, cz, r2; // x,y,z, radius squared
    {
        char buffer[100];
        puts("Please enter coordinates of the sphere centre x,y,z");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%lf,%lf,%lf", &cx, &cy, &cz);
    
        puts("Please enter the radius of the sphere");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%lf", &r2);
        r2 *= r2;
    }

    double ux, uy, uz, vx, vy, vz; // origin of line, unit vector direction
    ux = uy = uz = 0; // shoot ray from origin
    vx = vy = 0; vz = 1.0;

    for (int j = 0; j < M; j++)
    {
        // rows
        uy = (1 + 2 * j - M) / (double)M;
        for (int i = 0; i < N; i++)
        {
            // elements of row
            ux = (1 + 2 * i - N) * 4 / (double)N;

            double Dx = ux - cx, Dy = uy - cy, Dz = uz - cz;
            double D2 = Dx * Dx + Dy * Dy + Dz * Dz;
            double vD = vx * Dx + vy * Dy + vz * Dz;
            double disc = vD * vD - D2 + r2;

            if (disc < 0)
            { // discriminant is negative -> no intersection
                printf(" ");
            }
            else
            {
                printf("X"); // a graze or a full intersection
            }
        }
        printf("\n");
    }

    return 0;
}