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

/*monk_inversion.c struct*/
typedef struct inverse {
    int i;
    struct inverse *next;
}inverse;

/*monk_inversion.c prototypes*/
void findInverse(int **matrix, float **inverse, int size);
int calcAdjugate(int **matrix, int **adjugate, int size);
float calculateDeterminant(float **matrix, int size);
void getCofactor(int **mat, int **temp, int p, int q, int n);


#endif