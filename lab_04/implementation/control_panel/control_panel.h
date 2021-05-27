#pragma once

#include <QObject>
#include <QVector>

#include <constants.h>

class ControlPanel : public QObject {
Q_OBJECT
    enum PanelState { FREE, BUSY };

public:
    explicit ControlPanel(QObject *parent = nullptr);

    void setNewTarget(int floor);

signals:

    void go(int floor, Direction dir);

public slots:

    void handleArrival(int floor);

    void handleFloorPass(int new_floor);

private:
    int curr_floor;
    int main_target = -1; // TODO

    QVector<bool> is_floor_to_stop;
    PanelState curr_state;
    Direction curr_direction;

    bool findNearestFloor(int &floor);

    void findNewMainTarget();
};
