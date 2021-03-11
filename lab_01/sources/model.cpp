#include "model.hpp"
#include "points.hpp"
#include "lines.hpp"

void init_model(model_t &model)
{
    printf("[DBG] I'm into init_model()\n");
    init_points(model.points);
    init_lines(model.lines);
}

err_t load_model(model_t &model, filename_t fname)
{
    FILE *datafile = NULL;
    if ((datafile = fopen(fname, "r")) == NULL)
        return ERR_FOPEN;

    err_t rc = SUCCESS;

    model_t temp_model;
    if ((rc = load_points(temp_model.points, datafile)) != SUCCESS)
    {
        fclose(datafile);
        return rc;
    }

    if ((rc = load_lines(temp_model.lines, datafile)) != SUCCESS)
    {
        fclose(datafile);
        destruct_model(temp_model);
        return rc;
    }

    fclose(datafile);

    destruct_model(model);
    model = temp_model;

    return SUCCESS;
}

err_t redraw_model(const model_t &model, const canvas_t &canvas)
{
    if (!(points_are_defined(model.points) && lines_are_defined(model.lines)))
        return ERR_MEMORY;

    canvas->clear();
    drawer(model.lines, model.points, canvas);

    return SUCCESS;
}

err_t translate_model(model_t &model, const translate_t &tr_data)
{
    if (!(points_are_defined(model.points) && lines_are_defined(model.lines)))
        return ERR_MEMORY;

    translate_points(model.points, tr_data);

    return SUCCESS;
}

err_t scale_model(model_t &model, const scale_t &sc_data)
{
    if (!(points_are_defined(model.points) && lines_are_defined(model.lines)))
        return ERR_MEMORY;

    scale_points(model.points, sc_data);

    return SUCCESS;
}

err_t rotate_model(model_t &model, const rotate_t &rot_data)
{
    if (!(points_are_defined(model.points) && lines_are_defined(model.lines)))
        return ERR_MEMORY;

    rotate_points(model.points, rot_data);

    return SUCCESS;
}

void destruct_model(model_t &model)
{
    destruct_points(model.points);
    destruct_lines(model.lines);
}