#include "lines.h"
#include "errors.h"
#include <cstdio>

static err_t read_count(lines_t &lines, FILE *datafile)
{
    size_t tmp_count = 0;
    if ((fscanf(datafile, "%zu", &tmp_count)) != 1)
        return FREAD_ERR;

    if (tmp_count < 1)
        return LCOUNT_ERR;

    lines.count = tmp_count;

    return OK;
}

static err_t allocate(lines_t &lines)
{
    line_t *temp_data = (line_t *)malloc(lines.count * sizeof(line_t));
    if (temp_data == NULL)
        return ALLOC_ERR;

    lines.data = temp_data;

    return OK;
}

static err_t read_lines(line_t *const lines, const size_t &count, FILE *datafile)
{
    for (size_t i = 0; i < count; i++)
        if ((fscanf(datafile, "%d %d", &lines[i].point_ref_1, &lines[i].point_ref_2)) != 2)
            return FREAD_ERR;

    return OK;
}

void destructor(const lines_t &lines)
{
    free(lines.data);
}

err_t loader(lines_t &lines, FILE *datafile)
{
    err_t rc = OK;

    if ((rc = read_count(lines, datafile)))
        return rc;

    if ((rc = allocate(lines)))
        return rc;

    if ((rc = read_lines(lines.data, lines.count, datafile)))
        destructor(lines);

    return rc;
}