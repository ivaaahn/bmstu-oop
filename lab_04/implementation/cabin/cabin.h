#pragma once

#include <QObject>

#include <constants.h>
#include <control_panel/control_panel.h>
#include <doors/doors.h>

class Cabin : public QObject {
Q_OBJECT
    enum CabinState { MOVE, WAIT, STOP };

public:
    explicit Cabin(QObject *parent = nullptr);

signals:

    void called();

    void floorPassed(int floor, Direction d);

    void arrived(int floor);

    void stopped(int floor);

public slots:

    void doMove();

    void doStop();

    void handleCall(int floor, Direction dir);

private:
    int curr_floor;
    CabinState curr_state;
    Direction curr_direction;

    int target_floor;
    bool new_target_is_received;

    Doors doors;
    QTimer pass_floor_timer;
};
