#ifndef _MODEL_H_
#define _MODEL_H_


#include "ui_mainwindow.h"
// #include "draw.h"
#include "point.h"
#include "line.h"
#include "errors.h"


typedef const char *filename_t;

typedef struct
{
    points_t points;
    lines_t lines;
} model_t;



model_t &init_model(void);

err_t load_model(model_t &figure, filename_t name);

err_t draw_model(const model_t &figure,  const plane_t &plane);

err_t move_model(model_t &figure, const move_t &coeffs);

err_t scale_model(model_t &figure, const scale_t &coeffs);

err_t turn_model(model_t &figure, const turn &coeffs);

void free_model(const figure_t &figure);

#endif