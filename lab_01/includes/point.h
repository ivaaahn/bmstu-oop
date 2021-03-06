#ifndef _POINT_H_
#define _POINT_H_

#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "errors.h"

typedef struct
{
    double x;
    double y;
    double z;
} point_t;

typedef struct
{
    size_t count = 0;
    point_t *data = NULL;
} points_t;

typedef struct
{
    double dx;
    double dy;
    double dz;
} translate_data_t;

typedef struct
{
    double kx;
    double ky;
    double kz;
} scale_data_t;

typedef struct
{
    double ax;
    double ay;
    double az;
} rotate_data_t;

#endif // _POINT_H_