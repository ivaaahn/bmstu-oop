#include "request.hpp"


err_t request_handler(const request_t &request)
{   
    static model_t model = create_model();


    err_t rc = SUCCESS;
    switch (request.action)
    {
    case LOAD:
        rc = load_model(model, request.fname);
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

    case REDRAW:
        rc = redraw_model(model, request.canvas);
        break;

    case QUIT:
        destruct_model(model);
        break;

    default:
        rc = ERR_OTHER;
    }

    return rc;
}