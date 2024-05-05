#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - Entry point
 * Return: Always 0
*/
int main(void)
{
	int N; /*Number of points*/
    int i;
    float maxdist, sidelength;

    scanf("%d", &N);
    if (N < 2 || N > 1000)
    {
        exit(EXIT_FAILURE);
    }
    point *Points = (point *)malloc(N * sizeof(point));
    if (!Points)
    {
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < N; i++)
    {
        scanf("%f %f", &Points[i].x, &Points[i].y);
    }

    maxdist = findmaxdist(Points, N);

    sidelength = maxdist / sqrt(2.0);

    printf("%.4f\n", sidelength);
    free(Points);

    return (0);
}
/**
 * calc_dist - calculates Euclidean distance between two points
 * @p1: A struct of the points.
 * @p2: a struct of the points.
*/
float calc_dist(point p1, point p2)
{
    float dx, dy;

    dx = p1.x - p2.x;
    dy = p1.y - p2.y;

    return sqrt(dx * dx + dy * dy);
}

/**
 * findmaxdist - find maximum distance between any pair of points.
 * @p: The array of points.
 * @N: The Number of points
*/
float findmaxdist(point *p, int N)
{
    int i, j;
    float distance, max_dist = 0.0;

    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            distance = calc_dist(p[i], p[j]);
            if (distance > max_dist)
            {
                max_dist = distance;
            }
        }
    }
    return (max_dist);
}