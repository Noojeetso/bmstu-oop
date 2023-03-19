#ifndef VERTICES_H
#define VERTICES_H

#include "files.h"
#include "geometry.h"
#include "errors.h"

struct vertices_t
{
    vector3_t *data;
    size_t length;
};

ret_code_t vertices_allocate(vertices_t &vertices, size_t length);

void vertices_init(vertices_t &vertices);

void free_vertices(vertices_t &vertices);

ret_code_t read_vertices(vertices_t &vertices, FILE *file);

ret_code_t scale_vertices(vertices_t &local_vertices, double factor);

ret_code_t translate_vertices(vertices_t &vertices, const vector3_t &translation);

#endif // VERTICES_H
