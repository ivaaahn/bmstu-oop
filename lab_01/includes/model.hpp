#ifndef _MODEL_HPP_
#define _MODEL_HPP_

#include "points.hpp"
#include "lines.hpp"
#include "errors.hpp"
#include "drawer.hpp"

typedef const char *filename_t;

typedef struct
{
    points_t points;
    lines_t lines;
} model_t;


void init_model(model_t &model);

err_t load_model(model_t &model, filename_t fname);

void destruct_model(model_t &model);

err_t redraw_model(const model_t &model, const canvas_t &canvas);

err_t translate_model(model_t &model, const translate_t &translate_data);

err_t scale_model(model_t &model, const scale_t &scale_data);

err_t rotate_model(model_t &model, const rotate_t &rotate_data);


#endif  //  _MODEL_HPP_ 