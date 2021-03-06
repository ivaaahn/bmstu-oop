#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "ui_mainwindow.h"

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
