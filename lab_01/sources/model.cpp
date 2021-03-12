#include "model.hpp"
#include "points.hpp"
#include "lines.hpp"


model_t create_model()
{
    model_t new_model;

    init_points(new_model.points);
    init_lines(new_model.lines);

    return new_model;
}

static err_t load_model_stream(model_t &model, FILE *datafile)
{
    err_t rc = SUCCESS;
    if ((rc = load_points(model.points, datafile)) != SUCCESS)
        return rc;

    if ((rc = load_lines(model.lines, datafile)) != SUCCESS)
        return rc;

    return SUCCESS;
}

err_t load_model(model_t &model, filename_t fname)
{
    FILE *datafile = fopen(fname, "r");

    if (!datafile) return ERR_FOPEN;

    model_t temp_model = create_model();
    err_t rc = load_model_stream(temp_model, datafile);
    fclose(datafile);

    if (rc != SUCCESS)
    {
        destruct_model(temp_model);
        return rc;
    }
   
    destruct_model(model);
    model = temp_model;

    return SUCCESS;
}

err_t redraw_model(const model_t &model, const canvas_t &canvas)
{
    if (!(points_are_defined(model.points) && lines_are_defined(model.lines)))
        return ERR_MEMORY;

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

static void translate_to_center(model_t &model, point_t &center)
{
    translate_t tr_data;
    tr_data.x = -center.x;
    tr_data.y = -center.y;
    tr_data.z = -center.z;
    
    translate_model(model, tr_data);
}


static void translate_back(model_t &model, point_t &place)
{
    translate_t tr_data;
    tr_data.x = place.x;
    tr_data.y = place.y;
    tr_data.z = place.z;
    
    translate_model(model, tr_data);
}

err_t scale_model(model_t &model, const scale_t &sc_data)
{
    point_t center = get_center(model.points);
    translate_to_center(model, center);

    if (!(points_are_defined(model.points) && lines_are_defined(model.lines)))
        return ERR_MEMORY;

    scale_points(model.points, sc_data);
    translate_back(model, center);

    return SUCCESS;
}

err_t rotate_model(model_t &model, const rotate_t &rot_data)
{
    point_t center = get_center(model.points);
    translate_to_center(model, center);

    if (!(points_are_defined(model.points) && lines_are_defined(model.lines)))
        return ERR_MEMORY;

    rotate_points(model.points, rot_data);
    translate_back(model, center);

    return SUCCESS;
}

void destruct_model(model_t &model)
{
    destruct_points(model.points);
    destruct_lines(model.lines);
}