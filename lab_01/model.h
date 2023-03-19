#ifndef MODEL_H
#define MODEL_H

#include <cstdlib>
#include "files.h"
#include "projected_vertices.h"
#include "pivot.h"
#include "connections.h"
#include "errors.h"

struct model_t
{
    pivot_t pivot;
    vertices_t local_vertices;
    vertices_t global_vertices;
    projected_vertices_t projected_vertices;
    connections_t connections;
};

model_t init_model();

ret_code_t free_model(model_t &model);

ret_code_t load_model(model_t &model, const filename_t filename);

ret_code_t model_scale(model_t &model, double factor);

ret_code_t model_translate(model_t &model, const vector3_t &translation);

ret_code_t model_rotate(model_t &model, const vector3_t &rotation);

#endif // MODEL_H
