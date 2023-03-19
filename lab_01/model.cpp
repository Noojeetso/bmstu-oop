#include "model.h"

model_t init_model()
{
    model_t model;

    pivot_init(model.pivot);
    vertices_init(model.local_vertices);
    vertices_init(model.global_vertices);
    vertices_init(model.projected_vertices);
    connections_init(model.connections);

    return model;
}

ret_code_t free_model(model_t &model)
{
    free_vertices(model.local_vertices);
    free_vertices(model.global_vertices);
    free_projected_vertices(model.projected_vertices);
    free_connections(model.connections);
    model = init_model();

    return EXIT_OK;
}

ret_code_t allocate_extra_vertices(vertices_t &global_vertices, projected_vertices_t &projected_vertices, const vertices_t &local_vertices)
{
    ret_code_t rc;
    size_t length;

    if (local_vertices.length == 0)
    {
        return ERR_NO_DATA;
    }

    if (local_vertices.data == NULL)
    {
        return ERR_NULL_PTR;
    }

    length = local_vertices.length;

    rc = vertices_allocate(global_vertices, length);

    if (rc == EXIT_OK)
    {
        rc  = projected_vertices_allocate(projected_vertices, length);
    }

    if (rc != EXIT_OK)
    {
        free_vertices(global_vertices);
        free_projected_vertices(projected_vertices);
    }

    return rc;
}

ret_code_t model_from_file(model_t &model, FILE *file)
{
    ret_code_t rc;

    if (file == NULL)
    {
        return ERR_NULL_PTR;
    }

    rc = read_vertices(model.local_vertices, file);

    if (rc == EXIT_OK)
    {
        rc = allocate_extra_vertices(model.global_vertices, model.projected_vertices, model.local_vertices);
    }

    if (rc != EXIT_OK)
    {
        free_vertices(model.local_vertices);
    }

    if (rc == EXIT_OK)
    {
        rc = read_connections(model.connections, file);
    }

    return rc;
}

ret_code_t load_model(model_t &model, const filename_t filename)
{
    model_t tmp_model;
    ret_code_t rc;
    FILE *file;

    if (filename == NULL)
    {
        return ERR_NULL_PTR;
    }

    tmp_model = init_model();

    rc = file_open_read(&file, filename);

    if (rc == EXIT_OK)
    {
        rc = model_from_file(tmp_model, file);
    }

    if (rc == EXIT_OK)
    {
        free_model(model);
        model = tmp_model;
    }

    file_close(file);

    return rc;
}

ret_code_t update_global_coordinates(vertices_t &global_vertices, const pivot_t &pivot, const vertices_t &local_vertices)
{
    if (local_vertices.length == 0)
    {
        return ERR_NO_DATA;
    }

    if (local_vertices.length != global_vertices.length)
    {
        return ERR_DATA_CORRUPTED;
    }

    for (size_t i = 0; i < local_vertices.length; i++)
    {
        transform_to_global(global_vertices.data[i], pivot, local_vertices.data[i]);
    }

    return EXIT_OK;
}

ret_code_t model_translate(model_t &model, const vector3_t &translation)
{
    pivot_translate(model.pivot, translation);
    return translate_vertices(model.global_vertices, translation);
}

ret_code_t model_scale(model_t &model, double factor)
{
    ret_code_t rc;

    rc = scale_vertices(model.local_vertices, factor);

    if (rc == EXIT_OK)
    {
        rc = update_global_coordinates(model.global_vertices, model.pivot, model.local_vertices);
    }

    return rc;
}

ret_code_t model_rotate(model_t &model, const vector3_t &rotation)
{
    pivot_rotate(model.pivot, rotation);
    return update_global_coordinates(model.global_vertices, model.pivot, model.local_vertices);
}
