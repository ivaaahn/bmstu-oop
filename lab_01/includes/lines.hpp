#ifndef _LINES_HPP_
#define _LINES_HPP_

#include <cstdlib>
#include "line.hpp"
#include "errors.hpp"

typedef struct
{
    size_t count;
    line_t *data;
} lines_t;


err_t load_lines(lines_t &lines, FILE *datafile);

void init_lines(lines_t &lines);

void destruct_lines(lines_t &lines);

bool lines_are_defined(const lines_t &lines);


#endif // _LINES_HPP_