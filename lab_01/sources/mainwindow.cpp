#include "mainwindow.h"
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(0, 0, 640, 480);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_load_btn_clicked()
{
}

void MainWindow::on_scale_btn_clicked()
{
}

void MainWindow::on_rotate_btn_clicked()
{
}

void MainWindow::on_translate_btn_clicked()
{
}
