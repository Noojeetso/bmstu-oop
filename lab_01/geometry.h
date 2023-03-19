#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "math_impl.h"

struct vector2_t
{
    double x;
    double y;
};

struct vector3_t
{
    double x;
    double y;
    double z;
};

struct matrix3x3_t
{
    double data[3][3];
};

void init_vector(vector3_t &vector);

void add_to_vector(vector3_t &vector_to, const vector3_t &vector_which);

void sum_vectors(vector3_t &result, const vector3_t &vector_a, const vector3_t &vector_b);

void subtract_vectors(vector3_t &result, const vector3_t &vector_from, const vector3_t &vector_which);

void vector_scalar_multiply(vector3_t &vector, double factor);

double get_inner_product(const vector3_t &vector_a, const vector3_t &vector_b);

double get_vector_length(const vector3_t &vector);

void multiply_matrix_by_vector(vector3_t &result, const matrix3x3_t &matrix, const vector3_t &vector);

#endif // GEOMETRY_H
