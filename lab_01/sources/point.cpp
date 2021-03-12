#include <cmath>

#include "point.hpp"
#include "errors.hpp"


double to_rad(const double angle)
{
    return angle * M_PI / 180.0;
}

err_t read_point(point_t &p, FILE *datafile)
{
    if (fscanf(datafile, "%lf %lf %lf", &p.x, &p.y, &p.z) != 3)
        return ERR_FREAD;

    return SUCCESS;
}

void translate_point(point_t &p, const translate_t &tr_data)
{
    p.x += tr_data.x;
    p.y += tr_data.y;
    p.z += tr_data.z;
}

void scale_point(point_t &p, point_t &c, const scale_t &sc_data)
{
    p.x = c.x + sc_data.x * (-c.x + p.x);
    p.y = c.y + sc_data.y * (-c.y + p.y);
    p.z = c.y + sc_data.z * (-c.z + p.z);
}

static void rotate_x_axis(point_t &p, point_t &c, const double angle)
{
    double cos_theta = cos(to_rad(angle));
    double sin_theta = sin(to_rad(angle));

    double temp_y = p.y;
    p.y = c.y + (-c.y + p.y) * cos_theta - (-c.z + p.z) * sin_theta;
    p.z = c.z + (-c.z + temp_y) * sin_theta + (-c.z + p.z) * cos_theta;
}

static void rotate_y_axis(point_t &p, point_t &c, const double angle)
{
    double cos_theta = cos(to_rad(angle));
    double sin_theta = sin(to_rad(angle));

    double temp_x = p.x;
    p.x = c.x + (-c.x + p.x) * cos_theta - (-c.z + p.z) * sin_theta;
    p.z = c.z + (-c.x + temp_x) * sin_theta + (-c.z + p.z) * cos_theta;
}

static void rotate_z_axis(point_t &p, point_t &c, const double angle)
{
    double cos_theta = cos(to_rad(angle));
    double sin_theta = sin(to_rad(angle));

    double temp_x = p.x;
    p.x = c.x + (-c.x + p.x) * cos_theta - (-c.y + p.y) * sin_theta;
    p.y = c.y + (-c.x + temp_x) * sin_theta + (-c.y + p.y) * cos_theta;
}

void rotate_point(point_t &point, point_t &center, const rotate_t &rot_data)
{
    rotate_x_axis(point, center, rot_data.x);
    rotate_y_axis(point, center, rot_data.y);
    rotate_z_axis(point, center, rot_data.z);
}
