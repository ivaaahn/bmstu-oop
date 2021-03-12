#ifndef _LINE_HPP_
#define _LINE_HPP_

#include <cstdlib>
#include <cstdio>

#include "errors.hpp"

struct line_t
{
    size_t point_ref_1;
    size_t point_ref_2;
};


err_t read_line(line_t &line, FILE *datafile);


#endif  // _LINE_HPP_