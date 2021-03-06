#include "action.h"


// err_t action_handler(const action_t &request)
// {
//     err_t error_code = OK;

//     // switch (request.task)
//     // {
//     //     case LOAD:
//     //         error_code = load_figure(figure, request.file_name);
//     //         break;
            
//     //     case SCALE:
//     //         error_code = scale_figure(figure, request.scale);
//     //         break;
        
//     //     case ROTATE:
//     //         error_code = turn_figure(figure, request.turn);
//     //         break;
        
//     //     case TRANSLATE:
//     //         error_code = move_figure(figure, request.move);
//     //         break;
        
//     //     case DRAW:
//     //         error_code = draw_figure(figure, request.plane);
//     //         break;
        
//     //     case QUIT:
//     //         free_figure(figure);
//     //         break;
//     //     default:
//     //         error_code = UNKNOWN_COMMAND;
//     // }

//     return error_code;
// }