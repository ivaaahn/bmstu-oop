#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <cstdio>
#include "errors.hpp"

typedef struct
{
    double x;
    double y;
    double z;
} point_t;

typedef struct
{
    double dx;
    double dy;
    double dz;
} translate_t;

typedef struct
{
    double kx;
    double ky;
    double kz;
} scale_t;

typedef struct
{
    double ax;
    double ay;
    double az;
} rotate_t;


err_t read_point(point_t &p, FILE *datafile);

void translate_point(point_t &point, const translate_t &translate_data);

void scale_point(point_t &point, const scale_t &scale_data);

void rotate_point(point_t &point, const rotate_t &rotate_data);

#endif // _POINT_HPP_