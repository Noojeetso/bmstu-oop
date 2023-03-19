#include "pivot.h"

void pivot_init(pivot_t &pivot)
{
    pivot.center = {0, 0, 0};
    pivot.x_axis = {1, 0, 0};
    pivot.y_axis = {0, 1, 0};
    pivot.z_axis = {0, 0, 1};
    update_pivot_transformation_matrix(pivot);
}

void update_pivot_transformation_matrix(pivot_t &pivot)
{
    pivot.transformation_matrix.data[0][0] = pivot.x_axis.x;
    pivot.transformation_matrix.data[1][0] = pivot.x_axis.y;
    pivot.transformation_matrix.data[2][0] = pivot.x_axis.z;

    pivot.transformation_matrix.data[0][1] = pivot.y_axis.x;
    pivot.transformation_matrix.data[1][1] = pivot.y_axis.y;
    pivot.transformation_matrix.data[2][1] = pivot.y_axis.z;

    pivot.transformation_matrix.data[0][2] = pivot.z_axis.x;
    pivot.transformation_matrix.data[1][2] = pivot.z_axis.y;
    pivot.transformation_matrix.data[2][2] = pivot.z_axis.z;
}

void transform_to_global(vector3_t &global_coords, const pivot_t &pivot, const vector3_t &local_coords)
{
    vector3_t local_offset;
    multiply_matrix_by_vector(local_offset, pivot.transformation_matrix, local_coords);
    sum_vectors(global_coords, pivot.center, local_offset);
}

void pivot_translate(pivot_t &pivot, const vector3_t &translation)
{
    add_to_vector(pivot.center, translation);
    update_pivot_transformation_matrix(pivot);
}

void pivot_rotate_x(pivot_t &pivot, double angle_degrees)
{
    rotor3_t rotor;
    bivector3_t bivector = get_wedge(pivot.y_axis, pivot.z_axis);
    rotor = get_rotor(bivector, angle_degrees);
    pivot.y_axis = rotate(pivot.y_axis, rotor);
    pivot.z_axis = rotate(pivot.z_axis, rotor);
}

void pivot_rotate_y(pivot_t &pivot, double angle_degrees)
{
    rotor3_t rotor;
    bivector3_t bivector = get_wedge(pivot.x_axis, pivot.z_axis);
    rotor = get_rotor(bivector, angle_degrees);
    pivot.x_axis = rotate(pivot.x_axis, rotor);
    pivot.z_axis = rotate(pivot.z_axis, rotor);
}

void pivot_rotate_z(pivot_t &pivot, double angle_degrees)
{
    rotor3_t rotor;
    bivector3_t bivector = get_wedge(pivot.x_axis, pivot.y_axis);
    rotor = get_rotor(bivector, angle_degrees);
    pivot.x_axis = rotate(pivot.x_axis, rotor);
    pivot.y_axis = rotate(pivot.y_axis, rotor);
}

void pivot_rotate(pivot_t &pivot, const vector3_t &rotation)
{
    pivot_rotate_x(pivot, rotation.x);
    pivot_rotate_y(pivot, rotation.y);
    pivot_rotate_z(pivot, rotation.z);
    update_pivot_transformation_matrix(pivot);
}
