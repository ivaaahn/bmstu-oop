#include "errors.h"

void handler(const err_t &code)
{
    switch (code)
    {
    case FOPEN_ERR:
        QMessageBox::critical(NULL, "Ошибка", "При открытии файла произошла ошибка!");
        break;

    case ALLOC_ERR:
        QMessageBox::critical(NULL, "Ошибка", "При выделении памяти произошла ошибка!");
        break;

    case FREAD_ERR:
        QMessageBox::critical(NULL, "Ошибка", "При чтении файла произошла ошибка!");
        break;

    case PCOUNT_ERR:
        QMessageBox::critical(NULL, "Ошибка", "Некорретное кол-во точек!");
        break;

    case LCOUNT_ERR:
        QMessageBox::critical(NULL, "Ошибка", "Некорректное кол-во линий!");
        break;

    case MEM_ERR:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при обращении к данным!");
        break;

    default:
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная команда!");
    }
}