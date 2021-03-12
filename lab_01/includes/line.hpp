#ifndef _LINE_HPP_
#define _LINE_HPP_

#include <cstdlib>
#include <cstdio>

#include "errors.hpp"

typedef struct
{
    size_t point_ref_1;
    size_t point_ref_2;
} line_t;


err_t read_line(line_t &line, FILE *datafile);


#endif  // _LINE_HPP_