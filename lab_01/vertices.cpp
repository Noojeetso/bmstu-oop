#include "vertices.h"

void vertices_init(vertices_t &vertices)
{
    vertices.data = NULL;
    vertices.length = 0;
}

ret_code_t vertices_allocate(vertices_t &vertices, const size_t length)
{
    vertices.data = (vector3_t *)malloc(length * sizeof(vector3_t));
    if (vertices.data == NULL)
    {
        return ERR_NO_MEMORY;
    }

    vertices.length = length;

    return EXIT_OK;
}

void free_vertices(vertices_t &vertices)
{
    free(vertices.data);
    vertices_init(vertices);
}

ret_code_t read_vertex(vector3_t &vertex, FILE *file)
{
    ret_code_t rc;
    vector3_t temp_vector;

    rc = read_double(temp_vector.x, file);

    if (rc == EXIT_OK)
    {
        rc = read_double(temp_vector.y, file);
    }

    if (rc == EXIT_OK)
    {
        rc = read_double(temp_vector.z, file);
    }

    if (rc == EXIT_OK)
    {
        vertex = temp_vector;
    }

    return rc;
}

ret_code_t read_vertices_data(vertices_t &vertices, FILE *file)
{
    ret_code_t rc;

    if (vertices.length == 0)
    {
        return ERR_DATA_CORRUPTED;
    }

    if (vertices.data == NULL)
    {
        return ERR_NULL_PTR;
    }

    rc = read_vertex(vertices.data[0], file);

    for (size_t i = 1; rc == EXIT_OK && i < vertices.length; i++)
    {
        rc = read_vertex(vertices.data[i], file);
    }

    return rc;
}

ret_code_t read_vertices(vertices_t &vertices, FILE *file)
{
    ret_code_t rc;
    size_t length;

    rc = read_unsigned_long(length, file);

    if (rc == EXIT_OK)
    {
        rc = vertices_allocate(vertices, length);
    }

    if (rc == EXIT_OK)
    {
        rc = read_vertices_data(vertices, file);
    }

    if (rc != EXIT_OK)
    {
        free_vertices(vertices);
    }

    return rc;
}

ret_code_t read_vertices_length(vertices_t &vertices, FILE *file)
{
    return read_unsigned_long(vertices.length, file);
}

ret_code_t scale_vertices(vertices_t &local_vertices, double factor)
{
    if (local_vertices.length == 0)
    {
        return ERR_NO_DATA;
    }

    if (local_vertices.data == NULL)
    {
        return ERR_NULL_PTR;
    }

    for (size_t i = 0; i < local_vertices.length; i++)
    {
        vector_scalar_multiply(local_vertices.data[i], factor);
    }

    return EXIT_OK;
}

ret_code_t translate_vertices(vertices_t &vertices, const vector3_t &translation)
{
    if (vertices.length == 0)
    {
        return ERR_NO_DATA;
    }

    if (vertices.data == NULL)
    {
        return ERR_NULL_PTR;
    }

    for (size_t i = 0; i < vertices.length; i++)
    {
        add_to_vector(vertices.data[i], translation);
    }

    return EXIT_OK;
}
