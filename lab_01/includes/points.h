#ifndef _POINTS_H_
#define _POINTS_H_

#include <cstddef>
#include <cstdio>
#include "point.h"
#include "errors.h"

typedef struct
{
    size_t count = 0;
    point_t *data = NULL;
} points_t;

err_t loader(points_t &points, FILE *datafile);

void translate(points_t &points, const translate_t &tr_data);
void scale(points_t &points, const scale_t &sc_data);
void rotate(points_t &points, const rotate_t &rot_data);

void destructor(const points_t &points);

#endif // _POINTS_H_
