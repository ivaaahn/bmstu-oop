#include "request.h"

err_t request_handler(const request_t &request)
{
    static model_t model = creator();

    err_t rc = OK;

    switch (request.action)
    {
    case LOAD:
        rc = init(model, request.fname);
        break;

    case SCALE:
        rc = scale(model, request.scale_data);
        break;

    case ROTATE:
        rc = rotate(model, request.rotate_data);
        break;

    case TRANSLATE:
        rc = translate(model, request.translate_data);
        break;

    case RENDER:
        rc = render(model, request.canvas);
        break;

    case QUIT:
        destructor(model);
        break;

    default:
        rc = UNKNOWN_ERR;
    }

    return rc;
}