#ifndef _MAIN_H_
#define _MAIN_H_

/*Header files*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*square.c structs*/
typedef struct point{
    float x, y;
}point;

/*Square.c Prototypes*/
float calc_dist(point p1, point p2);
float findmaxdist(point *p, int N);

#endif