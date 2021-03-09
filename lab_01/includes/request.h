#ifndef _REQUEST_H_
#define _REQUEST_H_

#include "model.h"
#include "errors.h"

enum actions
{
    LOAD,
    TRANSLATE,
    SCALE,
    ROTATE,
    UPDATE,
    QUIT
};

typedef struct
{
    int action;
    union
    {
        filename_t fname;
        scale_t scale_data;
        rotate_t rotate_data;
        translate_t translate_data;
        canvas_t canvas;
    };
} request_t;

err_t request_handler(const request_t &request);

#endif // _ACTION_H_