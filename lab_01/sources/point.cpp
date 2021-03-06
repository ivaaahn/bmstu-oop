#include "point.h"

double to_rad(const double angle)
{
    return angle * M_PI / 180.0;
}


// static err_t read_amount(pdata_t &points, FILE *f)
// {
//     if ((fscanf(f, "%d", &points.size)) != 1)
//     {
//         return READ_ERR;
//     }

//     if (points.size < 2)
//     {
//         return PCOUNT_ERR;
//     }

//     return OK;
// }

// static err_t read_points(point_t *const array, const int size, FILE *f)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if ((fscanf(f, "%lf %lf %lf", &array[i].x, &array[i].y, &array[i].z)) != 3)
//         {
//             return READ_ERR;
//         }
//     }

//     return OK;
// }

// static err_t allocate_links(pdata_t &points)
// {
//     point_t *temp_array = (point_t *)malloc(points.size * sizeof(point_t));

//     if (temp_array == NULL)
//     {
//         return ALLOC_ERR;
//     }

//     points.array = temp_array;

//     return OK;
// }

// void free_points(const pdata_t &points)
// {
//     if (points.array != NULL)
//     {
//         free(points.array);
//     }
// }

// err_t handle_points(pdata_t &points, FILE *f)
// {
//     err_t error_code = OK;

//     if ((error_code = read_amount(points, f)))
//     {
//         return error_code;
//     }

//     if ((error_code = allocate_links(points)))
//     {
//         return error_code;
//     }

//     if ((error_code = read_points(points.array, points.size, f)))
//     {
//         free_points(points);
//     }

//     return error_code;
// }

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

void turn_x(point_t &point, const double theta)
{
    double cos_theta = cos(to_rad(theta));
    double sin_theta = sin(to_rad(theta));
    double temp_y = point.y;

    point.y = point.y * cos_theta - point.z * sin_theta;
    point.z = temp_y * sin_theta + point.z * cos_theta;
}

void turn_y(point_t &point, const double theta)
{
    double cos_theta = cos(to_rad(theta));
    double sin_theta = sin(to_rad(theta));
    double temp_x = point.x;

    point.x = point.x * cos_theta + point.z * sin_theta;
    point.z = -temp_x * sin_theta + point.z * cos_theta;
}

void turn_z(point_t &point, const double theta)
{
    double cos_theta = cos(to_rad(theta));
    double sin_theta = sin(to_rad(theta));
    double temp_x = point.x;

    point.x = point.x * cos_theta - point.y * sin_theta;
    point.y = temp_x * sin_theta + point.y * cos_theta;
}