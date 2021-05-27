#pragma once

#include <QObject>
#include <QTextEdit>

#include <cabin/cabin.h>
#include <control_panel/control_panel.h>

class Elevator : public QObject {
Q_OBJECT

public:
    Elevator();

    void click(int btn_number);

private:
    ControlPanel control_panel;
    Cabin cabin;
};
