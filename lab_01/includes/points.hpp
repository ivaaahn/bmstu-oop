#ifndef _POINTS_HPP_
#define _POINTS_HPP_

#include <cstddef>
#include <cstdio>
#include "point.hpp"
#include "errors.hpp"

typedef struct
{
    size_t count = 0;
    point_t *data;
} points_t;

err_t load_points(points_t &points, FILE *datafile);

void translate_points(points_t &points, const translate_t &tr_data);
void scale_points(points_t &points, const scale_t &sc_data);
void rotate_points(points_t &points, const rotate_t &rot_data);

void destruct_points(points_t &points);

bool points_are_defined(const points_t &points);
void init_points(points_t &points);


#endif // _POINTS_HPP_
