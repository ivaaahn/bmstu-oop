#include "point.h"

double to_rad(const double angle)
{
    return angle * M_PI / 180.0;
}

static err_t read_amount(points_t &points, FILE *datafile)
{
    size_t tmp_count = 0;

    if ((fscanf(datafile, "%zu", &tmp_count)) != 1)
    {
        return FREAD_ERR;
    }

    if (tmp_count < 2)
    {
        return PCOUNT_ERR;
    }

    points.count = tmp_count;

    return OK;
}

static err_t read_points(point_t *const points, const size_t size, FILE *datafile)
{
    for (size_t i = 0; i < size; i++)
    {
        if ((fscanf(datafile, "%lf %lf %lf", &points[i].x, &points[i].y, &points[i].z)) != 3)
        {
            return FREAD_ERR;
        }
    }

    return OK;
}

static err_t allocate_points(points_t &points)
{
    point_t *temp_data = (point_t *)malloc(points.count * sizeof(point_t));
    if (!temp_data)
    {
        return ALLOC_ERR;
    }

    points.data = temp_data;

    return OK;
}

void free_points(const points_t &points)
{
    free(points.data);
}

err_t points_reader(points_t &points, FILE *datafile)
{
    err_t rc = OK;

    if ((rc = read_amount(points, datafile)) != OK)
    {
        return rc;
    }

    if ((rc = allocate_points(points)) != OK)
    {
        return rc;
    }

    if ((rc = read_points(points.data, points.count, datafile)) != OK)
    {
        free_points(points);
    }

    return rc;
}

void translate_point(point_t &point, const translate_data_t &values)
{
    point.x += values.dx;
    point.y += values.dy;
    point.z += values.dz;
}

void scale_point(point_t &point, const scale_data_t &values)
{
    point.x *= values.kx;
    point.y *= values.ky;
    point.z *= values.kz;
}

void rotate_x_axis(point_t &point, const double theta)
{
    double cos_theta = cos(to_rad(theta));
    double sin_theta = sin(to_rad(theta));
    double temp_y = point.y;

    point.y = point.y * cos_theta - point.z * sin_theta;
    point.z = temp_y * sin_theta + point.z * cos_theta;
}

void rotate_y_axis(point_t &point, const double theta)
{
    double cos_theta = cos(to_rad(theta));
    double sin_theta = sin(to_rad(theta));
    double temp_x = point.x;

    point.x = point.x * cos_theta + point.z * sin_theta;
    point.z = -temp_x * sin_theta + point.z * cos_theta;
}

void rotate_z_axis(point_t &point, const double theta)
{
    double cos_theta = cos(to_rad(theta));
    double sin_theta = sin(to_rad(theta));
    double temp_x = point.x;

    point.x = point.x * cos_theta - point.y * sin_theta;
    point.y = temp_x * sin_theta + point.y * cos_theta;
}
