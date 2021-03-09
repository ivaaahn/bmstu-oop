#ifndef _LINES_H_
#define _LINES_H_

#include <cstddef>
#include "errors.h"

typedef struct
{
    int point_ref_1;
    int point_ref_2;
} line_t;

typedef struct
{
    size_t count;
    line_t *data = NULL;
} lines_t;

err_t loader(lines_t &lines, FILE *datafile);
void destructor(const lines_t &lines);

#endif // _LINES_H_