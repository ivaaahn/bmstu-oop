#include <cstdio>

#include "line.hpp"
#include "lines.hpp"
#include "errors.hpp"


static err_t read_lines_count(lines_t &lines, FILE *datafile)
{
    size_t tmp_count = 0;
    if ((fscanf(datafile, "%zu", &tmp_count)) != 1)
        return ERR_FREAD;

    if (tmp_count < 1)
        return ERR_LCOUNT;

    lines.count = tmp_count;

    return SUCCESS;
}

static err_t allocate_lines(lines_t &lines)
{
    line_t *temp_data = (line_t *)malloc(lines.count * sizeof(line_t));
    if (temp_data == NULL)
        return ERR_ALLOC;

    lines.data = temp_data;

    return SUCCESS;
}


static err_t read_lines(line_t *const lines, const size_t &count, FILE *datafile)
{
    err_t rc = SUCCESS;
    for (size_t i = 0; rc == SUCCESS && i < count; i++)
        rc = read_line(lines[i], datafile);

    return rc;
}

void destruct_lines(lines_t &lines)
{
    if (lines.data != NULL)
    {
        free(lines.data);
        init_lines(lines);
    }
}

err_t load_lines(lines_t &lines, FILE *datafile)
{
    err_t rc = SUCCESS;

    if ((rc = read_lines_count(lines, datafile)))
        return rc;

    if ((rc = allocate_lines(lines)))
        return rc;

    if ((rc = read_lines(lines.data, lines.count, datafile)))
        destruct_lines(lines);

    return rc;
}

bool lines_are_defined(const lines_t &lines)
{
    return lines.data != NULL;
}

void init_lines(lines_t &lines)
{
    lines.count = 0;
    lines.data = NULL;
}