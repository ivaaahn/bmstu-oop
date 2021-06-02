#include <QDebug>
#include "design.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    qDebug() << "Этаж № 1 | Движение кабины разблокировано | Двери закрыты ";

    for (int i = 0; i < ui->cabin_buttons.size(); ++i)
    {
        connect(ui->cabin_buttons[i], &QPushButton::pressed, this, [i, this]() { onCabinBtnClicked(i + 1); });
    }

    for (int i = 0; i < ui->cabin_buttons.size(); ++i)
    {
        connect(ui->floor_buttons[i], &QPushButton::pressed, this, [i, this]() { onFloorBtnClicked(i + 1); });
    }
}


void MainWindow::onCabinBtnClicked(const int btn_number) {
    qDebug() << "Кабина | Нажата кнопка #" << btn_number;
    lift.click_btn(btn_number);
}

void MainWindow::onFloorBtnClicked(const int btn_number) {
    qDebug() << "Этаж №" << btn_number << "| Вызов лифта";
    lift.click_btn(btn_number);
}

MainWindow::~MainWindow() {
    delete ui;
}
