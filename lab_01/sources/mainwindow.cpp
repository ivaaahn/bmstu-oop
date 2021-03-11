#include "mainwindow.hpp"
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(CANVAS_OFFSET, CANVAS_OFFSET, CANVAS_W, CANVAS_H);
}

MainWindow::~MainWindow(void)
{
    request_t quit = {.action = actions::QUIT};
    request_handler(quit);

    delete ui;
}

err_t MainWindow::render_actions(void)
{
    canvas_t canvas = ui->graphicsView->scene();
    request_t redraw = {.action = actions::REDRAW, .canvas = canvas};

    err_t rc = request_handler(redraw);

    return rc;
}

void MainWindow::on_load_btn_clicked(void)
{
    filename_t name = PATH_TO_DATAFILE;
    request_t load = {.action = actions::LOAD, .fname = name};

    err_t rc = SUCCESS;
    if ((rc = request_handler(load)) != SUCCESS)
    {
        err_handler(rc);
        return;
    }

    if ((rc = render_actions()) != SUCCESS)
        err_handler(rc);
}

void MainWindow::on_translate_btn_clicked(void)
{
    translate_t trans_data;
    trans_data.dx = ui->dx_box->value();
    trans_data.dy = ui->dy_box->value();
    trans_data.dz = ui->dz_box->value();

    request_t translate = {.action = actions::TRANSLATE, .translate_data = trans_data};

    err_t rc = SUCCESS;
    if ((rc = request_handler(translate)) != SUCCESS)
    {
        err_handler(rc);
        return;
    }

    if ((rc = render_actions()) != SUCCESS)
        err_handler(rc);
}

void MainWindow::on_scale_btn_clicked(void)
{
    scale_t scale_data;
    scale_data.kx = ui->kx_box->value();
    scale_data.ky = ui->ky_box->value();
    scale_data.kz = ui->kz_box->value();

    request_t scale = {.action = actions::SCALE, .scale_data = scale_data};

    err_t rc = SUCCESS;
    if ((rc = request_handler(scale)) != SUCCESS)
    {
        err_handler(rc);
        return;
    }

    if ((rc = render_actions()) != SUCCESS)
        err_handler(rc);
}

void MainWindow::on_rotate_btn_clicked(void)
{
    rotate_t rotate_data;
    rotate_data.ax = ui->ax_box->value();
    rotate_data.ay = ui->ay_box->value();
    rotate_data.az = ui->az_box->value();

    request_t rotate = {.action = actions::ROTATE, .rotate_data = rotate_data};
    err_t rc = SUCCESS;
    if ((rc = request_handler(rotate)) != SUCCESS)
    {
        err_handler(rc);
        return;
    }

    if ((rc = render_actions()) != SUCCESS)
        err_handler(rc);
}
