#include <QFileDialog>
#include <commands/scene/render/render_scene.hpp>
#include <exceptions/base_exception.hpp>
#include <commands/model/load/load_model.hpp>
#include <commands/model/remove/remove_model.hpp>
#include <commands/camera/load/load_camera.hpp>
#include <commands/camera/add/add_camera.hpp>
#include <commands/camera/remove/remove_camera.hpp>
#include <commands/camera/set/set_camera.hpp>
#include <commands/camera/move/move_camera.hpp>
#include <commands/model/move/move_model.hpp>
#include <commands/model/scale/scale_model.hpp>
#include <commands/model/rotate/rotate_model.hpp>
#include <iostream>
#include <exceptions/load_exceptions.hpp>
#include <commands/camera/count/count_cameras.hpp>

#include "mainwindow.h"

#include "drawer/factory/qt_drawer_factory.hpp"


void MainWindow::setup_scene() {
    std::cout << "setup scene\n";

    this->scene = std::make_shared<QGraphicsScene>(this);
    ui->graphicsView->setScene(this->scene.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    this->scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
//    auto rcontent = ui->graphicsView->contentsRect(); // TODO ???or this???
//    _scene->setSceneRect(0, 0, rcontent.width(), rcontent.height());

    auto factory = std::make_shared<QtDrawerFactory>(this->scene);
    this->drawer = factory->createDrawer();
}

void MainWindow::updateScene() {
    std::cout << "update scene\n";

    auto render_scene_cmd = std::make_shared<RenderScene>(this->drawer);

    try
    {
        this->facade->execute(render_scene_cmd);
    }
    catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}


void MainWindow::check_cam_exist() {
    auto camera_count = std::make_shared<size_t>(0);
    auto camera_count_cmd = std::make_shared<CameraCount>(camera_count);

    try
    {
        this->facade->execute(camera_count_cmd);
    }
    catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }

    if (!*camera_count) throw NoCameraError(__FILE__, __LINE__, "No camera found");
}
//
//void MainWindow::check_can_delete_cam() {
//    auto model_count = std::make_shared<size_t>(0);
//    ModelCount model_command(model_count);
//    _facade->execute(model_command);
//
//    auto camera_count = std::make_shared<size_t>(0);
//    CameraCount camera_command(camera_count);
//    _facade->execute(camera_command);
//
//    if (*camera_count <= 1 && *model_count)
//    {
//        std::string message = "Can not delete the last camera with the loaded models";
//        throw CameraError(message);
//    }
//}

//void MainWindow::check_models_exist() {
//    auto count = std::make_shared<size_t>(0);
//    ModelCount model_command(count);
//    _facade->execute(model_command);
//
//    if (!*count)
//    {
//        std::string message = "No models found.";
//        throw ModelError(message);
//    }
//}

void MainWindow::on_move_btn_clicked() {
    std::cout << "move_btn clicked\n";

//    try
//    {
//        check_cam_exist();
//        check_models_exist();
//    } catch (const CameraError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
//        return;
//    } catch (const ModelError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
//        return;
//    }



    auto move_model_cmd = std::make_shared<MoveModel>(this->ui->model_choose->currentIndex(),
                                                      this->ui->dx_box->value(),
                                                      this->ui->dy_box->value(),
                                                      this->ui->dz_box->value());
    try
    {
        this->facade->execute(move_model_cmd);
        this->updateScene();
    } catch (const BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_scale_btn_clicked() {
    std::cout << "scale_btn clicked\n";

//    try
//    {
//        check_cam_exist();
//        check_models_exist();
//    } catch (const CameraError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
//        return;
//    } catch (const ModelError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
//        return;
//    }

    auto scale_model_cmd = std::make_shared<ScaleModel>(this->ui->model_choose->currentIndex(),
                                                      this->ui->kx_box->value(),
                                                      this->ui->ky_box->value(),
                                                      this->ui->kz_box->value());
    try
    {
        this->facade->execute(scale_model_cmd);
        this->updateScene();
    } catch (const BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_rotate_btn_clicked() {
    std::cout << "rotate_btn clicked\n";

//    try
//    {
//        check_cam_exist();
//        check_models_exist();
//    } catch (const CameraError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
//        return;
//    } catch (const ModelError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
//        return;
//    }

    auto rotate_model_cmd = std::make_shared<RotateModel>(this->ui->model_choose->currentIndex(),
                                                        this->ui->ax_box->value(),
                                                        this->ui->ax_box->value(),
                                                        this->ui->az_box->value());
    try
    {
        this->facade->execute(rotate_model_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_load_model_btn_clicked() {
    std::cout << "load_model_btn clicked\n";

    try
    {
        this->check_cam_exist();
    } catch (const BaseException &ex)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем добавлять модель, добавьте хотя бы одну камеру.");
        return;
    }

    auto filename = QFileDialog::getOpenFileName();

    if (filename.isNull()) return;


    auto load_model_cmd = std::make_shared<LoadModel>(filename.toUtf8().data());

    try
    {
        this->facade->execute(load_model_cmd);
    }
    catch (const BaseException &ex)
    {
        std::cout << "catch" << ex.what() << std::endl;

        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    this->updateScene();

    ui->model_choose->addItem(QFileInfo(filename.toUtf8().data()).fileName());
    ui->model_choose->setCurrentIndex(ui->model_choose->count() - 1);
}

void MainWindow::on_remove_model_btn_clicked() {
    std::cout << "rem_model_btn clicked\n";

//    try
//    {
//        check_models_exist();
//    } catch (const ModelError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять модель, добавьте хотя бы одну.");
//        return;
//    }


    auto remove_model_cmd = std::make_shared<RemoveModel>(ui->model_choose->currentIndex());

    try
    {
        this->facade->execute(remove_model_cmd);
        this->ui->model_choose->removeItem(this->ui->model_choose->currentIndex());
        updateScene();
    }
    catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}



//void MainWindow::clear_scene() {
//    try
//    {
//        check_models_exist();
//    } catch (const ModelError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять модели, добавьте хотя бы одну.");
//        return;
//    }
//
//    for (int i = ui->model_choose->count() - 1; i >= 0; --i)
//    {
//        RemoveModel remove_command(i);
//        _facade->execute(remove_command);
//
//        ui->model_choose->removeItem(i);
//    }
//
//    updateScene();
//}

void MainWindow::on_load_camera_btn_clicked() {
    std::cout << "load_camera_btn clicked\n";

    auto file = QFileDialog::getOpenFileName();
    auto load_camera_cmd = std::make_shared<LoadCamera>(file.toUtf8().data());

    try
    {
        this->facade->execute(load_camera_cmd);

        auto cam_chooser = this->ui->camera_choose;
        int num = cam_chooser->count() ? cam_chooser->itemText(cam_chooser->count() - 1).toInt() + 1 : 1;
        cam_chooser->addItem(QString::number(num));
        cam_chooser->setCurrentIndex(cam_chooser->count() - 1);
    }
    catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_add_camera_btn_clicked() {
    std::cout << "add_camera_btn clicked\n";

    auto r_content = ui->graphicsView->contentsRect();
    auto add_camera_cmd = std::make_shared<AddCamera>(-r_content.width() / 2.0, -r_content.height() / 2.0, 0.0);
//    auto add_camera_cmd = std::make_shared<AddCamera>(0.0, 0.0, 0.0);

    try
    {
        this->facade->execute(add_camera_cmd);
        this->updateScene();

        auto cam_chooser = this->ui->camera_choose;
        int num = cam_chooser->count() ? cam_chooser->itemText(cam_chooser->count() - 1).toInt() + 1 : 1;
        cam_chooser->addItem(QString::number(num));
        cam_chooser->setCurrentIndex(cam_chooser->count() - 1);
    }
    catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_remove_camera_btn_clicked() {
    std::cout << "remove_cam_btn clicked\n";

//    try
//    {
//        check_cam_exist();
//    } catch (const CameraError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять камеру, добавьте хотя бы одну.");
//        return;
//    }

    auto camera_chooser = this->ui->camera_choose;
    auto remove_camera_cmd = std::make_shared<RemoveCamera>(camera_chooser->currentIndex());

//    try
//    {
//        check_can_delete_cam();
//    } catch (const CameraError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять камеру, необходимо удалить оставшиеся модели.");
//        return;
//    }

    try
    {
        this->facade->execute(remove_camera_cmd);
        camera_chooser->removeItem(camera_chooser->currentIndex());
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }


//    try
//    {
//        check_cam_exist();
//    } catch (const CameraError &error)
//    {
//        return;
//    }

}

void MainWindow::change_cam() {
    std::cout << "change_cam clicked\n";

//    try
//    {
//        check_cam_exist();
//    } catch (const CameraError &error)
//    {
//        return;
//    }
    auto camera_set_cmd = std::make_shared<SetCamera>(this->ui->camera_choose->currentIndex());

    try
    {
        this->facade->execute(camera_set_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_right_btn_clicked() {
    std::cout << "right_btn clicked\n";

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->ui->camera_choose->currentIndex(), 10, 0);

    try
    {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
    //    try
//    {
//        check_cam_exist();
//        check_models_exist();
//    } catch (const CameraError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
//        return;
//    } catch (const ModelError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
//        return;
//    }
}

void MainWindow::on_up_btn_clicked() {
    std::cout << "up_btn clicked\n";

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->ui->camera_choose->currentIndex(), 0, -10);

    try
    {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }

    //    try
//    {
//        check_cam_exist();
//        check_models_exist();
//    } catch (const CameraError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
//        return;
//    } catch (const ModelError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
//        return;
//    }
}

void MainWindow::on_down_btn_clicked() {
    std::cout << "down_btn clicked\n";

    auto camera_move_cmd = std::make_shared<MoveCamera>(this->ui->camera_choose->currentIndex(), 0, 10);

    try
    {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
    //    try
//    {
//        check_cam_exist();
//        check_models_exist();
//    } catch (const CameraError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
//        return;
//    } catch (const ModelError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
//        return;
//    }
}

void MainWindow::on_left_btn_clicked() {
    std::cout << "left_btn clicked\n";
    auto camera_move_cmd = std::make_shared<MoveCamera>(this->ui->camera_choose->currentIndex(), -10, 0);

    try
    {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
    //    try
//    {
//        check_cam_exist();
//        check_models_exist();
//    } catch (const CameraError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
//        return;
//    } catch (const ModelError &error)
//    {
//        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
//        return;
//    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    this->scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

    auto r_content = ui->graphicsView->contentsRect();
    this->scene->setSceneRect(0, 0, r_content.width(), r_content.height());
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    this->setup_scene();

    this->facade = std::make_shared<Facade>(Facade());

//    connect(ui->load_model_btn, &QPushButton::clicked, this, &MainWindow::on_load_model_btn_clicked);
//    connect(ui->remove_model_btn, &QPushButton::clicked, this, &MainWindow::on_remove_model_btn_clicked);
//
//    connect(ui->load_camera_btn, &QPushButton::clicked, this, &MainWindow::on_load_camera_btn_clicked);
//    connect(ui->add_camera_btn, &QPushButton::clicked, this, &MainWindow::on_add_camera_btn_clicked);
//    connect(ui->remove_camera_btn, &QPushButton::clicked, this, &MainWindow::on_remove_camera_btn_clicked);
//    connect(ui->clear_screen, &QPushButton::clicked, this, &MainWindow::clear_scene);
//
//    connect(ui->right_btn, &QPushButton::clicked, this, &MainWindow::on_right_btn_clicked);
//    connect(ui->up_btn, &QPushButton::clicked, this, &MainWindow::on_up_btn_clicked);
//    connect(ui->down_btn, &QPushButton::clicked, this, &MainWindow::on_down_btn_clicked);
//    connect(ui->left_btn, &QPushButton::clicked, this, &MainWindow::on_left_btn_clicked);
//
//    connect(ui->move_btn, &QPushButton::clicked, this, &MainWindow::on_move_btn_clicked);
//    connect(ui->scale_btn, &QPushButton::clicked, this, &MainWindow::on_scale_btn_clicked);
//    connect(ui->rotate_btn, &QPushButton::clicked, this, &MainWindow::on_rotate_btn_clicked);
//
    connect(ui->camera_choose, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::change_cam);
}

MainWindow::~MainWindow() { delete this->ui; }
