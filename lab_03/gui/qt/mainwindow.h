#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>
#include <memory>
#include "design.h"

#include "commands/command.hpp"
#include "commands/camera/camera_command.hpp"
#include "commands/model/model_command.hpp"
#include "commands/scene/scene_command.hpp"
#include "drawer/drawer.hpp"
#include "facade/facade.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);


    ~MainWindow() override;

protected:
    void setup_scene();

    void updateScene();

//    void clear_scene();
//
    void check_cam_exist();
//
//    void check_can_delete_cam();
//
//    void check_models_exist();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:

    void change_cam();

    void on_move_btn_clicked();

    void on_scale_btn_clicked();

    void on_rotate_btn_clicked();

    void on_load_model_btn_clicked();

    void on_remove_model_btn_clicked();

    void on_load_camera_btn_clicked();

    void on_add_camera_btn_clicked();

    void on_remove_camera_btn_clicked();

    void on_right_btn_clicked();

    void on_up_btn_clicked();

    void on_down_btn_clicked();

    void on_left_btn_clicked();

private:

    Ui::MainWindow *ui;

    std::shared_ptr<Facade> facade; // Может сделать не указатель?

    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<Drawer> drawer;
};
