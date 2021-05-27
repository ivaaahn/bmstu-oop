#pragma once

#include <QObject>
#include <QVector>

#include <constants.h>

class ControlPanel : public QObject {
Q_OBJECT
    enum PanelState { FREE, BUSY };

public:
    explicit ControlPanel(QObject *parent = nullptr);

    void setNewTarget(int new_target);

signals:

    void gotNewTarget(int floor, Direction dir);

public slots:

    void confirmArrival(int floor);

    void passedFloor(int new_floor);

private:
    int curr_floor;
    int curr_target = -1; // TODO

    QVector<bool> is_floor_to_stop;
    PanelState curr_state;
    Direction curr_direction;

    bool nextTarget(int &floor);

    void findNewTarget();
};
