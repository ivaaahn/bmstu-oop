#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "request.h"
#include "errors.h"

#define CANVAS_OFFSET 5
#define CANVAS_W 981
#define CANVAS_H 710

#define PATH_TO_DATAFILE "../../data/datafile"

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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_load_btn_clicked();

    void on_scale_btn_clicked();

    void on_rotate_btn_clicked();

    void on_translate_btn_clicked();

    err_t apply_actions(void);

private:
    Ui::MainWindow *ui;
};

#endif // _MAINWINDOW_H_
