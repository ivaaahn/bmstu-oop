#ifndef _REQUEST_HPP_
#define _REQUEST_HPP_

#include "model.hpp"
#include "errors.hpp"


enum actions
{
    LOAD,
    TRANSLATE,
    SCALE,
    ROTATE,
    REDRAW,
    QUIT
};

struct request_t
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
};


err_t request_handler(const request_t &request);


#endif // _ACTION_HPP_