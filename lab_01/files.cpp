#include "files.h"

ret_code_t file_open_read(FILE **file, const char *filename)
{
    if (file == NULL)
    {
        return ERR_NULL_PTR;
    }

    if (filename == NULL)
    {
        return ERR_FILE_NAME;
    }

    *file = fopen(filename, READ_MODE);
    if (*file == NULL)
    {
        return ERR_FILE_OPEN;
    }

    return EXIT_OK;
}

ret_code_t file_close(FILE *file)
{
    int rc;

    if (file == NULL)
    {
        return ERR_NULL_PTR;
    }

    rc = fclose(file);
    if (rc != EXIT_SUCCESS)
    {
        return ERR_FILE_CLOSE;
    }

    return EXIT_OK;
}

ret_code_t read_unsigned_long(unsigned long &i, FILE *file)
{
    int rc;

    if (file == NULL)
    {
        return ERR_NULL_PTR;
    }

    rc = fscanf(file, "%lu", &i);
    if (rc != 1)
    {
        return ERR_FILE_STRUCTURE;
    }

    return EXIT_OK;
}

ret_code_t read_double(double &lf, FILE *file)
{
    int rc;

    if (file == NULL)
    {
        return ERR_NULL_PTR;
    }

    rc = fscanf(file, "%lf", &lf);
    if (rc != 1)
    {
        return ERR_FILE_STRUCTURE;
    }

    return EXIT_OK;
}
