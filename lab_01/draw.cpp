#include "draw.h"

void draw_line(const canvas_t &canvas,
               const vector2_t &vertex_1, const vector2_t &vertex_2)
{
    canvas.scene->addLine(vertex_1.x, vertex_1.y, vertex_2.x, vertex_2.y);
}

ret_code_t clear_canvas(const canvas_t &canvas)
{
    if (canvas.scene == NULL)
    {
        return ERR_NULL_PTR;
    }

    canvas.scene->clear();

    return EXIT_OK;
}

ret_code_t draw_connection(const canvas_t &canvas, const connection_t &connection,
                           const projected_vertices_t &projected_vertices)
{
    size_t vertex_1_index;
    size_t vertex_2_index;
    vector2_t projected_vertex_1;
    vector2_t projected_vertex_2;

    if (projected_vertices.length == 0)
    {
        return ERR_NO_DATA;
    }

    if (projected_vertices.data == NULL)
    {
        return ERR_NULL_PTR;
    }

    vertex_1_index = connection.vertices[0];
    vertex_2_index = connection.vertices[1];

    projected_vertex_1 = projected_vertices.data[vertex_1_index];
    projected_vertex_2 = projected_vertices.data[vertex_2_index];

    draw_line(canvas, projected_vertex_1, projected_vertex_2);

    return EXIT_OK;
}


ret_code_t check_connection(const connection_t &connection, size_t vertices_length)
{
    if (connection.vertices[0] >= vertices_length || connection.vertices[1] >= vertices_length)
        return ERR_ARRAY_OVERFLOW;
    return EXIT_OK;
}

ret_code_t check_connections(const connections_t &connections, size_t vertices_length)
{
    ret_code_t rc;

    if (connections.length == 0)
    {
        return ERR_NO_DATA;
    }

    if (connections.data == NULL)
    {
        return ERR_NULL_PTR;
    }

    for (size_t i = 0; i < connections.length; i++)
    {
        rc = check_connection(connections.data[i], vertices_length);
        if (rc != EXIT_OK)
            break;
    }

    return rc;
}

ret_code_t draw_connections(const canvas_t &canvas, const connections_t &connections,
                            const projected_vertices_t &projected_vertices)
{
    ret_code_t rc;

    if (!projected_vertices.length || !connections.length)
    {
        return ERR_NO_DATA;
    }

    if (connections.data == NULL || projected_vertices.data == NULL)
    {
        return ERR_NULL_PTR;
    }

    rc = check_connections(connections, projected_vertices.length);

    for (size_t i = 0; rc == EXIT_OK && i < connections.length; i++)
    {
        rc = draw_connection(canvas, connections.data[i], projected_vertices);
    }

    return rc;
}

ret_code_t draw_model(model_t &model, const canvas_t &canvas)
{
    ret_code_t rc;

    rc = update_projected_vertices(model.projected_vertices, model.global_vertices);

    if (rc == EXIT_OK)
    {
        rc = clear_canvas(canvas);
    }

    if (rc == EXIT_OK)
    {
        rc = draw_connections(canvas, model.connections, model.projected_vertices);
    }

    return rc;
}
