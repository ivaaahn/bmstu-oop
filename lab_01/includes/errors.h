#ifndef _ERRORS_H_
#define _ERRORS_H_

#include <QMessageBox>

typedef enum
{
    OK,
    FOPEN_ERR,
    ALLOC_ERR,
    FREAD_ERR,
    LCOUNT_ERR,
    PCOUNT_ERR,
    MEM_ERR,
    UNKNOWN_ERR
} err_t;

void handler(const err_t &code);

#endif // _ERRORS_H_
