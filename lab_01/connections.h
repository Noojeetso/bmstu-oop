#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <cstdlib>
#include <stdio.h>
#include <files.h>
#include "errors.h"

struct connection_t
{
    size_t vertices[2];
};

struct connections_t
{
    connection_t *data;
    size_t length;
    size_t max_length;
};

ret_code_t connections_allocate(connections_t &connections);

ret_code_t add_connection(connections_t &connection_arr, const connection_t &connection);

void free_connections(connections_t &connections);

void connections_init(connections_t &connections);

ret_code_t read_connections(connections_t &connections, FILE *file);

#endif // CONNECTIONS_H
