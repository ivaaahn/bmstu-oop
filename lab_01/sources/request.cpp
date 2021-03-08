#include "request.h"

err_t request_handler(const request_t &request)
{
    static model_t model = create_model();

    err_t rc = OK;

    switch (request.action)
    {
    case LOAD:
        rc = init_model(model, request.fname);
        break;

    case SCALE:
        rc = scale_model(model, request.scale_data);
        break;

    case ROTATE:
        rc = rotate_model(model, request.rotate_data);
        break;

    case TRANSLATE:
        rc = translate_model(model, request.translate_data);
        break;

    case DRAW:
        rc = draw_model(model, request.canvas);
        break;

    case QUIT:
        free_model(model);
        break;
    default:
        rc = UNKNOWN_ERR;
    }

    return rc;
}