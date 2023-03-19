#include "geometry.h"

void init_vector(vector3_t &vector)
{
    vector.x = 0;
    vector.y = 0;
    vector.z = 0;
}

void add_to_vector(vector3_t &vector_to, const vector3_t &vector_which)
{
    vector_to.x += vector_which.x;
    vector_to.y += vector_which.y;
    vector_to.z += vector_which.z;
}

void sum_vectors(vector3_t &result, const vector3_t &vector_a, const vector3_t &vector_b)
{
    result.x = vector_a.x + vector_b.x;
    result.y = vector_a.y + vector_b.y;
    result.z = vector_a.z + vector_b.z;
}

void subtract_vectors(vector3_t &result, const vector3_t &vector_from, const vector3_t &vector_which)
{
    result.x = vector_from.x - vector_which.x;
    result.y = vector_from.y - vector_which.y;
    result.z = vector_from.z - vector_which.z;
}

void vector_scalar_multiply(vector3_t &vector, double factor)
{
    vector.x *= factor;
    vector.y *= factor;
    vector.z *= factor;
}

double get_inner_product(const vector3_t &vector_a, const vector3_t &vector_b)
{
    return vector_a.x * vector_b.x + vector_a.y + vector_b.y + vector_a.z * vector_b.z;
}

double get_vector_length(const vector3_t &vector)
{
    return get_sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

void multiply_matrix_by_vector(vector3_t &result, const matrix3x3_t &matrix, const vector3_t &vector)
{
    result.x = vector.x * matrix.data[0][0] +
               vector.y * matrix.data[0][1] +
               vector.z * matrix.data[0][2];

    result.y = vector.x * matrix.data[1][0] +
               vector.y * matrix.data[1][1] +
               vector.z * matrix.data[1][2];

    result.z = vector.x * matrix.data[2][0] +
               vector.y * matrix.data[2][1] +
               vector.z * matrix.data[2][2];
}
