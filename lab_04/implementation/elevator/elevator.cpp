#include "elevator/elevator.h"

Elevator::Elevator() {
    QObject::connect(&controller, SIGNAL(go(int, Direction)), &cabin, SLOT(handleCall(int, Direction)));
    QObject::connect(&cabin, SIGNAL(floorPassed(int)), &controller, SLOT(handleFloorPass(int)));
    QObject::connect(&cabin, SIGNAL(stopped(int)), &controller, SLOT(handleStopping(int)));
}

void Elevator::click_btn(const int btn_number) {
    controller.addTarget(btn_number);
}
