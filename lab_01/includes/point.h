#ifndef _POINT_H_
#define _POINT_H_

typedef struct
{
    double x;
    double y;
    double z;
} point_t;

typedef struct
{
    double dx;
    double dy;
    double dz;
} translate_t;

typedef struct
{
    double kx;
    double ky;
    double kz;
} scale_t;

typedef struct
{
    double ax;
    double ay;
    double az;
} rotate_t;

void translate(point_t &point, const translate_t &tr_data);

void scale(point_t &point, const scale_t &sc_data);

void rotate(point_t &point, const rotate_t &rot_data);

#endif // _POINT_H_