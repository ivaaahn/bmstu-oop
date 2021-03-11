#include <QMessageBox>

#include "errors.hpp"

void err_handler(const err_t code)
{
    switch (code)
    {
    case ERR_FOPEN:
        QMessageBox::critical(NULL, "Ошибка", "При открытии файла произошла ошибка!");
        break;

    case ERR_FREAD:
        QMessageBox::critical(NULL, "Ошибка", "При чтении файла произошла ошибка!");
        break;

    case ERR_PCOUNT:
        QMessageBox::critical(NULL, "Ошибка", "Некорректное кол-во линий!");
        break;

    case ERR_LCOUNT:
        QMessageBox::critical(NULL, "Ошибка", "Некорректное кол-во точек!");
        break;

    case ERR_MEMORY:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при обращении к данным!");
        break;

    case ERR_ALLOC:
        QMessageBox::critical(NULL, "Ошибка", "При выделении памяти произошла ошибка!");
        break;

    default:
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная команда!");
    }
}