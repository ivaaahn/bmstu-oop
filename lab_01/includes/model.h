#ifndef _MODEL_H_
#define _MODEL_H_


#include "ui_mainwindow.h"
#include "drawer.h"
#include "point.h"
#include "line.h"
#include "errors.h"


typedef const char *filename_t;

typedef struct
{
    points_t points;
    lines_t lines;
} model_t;



model_t &create_model(void);

err_t init_model(model_t &figure, filename_t name);

err_t update_model(const model_t &figure,  const canvas_t &canvas);

err_t translate_model(model_t &figure, const translate_data_t &coeffs);

err_t scale_model(model_t &figure, const scale_data_t &coeffs);

err_t rotate_model(model_t &figure, const rotate_data_t &coeffs);

void free_model(const model_t &model);

#endif