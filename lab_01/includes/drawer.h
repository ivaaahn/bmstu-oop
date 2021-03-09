#ifndef _DRAWER_H_
#define _DRAWER_H_

#include "ui_mainwindow.h"
#include "point.h"
#include "line.h"


typedef QGraphicsScene *canvas_t;


// typedef struct
// {
//     QGraphicsScene *scene;
//     int width;
//     int height;
// } canvas_t;


void drawer(const lines_t &lines, const points_t &points, const canvas_t &canvas);

#endif  // _DRAWER_H_