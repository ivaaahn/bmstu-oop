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
    [[nodiscard]] size_t getCamerasCount() const;

    [[nodiscard]] size_t getModelsCount() const;

    bool canRemoveCamera(size_t id);

    bool canRemoveModel(size_t id);

    bool modelSelected();

    bool cameraSelected();

    void setupScene();

    void updateScene();

    void resetModel();

    void resetCamera();

    size_t getCurrCameraID();

    size_t getCurrModelID();

    bool checkCamAndModel();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:

    void on_change_camera_btn_clicked();

    void on_change_model_btn_clicked();

    void on_move_btn_clicked();

    void on_scale_btn_clicked();

    void on_rotate_btn_clicked();

    void on_load_model_btn_clicked();

    void on_load_camera_btn_clicked();

    void on_add_camera_btn_clicked();

    void on_remove_object_btn_clicked();

    void on_clear_scene_btn_clicked();

    void on_left_btn_clicked();

    void on_right_btn_clicked();

    void on_up_btn_clicked();

    void on_down_btn_clicked();

private:

    Ui::MainWindow *ui;

    std::shared_ptr<Facade> facade;

    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<Drawer> drawer;

    size_t last_cam_id = 0;
    size_t last_mod_id = 0;
};
