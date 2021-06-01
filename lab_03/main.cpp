#include <QApplication>

#include <QScreen>
#include <QStyle>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, w.size(),
                                      QGuiApplication::primaryScreen()->availableGeometry()));
    w.show();
    return QApplication::exec();
}