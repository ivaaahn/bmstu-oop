#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "request.hpp"
#include "errors.hpp"

#define CANVAS_OFFSET 5
#define CANVAS_W 1247
#define CANVAS_H 890


QT_BEGIN_NAMESPACE

namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void load_file(filename_t filename);

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
private slots:
    
    void on_scale_btn_clicked();

    void on_rotate_btn_clicked();

    void on_translate_btn_clicked();

    err_t redraw_actions();

private:
    Ui::MainWindow *ui;
};


#endif // _MAINWINDOW_HPP_
