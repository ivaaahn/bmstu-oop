#ifndef _ACTION_H_
#define _ACTION_H_


// #include "figure.h"
#include "errors.h"

enum actions
{
    LOAD,
    TRANSLATE,
    SCALE,
    ROTATE,
    DRAW,
    QUIT
};

// typedef struct
// {
//     int task;
//     union
//     {
//         fname_t file_name;
//         scale_t scale;
//         turn_t turn;
//         move_t move;
//         plane_t plane;
//     };
// } action_t;


// err_t action_handler(const action_t &request);

#endif // _ACTION_H_