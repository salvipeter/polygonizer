#ifndef BLOOMENTHAL_POLYGONIZER_H
#define BLOOMENTHAL_POLYGONIZER_H

#define TET   0
#define NOTET 1

typedef struct point {
    double x, y, z;
} POINT;

typedef struct vertex {
    POINT position, normal;
} VERTEX;

typedef struct vertices {
    int count, max;
    VERTEX *ptr;
} VERTICES;

char *polygonize (double (*function)(double,double,double), double size, int bounds,
                  double x, double y, double z,
                  int (*triproc)(int,int,int,VERTICES), int mode);

#endif
