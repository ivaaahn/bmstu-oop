#pragma once

#include <QMainWindow>
#include "elevator/elevator.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    void onCabinBtnClicked(int btn_number);

private slots:

    void onFloorBtnClicked(int btn_number);

private:
    Ui::MainWindow *ui;
    Elevator lift;
};