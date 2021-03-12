#include <cstdio>

#include "line.hpp"
#include "errors.hpp"


err_t read_line(line_t &line, FILE *datafile)
{
    if (fscanf(datafile, "%zu %zu", &line.point_ref_1, &line.point_ref_2) != 2)
        return ERR_FREAD;

    return SUCCESS;
}
