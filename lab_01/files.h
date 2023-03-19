#ifndef FILES_H
#define FILES_H

#include <cstdlib>
#include <cstdio>
#include "errors.h"

#define READ_MODE "r"

typedef const char *filename_t;

ret_code_t file_open_read(FILE **file, const char *filename);

ret_code_t file_close(FILE *file);

ret_code_t read_unsigned_long(unsigned long &i, FILE *file);

ret_code_t read_double(double &lf, FILE *file);

#endif // FILES_H
