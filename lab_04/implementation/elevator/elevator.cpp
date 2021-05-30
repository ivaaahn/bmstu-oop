#include "elevator/elevator.h"

Elevator::Elevator() {
    QObject::connect(&controller, SIGNAL(targetIsSet(int, Direction)), &cabin, SLOT(cabinPreparing(int, Direction)));
    QObject::connect(&cabin, SIGNAL(floorPassed(int)), &controller, SLOT(targetSetting(int)));
    QObject::connect(&cabin, SIGNAL(unlocked()), &controller, SLOT(targetUpdating()));
}

void Elevator::click_btn(const int btn_number) {
    controller.setTarget(btn_number);
}
