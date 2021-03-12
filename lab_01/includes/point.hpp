#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <cstdio>
#include "errors.hpp"

typedef struct
{
    double x;
    double y;
    double z;
} coord_t;


typedef coord_t point_t;
typedef coord_t translate_t;
typedef coord_t rotate_t;
typedef coord_t scale_t;


err_t read_point(point_t &point, FILE *datafile);

void translate_point(point_t &point, const translate_t &translate_data);

void scale_point(point_t &point, point_t &center, const scale_t &scale_data);

void rotate_point(point_t &point, point_t &center, const rotate_t &rotate_data);


#endif // _POINT_HPP_