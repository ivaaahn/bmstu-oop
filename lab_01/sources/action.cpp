#include "action.h"


err_t request_handler(const request_t &request)
{
    static model_t model = init_model();

    err_t error_code = OK;

    switch (request.action)
    {
        case LOAD:
            error_code = load_model(model, request.fname);
            break;
            
        case SCALE:
            error_code = scale_model(model, request.scale);
            break;
        
        case ROTATE:
            error_code = rotate_model(model, request.turn);
            break;
        
        case TRANSLATE:
            error_code = translate_model(model, request.move);
            break;
        
        case DRAW:
            error_code = draw_model(model, request.canvas);
            break;
        
        case QUIT:
            free_model(model);
            break;
        default:
            error_code = UNKNOWN_ERR;
    }

    return error_code;
}