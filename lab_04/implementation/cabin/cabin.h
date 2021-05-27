#pragma once

#include <QObject>

#include <constants.h>
#include <controller/controller.h>
#include <doors/doors.h>

class Cabin : public QObject {
Q_OBJECT
    enum CabinState { MOVE, WAIT, STOP };

public:
    explicit Cabin(QObject *parent = nullptr);

signals:

    void called();

    void floorPassed(int floor);

    void arrived(int floor);

    void stopped(int floor);

public slots:

    void doMove();

    void doStop();

    void handleCall(int floor, Direction dir);

private:
    int curr_floor;
    int target_floor;

    CabinState curr_state;
    Direction direction;

    Doors doors;
    QTimer pass_floor_timer;

    void goNextFloor();
};
