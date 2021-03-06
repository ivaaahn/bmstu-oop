#ifndef _LINE_H_
#define _LINE_H_

#include <cstdio>
#include <stdlib.h>

#include "ui_mainwindow.h"
#include "errors.h"
#include "point.h"

typedef struct 
{
    int point_1;
    int point_2;
} line_t;


typedef struct 
{
    size_t count;
    line_t *data = NULL;
} lines_t;


err_t lines_handler(lines_t links, FILE *f);
void free_lines(const lines_t &lines);


#endif  // _LINE_H_
