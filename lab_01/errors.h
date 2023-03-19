#ifndef ERRORS_H
#define ERRORS_H

#include <QMessageBox>

typedef enum ret_code
{
    EXIT_OK,
    ERR_NO_MEMORY,
    ERR_NULL_PTR,
    ERR_FILE_NAME,
    ERR_FILE_OPEN,
    ERR_FILE_CLOSE,
    ERR_FILE_STRUCTURE,
    ERR_DATA_CORRUPTED,
    ERR_NO_DATA,
    ERR_ARRAY_OVERFLOW,
    INCORRECT_COMMAND
} ret_code_t;

void handle_error(const ret_code_t &code);

#endif // ERRORS_H
