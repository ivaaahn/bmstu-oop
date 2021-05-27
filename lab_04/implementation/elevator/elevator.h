#pragma once

#include <QObject>
#include <QTextEdit>

#include <cabin/cabin.h>
#include <controller/controller.h>

class Elevator : public QObject {
Q_OBJECT

public:
    Elevator();

    void click(int btn_number);

private:
    Controller control_panel;
    Cabin cabin;
};
