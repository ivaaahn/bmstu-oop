#ifndef _ACTION_H_
#define _ACTION_H_

#include "model.h"
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

typedef struct
{
    int action;
    union
    {
        filename_t fname;
        scale_data_t scale;
        rotate_data_t turn;
        translate_data_t move;
        canvas_t canvas;
    };
} request_t;

err_t request_handler(const request_t &request);

#endif // _ACTION_H_