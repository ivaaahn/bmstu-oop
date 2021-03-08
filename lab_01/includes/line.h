#ifndef _LINE_H_
#define _LINE_H_

#include <cstdio>
#include <cstdlib>

#include "ui_mainwindow.h"
#include "errors.h"
#include "point.h"

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


err_t lines_reader(lines_t &lines, FILE *datafile);
void free_lines(const lines_t &lines);


#endif  // _LINE_H_
