#include <cmath>
#include "errors.hpp"

#include "point.hpp"


err_t read_point(point_t &p, FILE *datafile)
{
    if (fscanf(datafile, "%lf %lf %lf", &p.x, &p.y, &p.z) != 3)
        return ERR_FREAD;

    return SUCCESS;
}

double to_rad(const double angle)
{
    return angle * M_PI / 180.0;
}

void translate_point(point_t &point, const translate_t &tr_data)
{
    point.x += tr_data.dx;
    point.y += tr_data.dy;
    point.z += tr_data.dz;
}

void scale_point(point_t &point, const scale_t &sc_data)
{
    point.x *= sc_data.kx;
    point.y *= sc_data.ky;
    point.z *= sc_data.kz;
}

static void rotate_x_axis(point_t &point, const double angle)
{
    double cos_theta = cos(to_rad(angle));
    double sin_theta = sin(to_rad(angle));
    
    double temp_y = point.y;
    point.y = point.y * cos_theta - point.z * sin_theta;
    point.z = temp_y * sin_theta + point.z * cos_theta;
}

static void rotate_y_axis(point_t &point, const double angle)
{
    double cos_theta = cos(to_rad(angle));
    double sin_theta = sin(to_rad(angle));

    double temp_x = point.x;
    point.x = point.x * cos_theta + point.z * sin_theta;
    point.z = -temp_x * sin_theta + point.z * cos_theta;
}

static void rotate_z_axis(point_t &point, const double angle)
{
    double cos_theta = cos(to_rad(angle));
    double sin_theta = sin(to_rad(angle));

    double temp_x = point.x;
    point.x = point.x * cos_theta - point.y * sin_theta;
    point.y = temp_x * sin_theta + point.y * cos_theta;
}

void rotate_point(point_t &point, const rotate_t &rot_data)
{
    rotate_x_axis(point, rot_data.ax);
    rotate_y_axis(point, rot_data.ay);
    rotate_z_axis(point, rot_data.az);
}
