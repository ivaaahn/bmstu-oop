#include "drawer.hpp"
#include "point.hpp"

static void to_canvas_cs(point_t &point, const canvas_t &canvas)
{
    point.x += canvas->width() / 2;
    point.y += canvas->height() / 2;
}

static void draw_line(const line_t &line, const point_t *const points, const canvas_t &canvas)
{
    point_t p1 = points[line.point_ref_1];
    to_canvas_cs(p1, canvas);

    point_t p2 = points[line.point_ref_2];
    to_canvas_cs(p2, canvas);

    canvas->addLine(p1.x, p1.y, p2.x, p2.y);
}

void drawer(const lines_t &lines, const points_t &points, const canvas_t &canvas)
{
    for (size_t i = 0; i < lines.count; i++)
        draw_line(lines.data[i], points.data, canvas);
}
