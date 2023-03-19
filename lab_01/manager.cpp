#include "manager.h"

ret_code_t handle_request(const request_t &request)
{
    ret_code_t rc;
    static model_t model = init_model();

    switch (request.code)
    {
        case LOAD_MODEL:
            rc = load_model(model, request.filename);
            break;
        case TRANSLATE_MODEL:
            rc = model_translate(model, request.translation);
            break;
        case SCALE_MODEL:
            rc = model_scale(model, request.scale);
            break;
        case ROTATE_MODEL:
            rc = model_rotate(model, request.rotation);
            break;
        case DRAW_MODEL:
            rc = draw_model(model, request.canvas);
            break;
        case EXIT:
            rc = free_model(model);
            break;
        default:
            rc = INCORRECT_COMMAND;
    }

    return rc;
}
