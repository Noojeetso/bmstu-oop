#ifndef PIVOT_H
#define PIVOT_H

#include "geometry.h"
#include "bivector.h"
#include "math_impl.h"
#include "errors.h"

struct pivot_t
{
    vector3_t center;
    vector3_t x_axis;
    vector3_t y_axis;
    vector3_t z_axis;
    matrix3x3_t transformation_matrix;
};

struct translation_t
{
    double dx;
    double dy;
    double dz;
};

struct scale_t
{
    double kx;
    double ky;
    double kz;
};

struct rotation_t
{
    double x;
    double y;
    double z;
};

void pivot_init(pivot_t &pivot);

void transform_to_global(vector3_t &global_coords, const pivot_t &pivot, const vector3_t &local_coords);

void update_pivot_transformation_matrix(pivot_t &pivot);

void pivot_translate(pivot_t &pivot, const vector3_t &translation);

void pivot_rotate(pivot_t &pivot, const vector3_t &rotation);

#endif // PIVOT_H
