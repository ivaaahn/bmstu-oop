#include "model.h"
#include "point.h"

model_t &create_model(void)
{
    static model_t model;

    model.lines.data = NULL;
    model.lines.count = 0;

    model.points.data = NULL;
    model.points.count = 0;

    return model;
}

static err_t load_model(model_t &new_model, FILE *datafile)
{
    err_t rc = OK;

    if ((rc = points_reader(new_model.points, datafile)) != OK)
        return rc;

    if ((rc = lines_reader(new_model.lines, datafile)) != OK)
        free_model(new_model);

    return rc;
}

err_t init_model(model_t &model, filename_t fname)
{
    FILE *datafile = NULL;
    if ((datafile = fopen(fname, "r")) == NULL)
        return FOPEN_ERR;

    err_t rc = load_model(model, datafile);
    fclose(datafile);

    return rc;
}

err_t update_model(const model_t &model, const canvas_t &canvas)
{
    if (!(model.lines.data && model.points.data))
        return MEM_ERR;

    canvas->clear();
    drawer(model.lines, model.points, canvas);

    return OK;
}

static void translate_points(points_t &points, const translate_data_t &coeffs)
{
    for (size_t i = 0; i < points.count; i++)
        translate_point(points.data[i], coeffs);
}

err_t translate_model(model_t &model, const translate_data_t &coeffs)
{
    if (!(model.points.data && model.lines.data))
        return MEM_ERR;

    translate_points(model.points, coeffs);

    return OK;
}

static void scale_points(points_t &points, const scale_data_t &coeffs)
{
    for (size_t i = 0; i < points.count; i++)
        scale_point(points.data[i], coeffs);
}

err_t scale_model(model_t &model, const scale_data_t &coeffs)
{
    if (!(model.points.data && model.lines.data))
        return MEM_ERR;

    scale_points(model.points, coeffs);

    return OK;
}

static void rotate_points(points_t &points, const rotate_data_t &coeffs)
{
    for (size_t i = 0; i < points.count; i++)
    {
        rotate_x_axis(points.data[i], coeffs.ax);
        rotate_y_axis(points.data[i], coeffs.ay);
        rotate_z_axis(points.data[i], coeffs.az);
    }
}

err_t rotate_model(model_t &model, const rotate_data_t &coeffs)
{
    if (!(model.points.data && model.lines.data))
        return MEM_ERR;

    rotate_points(model.points, coeffs);

    return OK;
}

void free_model(const model_t &model)
{
    free_points(model.points);
    free_lines(model.lines);
}