#ifndef _DRAWER_HPP_
#define _DRAWER_HPP_

#include <QGraphicsScene>

#include "points.hpp"
#include "lines.hpp"

typedef QGraphicsScene *canvas_t;

void drawer(const lines_t &lines, const points_t &points, const canvas_t &canvas);

#endif // _DRAWER_HPP_