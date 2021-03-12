#ifndef _POINTS_HPP_
#define _POINTS_HPP_

#include <cstdlib>
#include <cstdio>

#include "point.hpp"
#include "errors.hpp"


struct points_t
{
    size_t count;
    point_t *data;
    point_t center;
};


err_t load_points(points_t &points, FILE *datafile);

void init_points(points_t &points);
void destruct_points(points_t &points);

err_t translate_points(points_t &points, const translate_t &tr_data);

err_t scale_points(points_t &points, const scale_t &sc_data);

err_t rotate_points(points_t &points, const rotate_t &rot_data);

point_t& get_center(points_t &points);

bool points_are_defined(const points_t &points);



#endif // _POINTS_HPP_
