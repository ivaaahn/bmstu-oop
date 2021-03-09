#include "model.h"
#include "points.h"
#include "lines.h"

model_t &creator(void)
{
    static model_t model;

    model.lines.data = NULL;
    model.lines.count = 0;

    model.points.data = NULL;
    model.points.count = 0;

    return model;
}

static err_t load(model_t &new_model, FILE *datafile)
{
    err_t rc = OK;

    if ((rc = loader(new_model.points, datafile)) != OK)
        return rc;

    if ((rc = loader(new_model.lines, datafile)) != OK)
        destructor(new_model);

    return rc;
}

err_t init(model_t &model, filename_t fname)
{
    FILE *datafile = NULL;
    if ((datafile = fopen(fname, "r")) == NULL)
        return FOPEN_ERR;

    err_t rc = load(model, datafile);
    fclose(datafile);

    return rc;
}

err_t update(const model_t &model, const canvas_t &canvas)
{
    if (!(model.lines.data && model.points.data))
        return MEM_ERR;

    canvas->clear();
    drawer(model.lines, model.points, canvas);

    return OK;
}

err_t translate(model_t &model, const translate_t &tr_data)
{
    if (!(model.points.data && model.lines.data))
        return MEM_ERR;

    translate(model.points, tr_data);

    return OK;
}

err_t scale(model_t &model, const scale_t &sc_data)
{
    if (!(model.points.data && model.lines.data))
        return MEM_ERR;

    scale(model.points, sc_data);

    return OK;
}

err_t rotate(model_t &model, const rotate_t &rot_data)
{
    if (!(model.points.data && model.lines.data))
        return MEM_ERR;

    rotate(model.points, rot_data);

    return OK;
}

void destructor(const model_t &model)
{
    destructor(model.points);
    destructor(model.lines);
}