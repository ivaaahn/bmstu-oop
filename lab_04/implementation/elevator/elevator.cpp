#include "elevator/elevator.h"

Elevator::Elevator() {
    QObject::connect(&control_panel, SIGNAL(gotNewTarget(int,Direction)), &cabin, SLOT(doMove(int,Direction)));
    QObject::connect(&cabin, SIGNAL(floorPassed(int,Direction)), &control_panel, SLOT(passedFloor(int)));
    QObject::connect(&cabin, SIGNAL(stopped(int)), &control_panel, SLOT(confirmArrival(int)));
}

void Elevator::click(const int btn_number) {
    control_panel.setNewTarget(btn_number);
}
