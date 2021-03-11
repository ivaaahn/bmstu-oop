#ifndef _ERRORS_HPP_
#define _ERRORS_HPP_

#include <QMessageBox>

#define SUCCESS 0

#define ERR_FOPEN   1 // file open
#define ERR_FREAD   2 // file read

#define ERR_ALLOC   3
#define ERR_PCOUNT  4 // num of points
#define ERR_LCOUNT  5 // num of lines
#define ERR_MEMORY  6

#define ERR_OTHER   7

typedef int err_t;

void err_handler(const err_t code);

#endif // _ERRORS_HPP_
