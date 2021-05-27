#include <QDebug>
#include "design.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    qDebug() << "FLOOR #1 | DOORS: CLOSED | WAITING FOR...";

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
    qDebug() << "CABIN | PRESSED #" << btn_number;
    lift.click(btn_number);
}

void MainWindow::onFloorBtnClicked(const int btn_number) {
    qDebug() << "FLOOR #" << btn_number << "| CALLS";
    lift.click(btn_number);
}

MainWindow::~MainWindow() {
    delete ui;
}
