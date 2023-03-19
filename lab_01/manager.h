#ifndef MANAGER_H
#define MANAGER_H

#include "model.h"
#include "draw.h"
#include "errors.h"

enum data
{
    LOAD_MODEL,
    TRANSLATE_MODEL,
    SCALE_MODEL,
    ROTATE_MODEL,
    MOVE_MODEL,
    DRAW_MODEL,
    EXIT
};

typedef struct request
{
    int code;
    union
    {
        filename_t filename;
        vector3_t translation;
        double scale;
        vector3_t rotation;
        canvas_t canvas;
    };
} request_t;

ret_code_t handle_request(const request_t &request);

#endif // MANAGER_H
