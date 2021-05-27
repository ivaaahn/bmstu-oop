#pragma once

#include <QObject>
#include <QTextEdit>

#include <cabin/cabin.h>
#include <controller/controller.h>

class Elevator : public QObject {
Q_OBJECT

public:
    Elevator();

    void click_btn(int btn_number);

private:
    Controller controller;
    Cabin cabin;
};
