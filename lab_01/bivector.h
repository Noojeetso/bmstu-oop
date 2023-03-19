#ifndef BIVECTOR_H
#define BIVECTOR_H

#include "geometry.h"

struct bivector3_t
{
    double area_01;
    double area_02;
    double area_12;
};

struct rotor3_t
{
    double scalar_part;
    double area_01;
    double area_02;
    double area_12;
};

vector3_t rotate_vector_around_axis(const vector3_t &source_vector, const bivector3_t &bivector);

rotor3_t get_rotor(const bivector3_t &bivector, double angle_degrees);

bivector3_t get_wedge(const vector3_t &vector_a, const vector3_t &vector_b);

vector3_t rotate(const vector3_t &vector, const rotor3_t &rotor);

#endif // BIVECTOR_H
