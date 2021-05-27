#include "elevator/elevator.h"

Elevator::Elevator() {
    QObject::connect(&control_panel, SIGNAL(go(int,Direction)), &cabin, SLOT(handleCall(int,Direction)));
    QObject::connect(&cabin, SIGNAL(floorPassed(int,Direction)), &control_panel, SLOT(handleFloorPass(int)));
    QObject::connect(&cabin, SIGNAL(stopped(int)), &control_panel, SLOT(handleArrival(int)));
}

void Elevator::click(const int btn_number) {
    control_panel.setNewTarget(btn_number);
}
