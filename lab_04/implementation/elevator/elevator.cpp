#include "elevator/elevator.h"

Elevator::Elevator() {
    QObject::connect(&controller, SIGNAL(targetIsSet(int, Direction)), &cabin, SLOT(cabinProcessing(int, Direction)));
    QObject::connect(&cabin, SIGNAL(floorPassed(int)), &controller, SLOT(targetSetting(int)));
    QObject::connect(&cabin, SIGNAL(cabinUnlocked()), &controller, SLOT(targetUpdating()));

}

void Elevator::click_btn(const int btn_number) {
    controller.addTarget(btn_number);
}
