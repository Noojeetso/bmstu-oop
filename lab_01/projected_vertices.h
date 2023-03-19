#ifndef PROJECTED_VERTICES_H
#define PROJECTED_VERTICES_H

#include "vertices.h"
#include "geometry.h"
#include "errors.h"

struct projected_vertices_t
{
    vector2_t *data;
    size_t length;
};

ret_code_t projected_vertices_allocate(projected_vertices_t &projected_vertices, size_t length);

void vertices_init(projected_vertices_t &projected_vertices);

void free_projected_vertices(projected_vertices_t &projected_vertices);

ret_code_t update_projected_vertices(projected_vertices_t &projected_vertices, const vertices_t &vertices);

#endif // PROJECTED_VERTICES_H
