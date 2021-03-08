#include "mainwindow.h"
#include <stdio.h>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(5, 5, W, H);
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

    err_t rc = request_handler(request);

    return rc;
}

void MainWindow::on_load_btn_clicked(void)
{
    filename_t name = PATH_TO_DATAFILE;
    request_t request;

    request.action = LOAD;
    request.fname = name;

    err_t rc = OK;
    
    if ((rc = request_handler(request)) != OK)
    {
        err_handler(rc);
        return;
    }

    if ((rc = draw_actions()) != OK)
    {
        err_handler(rc);
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
    request.translate_data = coeffs;

    err_t rc = OK;
    
    if ((rc = request_handler(request)) != OK)
    {
        err_handler(rc);
        return;
    }

    if ((rc = draw_actions()) != OK)
    {
        err_handler(rc);
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
    request.scale_data = coeffs;

    err_t rc = OK;

    if ((rc = request_handler(request)))
    {
        err_handler(rc);
        return;
    }

    if ((rc = draw_actions()) != OK)
    {
        err_handler(rc);
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
    request.rotate_data = coeffs;

    err_t rc = OK;
    
    if ((rc = request_handler(request)) != OK)
    {
        err_handler(rc);
        return;
    }

    if ((rc = draw_actions()) != OK)
    {
        err_handler(rc);
    }
}



// void MainWindow::resizeEvent(QResizeEvent *event)
// {
//     int width = ui->graphicsView->width();
//     int height = ui->graphicsView->height();

//     ui->graphicsView->scene()->setSceneRect(0, 0, width, height);

//  }
