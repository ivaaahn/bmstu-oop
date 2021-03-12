#include <QApplication>
#include <cstdlib>

#include "mainwindow.hpp"
#include "errors.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    if (argc >= 2)
        w.load_file(argv[1]);
    else
    {
        err_handler(ERR_LAUNCH_ARGS);
        return EXIT_FAILURE;
    }

    return a.exec();
}
