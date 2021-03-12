#include <QMessageBox>

#include "errors.hpp"


void err_handler(const err_t code)
{
    switch (code)
    {
    case ERR_FOPEN:
        QMessageBox::critical(NULL, "Ошибка", "Не удалось открыть файл!");
        break;

    case ERR_FREAD:
        QMessageBox::critical(NULL, "Ошибка", "Не удалось считать файл!");
        break;

    case ERR_PCOUNT:
        QMessageBox::critical(NULL, "Ошибка", "Некорректное количество линий!");
        break;

    case ERR_LCOUNT:
        QMessageBox::critical(NULL, "Ошибка", "Некорректное количество точек!");
        break;

    case ERR_MEMORY:
        QMessageBox::critical(NULL, "Ошибка", "Произошла ошибка при обращении к данным!");
        break;

    case ERR_ALLOC:
        QMessageBox::critical(NULL, "Ошибка", "Произошла ошибка при выделении памяти");
        break;

    case ERR_LAUNCH_ARGS:
        QMessageBox::critical(NULL, "Ошибка", "Не указано имя файла, содержащего модель!");
        break;

    default:
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная команда!");
    }
}