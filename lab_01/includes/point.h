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

err_t points_reader(points_t &points, FILE *datafile);

void translate_point(point_t &point, const translate_data_t &coeffs);

void scale_point(point_t &point, const scale_data_t &coeffs);

void rotate_x_axis(point_t &point, const double theta);

void rotate_y_axis(point_t &point, const double theta);

void rotate_z_axis(point_t &point, const double theta);

void free_points(const points_t &points);

#endif // _POINT_H_