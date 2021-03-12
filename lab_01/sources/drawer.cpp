#include "drawer.hpp"
#include "point.hpp"


static void draw_line(const projection_t &p1, const projection_t &p2, const canvas_t &canvas)
{
    canvas->addLine(p1.x, p1.y, p2.x, p2.y);
}

static void to_canvas_cs(projection_t &p_proj, const point_t &p, const canvas_t &canvas)
{
    p_proj.x = p.x + canvas->width() / 2;
    p_proj.y = p.y + canvas->height() / 2;
}

static void draw_handler(const line_t &line, const point_t *const points, const canvas_t &canvas)
{
    projection_t p1, p2;
    12
-1,  1.62, 0
1,  1.62, 0
-1, -1.62, 0
1, -1.62, 0
0, -1, 1.62
0,  1, 1.62
0, -1, -1.62
0,  1, -1.62
1.62, 0, -1
1.62, 0,  1
-1.62, 0, -1
-1.62, 0,  1
0 0 0

0 1

    to_canvas_cs(p1, points[line.point_ref_1], canvas);
    to_canvas_cs(p2, points[line.point_ref_2], canvas);

    draw_line(p1, p2, canvas);
}

void drawer(const lines_t &lines, const points_t &points, const canvas_t &canvas)
{
    for (size_t i = 0; i < lines.count; i++)
        draw_handler(lines.data[i], points.data, canvas);
}
