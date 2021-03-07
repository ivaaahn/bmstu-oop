#include "drawer.h"
#include "point.h"
#include "line.h"

static void draw_line(const line_t &line, const point_t *const points, const canvas_t &canvas)
{
    point_t pt1 = points[line.point_1];
    point_t pt2 = points[line.point_2];

    canvas.scene->addLine(
        pt1.x + canvas.width / 2,
        pt1.y + canvas.height / 2,
        pt2.x + canvas.width / 2,
        pt2.y + canvas.height / 2
   );
}

void draw_lines(const lines_t &lines, const points_t &points, const canvas_t &canvas)
{
    for (size_t i = 0; i < lines.count; i++)
    {
        draw_line(lines.data[i], points.data, canvas);
    }
}
