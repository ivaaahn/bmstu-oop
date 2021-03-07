#ifndef _DRAWER_H_
#define _DRAWER_H_

#include "ui_mainwindow.h"
#include "point.h"
#include "line.h"

typedef struct
{
    QGraphicsScene *scene;
    double width;
    double height;
} canvas_t;


void draw_lines(const lines_t &lines, const points_t &points, const canvas_t &canvas);

#endif  // _DRAWER_H_