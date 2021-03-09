#include "mainwindow.h"
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
    request_t quit = {.action = QUIT};
    request_handler(quit);

    delete ui;
}

err_t MainWindow::render_actions(void)
{
    canvas_t canvas = ui->graphicsView->scene();
    request_t render = {.action = RENDER, .canvas = canvas};
    err_t rc = request_handler(render);

    return rc;
}

void MainWindow::on_load_btn_clicked(void)
{
    filename_t name = PATH_TO_DATAFILE;
    request_t load = {.action = LOAD, .fname = name};

    err_t rc = OK;
    if ((rc = request_handler(load)) != OK)
    {
        handler(rc);
        return;
    }

    if ((rc = render_actions()) != OK)
        handler(rc);
}

void MainWindow::on_translate_btn_clicked(void)
{
    translate_t tr_data;
    tr_data.dx = ui->dx_box->value();
    tr_data.dy = ui->dy_box->value();
    tr_data.dz = ui->dz_box->value();

    request_t translate = {.action = TRANSLATE, .translate_data = tr_data};

    err_t rc = OK;
    if ((rc = request_handler(translate)) != OK)
    {
        handler(rc);
        return;
    }

    if ((rc = render_actions()) != OK)
        handler(rc);
}

void MainWindow::on_scale_btn_clicked(void)
{
    scale_t sc_data;
    sc_data.kx = ui->kx_box->value();
    sc_data.ky = ui->ky_box->value();
    sc_data.kz = ui->kz_box->value();

    request_t scale = {.action = SCALE, .scale_data = sc_data};

    err_t rc = OK;
    if ((rc = request_handler(scale)) != OK)
    {
        handler(rc);
        return;
    }

    if ((rc = render_actions()) != OK)
        handler(rc);
}

void MainWindow::on_rotate_btn_clicked(void)
{
    rotate_t rot_data;
    rot_data.ax = ui->ax_box->value();
    rot_data.ay = ui->ay_box->value();
    rot_data.az = ui->az_box->value();

    request_t rotate = {.action = ROTATE, .rotate_data = rot_data};
    err_t rc = OK;
    if ((rc = request_handler(rotate)) != OK)
    {
        handler(rc);
        return;
    }

    if ((rc = render_actions()) != OK)
        handler(rc);
}
