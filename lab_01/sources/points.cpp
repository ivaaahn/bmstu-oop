#include <cstdio>

#include "points.hpp"
#include "errors.hpp"


static err_t read_points_count(points_t &points, FILE *datafile)
{
    size_t tmp_count = 0;

    if ((fscanf(datafile, "%zu", &tmp_count)) != 1)
        return ERR_FREAD;

    if (tmp_count < 2)
        return ERR_PCOUNT;

    points.count = tmp_count;

    return SUCCESS;
}

static err_t allocate_points(points_t &points)
{
    point_t *tmp_data = (point_t *)malloc(points.count * sizeof(point_t));
    if (tmp_data == NULL)
        return ERR_ALLOC;

    points.data = tmp_data;

    return SUCCESS;
}

static err_t read_points(points_t &points, FILE *datafile)
{
    err_t rc = SUCCESS;
    for (size_t i = 0; rc == SUCCESS && i < points.count; i++)
        rc = read_point(points.data[i], datafile);

    rc = read_point(points.center, datafile);  // read center of all points

    return rc;
}

err_t translate_points(points_t &points, const translate_t &tr_data)
{
    for (size_t i = 0; i < points.count; i++)
        translate_point(points.data[i], tr_data);

    translate_point(points.center, tr_data);

    return SUCCESS;
}

point_t& get_center(points_t &points)
{
    return points.center;
}

err_t scale_points(points_t &points, const scale_t &sc_data)
{
    for (size_t i = 0; i < points.count; i++)
        scale_point(points.data[i], sc_data);

    return SUCCESS;
}

err_t rotate_points(points_t &points, const rotate_t &rot_data)
{
    for (size_t i = 0; i < points.count; i++)
        rotate_point(points.data[i], rot_data);

    return SUCCESS;
}

err_t load_points(points_t &points, FILE *datafile)
{
    err_t rc = SUCCESS;

    if ((rc = read_points_count(points, datafile)) != SUCCESS)
        return rc;

    if ((rc = allocate_points(points)) != SUCCESS)
        return rc;

    if ((rc = read_points(points, datafile)) != SUCCESS)
        destruct_points(points);

    return rc;
}

void init_points(points_t &points)
{
    points.count = 0;
    points.data = NULL;
}

bool points_are_defined(const points_t &points)
{
    return points.data != NULL;
}

void destruct_points(points_t &points)
{
    if (points.data != NULL)
    {
        free(points.data);
        init_points(points);
    }
}