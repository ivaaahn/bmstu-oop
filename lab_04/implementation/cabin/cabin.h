#pragma once

#include <QObject>

#include <constants.h>
#include <controller/controller.h>
#include <doors/doors.h>

class Cabin : public QObject {
Q_OBJECT
    enum CabinState { MOVE, PROCESSING, STOP, LOCKED, UNLOCKED };

public:
    explicit Cabin(QObject *parent = nullptr);

signals:

    void unlocked();

    void locked();

    void processed();

    void floorPassed(int floor);

    void arrived(int floor);

    void stopped(int floor);

public slots:

    void cabinLocking();

    void cabinUnlocking();

    void cabinProcessing(int floor, Direction dir);

    void cabinMoving();

    void cabinStopping();


private:
    int curr_floor;
    int target_floor;

    CabinState state;
    Direction direction;

    Doors doors;
    QTimer pass_floor_timer;

    void goNextFloor();
};
