#include "line.h"

static err_t read_amount(lines_t &lines, FILE *datafile)
{
    if ((fscanf(datafile, "%zu", &lines.count)) != 1)
    {
        return READ_ERR;
    }

    if (lines.count < 1)
    {
        return LCOUNT_ERR;
    }

    return OK;
}

static err_t read_lines(line_t *const array, const size_t &size, FILE *datafile)
{
    for (size_t i = 0; i < size; i++)
    {
        if ((fscanf(datafile, "%d %d", &array[i].point_1, &array[i].point_2)) != 2)
        {
            return READ_ERR;
        }
    }

    return OK;
}

static err_t allocate_lines(lines_t &lines)
{
    line_t *temp_array = (line_t*)malloc(lines.count * sizeof(line_t));

    if (temp_array == NULL)
    {
        return ALLOC_ERR;
    }

    lines.data = temp_array;

    return OK;
}

void free_lines(const lines_t &lines)
{

    // TODO: AGAIN...
    if (lines.data != NULL)
    {
        free(lines.data);
    }
}

err_t lines_handler(lines_t &lines, FILE *datafile)
{
     err_t error_code = OK;

     if ((error_code = read_amount(lines, datafile)))
     {
         return error_code;
     }

     if ((error_code = allocate_lines(lines)))
     {
         return error_code;
     }

     if ((error_code = read_lines(lines.data, lines.count, datafile)))
     {
        free_lines(lines);
     }

     return error_code;
}