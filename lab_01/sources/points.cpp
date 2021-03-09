#include <cstdio>
#include "points.h"
#include "errors.h"

static err_t read_count(points_t &points, FILE *datafile)
{
    size_t tmp_count = 0;

    if ((fscanf(datafile, "%zu", &tmp_count)) != 1)
        return FREAD_ERR;

    if (tmp_count < 2)
        return PCOUNT_ERR;

    points.count = tmp_count;

    return OK;
}

static err_t allocate(points_t &points)
{
    point_t *temp_data = (point_t *)malloc(points.count * sizeof(point_t));
    if (temp_data == NULL)
        return ALLOC_ERR;

    points.data = temp_data;

    return OK;
}

static err_t read_points(point_t *const points, const size_t size, FILE *datafile)
{
    for (size_t i = 0; i < size; i++)
        if ((fscanf(datafile, "%lf %lf %lf", &points[i].x, &points[i].y, &points[i].z)) != 3)
            return FREAD_ERR;

    return OK;
}

void translate(points_t &points, const translate_t &tr_data)
{
    for (size_t i = 0; i < points.count; i++)
        translate(points.data[i], tr_data);
}

void scale(points_t &points, const scale_t &sc_data)
{
    for (size_t i = 0; i < points.count; i++)
        scale(points.data[i], sc_data);
}

void rotate(points_t &points, const rotate_t &rot_data)
{
    for (size_t i = 0; i < points.count; i++)
        rotate(points.data[i], rot_data);
}

err_t loader(points_t &points, FILE *datafile)
{
    err_t rc = OK;

    if ((rc = read_count(points, datafile)) != OK)
        return rc;

    if ((rc = allocate(points)) != OK)
        return rc;

    if ((rc = read_points(points.data, points.count, datafile)) != OK)
        destructor(points);

    return rc;
}

void destructor(const points_t &points)
{
    free(points.data);
}
