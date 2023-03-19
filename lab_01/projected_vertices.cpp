#include "projected_vertices.h"

void vertices_init(projected_vertices_t &projected_vertices)
{
    projected_vertices.data = NULL;
    projected_vertices.length = 0;
}

ret_code_t projected_vertices_allocate(projected_vertices_t &projected_vertices, size_t length)
{
    projected_vertices.data = (vector2_t *)malloc(length * sizeof(vector2_t));
    if (projected_vertices.data == NULL)
    {
        return ERR_NO_MEMORY;
    }

    projected_vertices.length = length;

    return EXIT_OK;
}

void free_projected_vertices(projected_vertices_t &projected_vertices)
{
    free(projected_vertices.data);
    vertices_init(projected_vertices);
}

void project_to_origin(vector2_t &vertex_out, const vector3_t &vertex_in)
{
    vertex_out.x = vertex_in.x;
    vertex_out.y = vertex_in.y;
}

ret_code_t update_projected_vertice(vector2_t &projected_vertex, const vector3_t &vertex)
{
    project_to_origin(projected_vertex, vertex);
    return EXIT_OK;
}

ret_code_t update_projected_vertices(projected_vertices_t &projected_vertices, const vertices_t &vertices)
{
    ret_code_t rc;

    if (vertices.length == 0)
    {
        return ERR_NO_DATA;
    }

    if (projected_vertices.data == NULL || vertices.data == NULL)
    {
        return ERR_NULL_PTR;
    }

    if (projected_vertices.length == 0 || projected_vertices.length != vertices.length)
    {
        return ERR_DATA_CORRUPTED;
    }

    rc = update_projected_vertice(projected_vertices.data[0], vertices.data[0]);

    for (size_t i = 1; rc == EXIT_OK && i < vertices.length; i++)
    {
        rc = update_projected_vertice(projected_vertices.data[i], vertices.data[i]);
    }

    return rc;
}
