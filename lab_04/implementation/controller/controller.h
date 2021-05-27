#pragma once

#include <QObject>
#include <QVector>

#include <constants.h>

class Controller : public QObject {
Q_OBJECT
    enum PanelState { FREE, BUSY };

public:
    explicit Controller(QObject *parent = nullptr);

    void addTarget(int floor);

signals:

    void go(int floor, Direction dir);

public slots:

    void handleStopping(int target_floor);

    void handleFloorPass(int new_floor);

private:
    int curr_floor;
    int main_target;
    int nearest_target;

    QVector<bool> need_visit;
    PanelState curr_state;
    Direction curr_direct;

    bool findNearestTarget();

    bool updateNearestTarget(int floor);

    bool findMainTarget();

    bool updateMainTarget(int floor);

    void updateDirection();

    void resetParams();
};
