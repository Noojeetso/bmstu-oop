#include "connections.h"

void connections_init(connections_t &connections)
{
    connections.data = NULL;
    connections.length = 0;
}

ret_code_t connections_allocate(connections_t &connections)
{
    connections.data = (connection_t *)malloc(connections.length * sizeof(connection_t));
    if (connections.data == NULL)
    {
        return ERR_NO_MEMORY;
    }

    return EXIT_OK;
}

void free_connections(connections_t &connections)
{
    free(connections.data);
    connections_init(connections);
}

ret_code_t add_connection(connections_t &connections, const connection_t &connection)
{
    if (connections.length == connections.max_length)
    {
        return ERR_ARRAY_OVERFLOW;
    }

    connections.data[connections.length] = connection;
    connections.length++;

    return EXIT_OK;
}

ret_code_t read_connections_length(connections_t &connections, FILE *file)
{
    return read_unsigned_long(connections.length, file);
}

ret_code_t read_connection(connection_t &connection, FILE *file)
{
    ret_code_t rc;

    rc = read_unsigned_long(connection.vertices[0], file);

    if (rc == EXIT_OK)
    {
        rc = read_unsigned_long(connection.vertices[1], file);
    }

    return rc;
}

ret_code_t read_connections_data(connections_t &connections, FILE *file)
{
    ret_code_t rc;

    if (connections.length == 0)
    {
        return ERR_DATA_CORRUPTED;
    }

    if (connections.data == NULL)
    {
        return ERR_NULL_PTR;
    }

    rc = read_connection(connections.data[0], file);

    for (size_t i = 1; rc == EXIT_OK && i < connections.length; i++)
    {
        rc = read_connection(connections.data[i], file);
    }

    return rc;
}

ret_code_t read_connections(connections_t &connections, FILE *file)
{
    ret_code_t rc;

    rc = read_connections_length(connections, file);

    if (rc == EXIT_OK)
    {
        rc = connections_allocate(connections);
    }

    if (rc == EXIT_OK)
    {
        rc = read_connections_data(connections, file);
    }

    if (rc != EXIT_OK)
    {
        free_connections(connections);
    }

    return rc;
}
