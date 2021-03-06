#include "model.h"

model_t &init_model(void)
{
    static model_t model;
    model.lines.data = NULL;
    model.lines.count = 0;

    model.points.data = NULL;
    model.points.count = 0;

    return model;
}


err_t load_model(model_t &model, fname_t name)
{
    FILE *datafile = NULL;

    if ((datafile = fopen(name, "r")) == NULL)
    {
        return FILE_ERR;
    }
    
    err_t error_code = OK;
    model_t temp_figure = init_model();
    // error_code = load_temp_figure(temp_figure, f);
    // fclose(f);

    if (!error_code)
    {   
        free_figure(figure);
        figure = temp_figure;
    }

    return error_code;
}