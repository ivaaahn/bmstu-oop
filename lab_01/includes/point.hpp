#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <cstdio>

#include "errors.hpp"

struct coord_t
{
    double x;
    double y;
    double z;
};


typedef coord_t point_t;
typedef coord_t translate_t;
typedef coord_t rotate_t;
typedef coord_t scale_t;


err_t read_point(point_t &point, FILE *datafile);

err_t translate_point(point_t &point, const translate_t &translate_data);

err_t scale_point(point_t &point, const scale_t &scale_data);

err_t rotate_point(point_t &point, const rotate_t &rotate_data);


#endif // _POINT_HPP_