#include "model.h"
#include "point.h"

model_t &init_model(void)
{
    static model_t model;
    model.lines.data = NULL;
    model.lines.count = 0;

    model.points.data = NULL;
    model.points.count = 0;

    return model;
}

static err_t load_temp_model(model_t &temp_model, FILE *datafile)
{
    err_t error_code = OK;
    if ((error_code = points_handler(temp_model.points, datafile)))
    {
        return error_code;
    }

    if ((error_code = lines_handler(temp_model.lines, datafile)))
    {
        free_points(temp_model.points);
    }

    return error_code;
}


err_t load_model(model_t &model, filename_t fname)
{
    FILE *datafile = NULL;
    printf("%s", fname);

    if ((datafile = fopen(fname, "r")) == NULL)
    {
        return FILE_ERR;
    }
    
    err_t error_code = OK;
    model_t temp_model = init_model();
    error_code = load_temp_model(temp_model, datafile);
    fclose(datafile);

    if (!error_code)
    {   
        free_model(model);
        model = temp_model;
    }

    return error_code;
}

err_t draw_model(const model_t &model,  const canvas_t &canvas)
{
    if (model.lines.data == NULL || model.points.data == NULL)
    {
        return MEM_ERR;
    }

    canvas.scene->clear();
    draw_lines(model.lines, model.points, canvas);

    return OK;
}


static void translate_points(points_t &points, const translate_data_t &coeffs)
{
    for (size_t i = 0; i < points.count; i++)
    {
        translate_point(points.data[i], coeffs);
    }
}

err_t translate_model(model_t &model, const translate_data_t &coeffs)
{
    if (model.points.data == NULL || model.lines.data == NULL)
    {
        return MEM_ERR;
    }

    translate_points(model.points, coeffs);

    return OK;
}

static void scale_points(points_t &points, const scale_data_t &coeffs)
{
    for (size_t i = 0; i < points.count; i++)
    {
        scale_point(points.data[i], coeffs);
    }
}

err_t scale_model(model_t &model, const scale_data_t &coeffs)
{
    if (model.points.data == NULL || model.lines.data == NULL)
    {
        return MEM_ERR;
    }

    scale_points(model.points, coeffs);

    return OK;
}

static void rotate_points(points_t &points, const rotate_data_t &coeffs)
{
    for (size_t i = 0; i < points.count; i++)
    {
        rotate_x(points.data[i], coeffs.ax);
        rotate_y(points.data[i], coeffs.ay);
        rotate_z(points.data[i], coeffs.az);
    }
}

err_t rotate_model(model_t &model, const rotate_data_t &coeffs)
{
    if (model.points.data == NULL || model.lines.data == NULL)
    {
        return MEM_ERR;
    }

    rotate_points(model.points, coeffs);

    return OK;
}

void free_model(const model_t &model)
{
    free_points(model.points);
    free_lines(model.lines);
}