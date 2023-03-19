#include "bivector.h"

rotor3_t get_rotor(const bivector3_t &bivector, double angle_degrees)
{
    rotor3_t rotor;

    double sina = get_sin(angle_degrees / 2.f);
    rotor.scalar_part = get_cos(angle_degrees / 2.f);
    rotor.area_01 = sina * bivector.area_01;
    rotor.area_02 = sina * bivector.area_02;
    rotor.area_12 = sina * bivector.area_12;

    return rotor;
}

bivector3_t get_wedge(const vector3_t &vector_a, const vector3_t &vector_b)
{
    bivector3_t result;

    result.area_01 = vector_a.x * vector_b.y - vector_a.y * vector_b.x;
    result.area_02 = vector_a.x * vector_b.z - vector_a.z * vector_b.x;
    result.area_12 = vector_a.y * vector_b.z - vector_a.z * vector_b.y;

    return result;
}

vector3_t rotate(const vector3_t &vector, const rotor3_t &rotor)
{
    vector3_t q;
    vector3_t r;
    float q012;

    // q = vector * rotor
    q.x = rotor.scalar_part * vector.x - rotor.area_01 * vector.y - rotor.area_02 * vector.z;
    q.y = rotor.scalar_part * vector.y + rotor.area_01 * vector.x - rotor.area_12 * vector.z;
    q.z = rotor.scalar_part * vector.z + rotor.area_02 * vector.x + rotor.area_12 * vector.y;

    // trivector part
    q012 = rotor.area_01 * vector.z - rotor.area_02 * vector.y + rotor.area_12 * vector.x;

    // r = rotor_flipped * q
    r.x = rotor.scalar_part * q.x - rotor.area_01 * q.y - rotor.area_02 * q.z + rotor.area_12 * q012;
    r.y = rotor.scalar_part * q.y + rotor.area_01 * q.x - rotor.area_02 * q012 - rotor.area_12 * q.z;
    r.z = rotor.scalar_part * q.z + rotor.area_01 * q012 + rotor.area_02 * q.x + rotor.area_12 * q.y;

    // trivector part is always zero

    return r;
}
