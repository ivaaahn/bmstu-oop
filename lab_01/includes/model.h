#ifndef _MODEL_H_
#define _MODEL_H_

#include "points.h"
#include "lines.h"
#include "errors.h"
#include "drawer.h"

typedef const char *filename_t;

typedef struct
{
    points_t points;
    lines_t lines;
} model_t;

model_t &creator(void);
void destructor(const model_t &model);

err_t init(model_t &model, filename_t fname);
err_t update(const model_t &model, const canvas_t &canvas);
err_t translate(model_t &model, const translate_t &tr_data);
err_t scale(model_t &model, const scale_t &sc_data);
err_t rotate(model_t &model, const rotate_t &rot_data);

#endif