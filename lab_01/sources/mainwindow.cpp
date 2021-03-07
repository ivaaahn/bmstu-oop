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

MainWindow::~MainWindow(void)
{
    request_t request;
    request.action = QUIT;
    request_handler(request);

    delete ui;
}

err_t MainWindow::draw_actions(void)
{
    canvas_t canvas;
    canvas.scene = ui->graphicsView->scene();
    canvas.width = canvas.scene->width();
    canvas.height = canvas.scene->height();

    request_t request;
    request.action = DRAW;
    request.canvas = canvas;

    err_t error_code = request_handler(request);

    return error_code;
}

void MainWindow::on_load_btn_clicked(void)
{
    filename_t name = "../../data/data.csv";
    request_t request;

    request.action = LOAD;
    request.fname = name;

    err_t error_code = request_handler(request);
    if (error_code)
    {
        err_handler(error_code);
        return;
    }

    error_code = draw_actions();
    if (error_code)
    {
        err_handler(error_code);
    }
}

void MainWindow::on_translate_btn_clicked(void)
{
    translate_data_t coeffs;
    coeffs.dx = ui->dx_box->value();
    coeffs.dy = ui->dy_box->value();
    coeffs.dz = ui->dz_box->value();

    request_t request;
    request.action = TRANSLATE;
    request.move = coeffs;

    err_t error_code = request_handler(request);
    if (error_code)
    {
        err_handler(error_code);
        return;
    }

    error_code = draw_actions();
    if (error_code)
    {
        err_handler(error_code);
    }
}

void MainWindow::on_scale_btn_clicked(void)
{
    scale_data_t coeffs;
    coeffs.kx = ui->kx_box->value();
    coeffs.ky = ui->ky_box->value();
    coeffs.kz = ui->kz_box->value();

    request_t request;
    request.action = SCALE;
    request.scale = coeffs;

    err_t error_code = request_handler(request);
    if (error_code)
    {
        err_handler(error_code);
        return;
    }

    error_code = draw_actions();
    if (error_code)
    {
        err_handler(error_code);
    }
}

void MainWindow::on_rotate_btn_clicked(void)
{
    rotate_data_t coeffs;
    coeffs.ax = ui->ax_box->value();
    coeffs.ay = ui->ay_box->value();
    coeffs.az = ui->az_box->value();

    request_t request;
    request.action = ROTATE;
    request.turn = coeffs;

    err_t error_code = request_handler(request);
    if (error_code)
    {
        err_handler(error_code);
        return;
    }

    error_code = draw_actions();
    if (error_code)
    {
        err_handler(error_code);
    }
}

