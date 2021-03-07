#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_


#include <QMainWindow>
#include "ui_mainwindow.h"
#include "action.h"
#include "errors.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
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

    err_t draw_actions(void);


private:
    Ui::MainWindow *ui;
};


#endif // _MAINWINDOW_H_
