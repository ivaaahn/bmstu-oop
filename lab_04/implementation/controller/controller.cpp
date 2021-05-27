#include <controller/controller.h>

#include <iostream>

#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent), curr_floor(START_FLOOR), main_target(NO_TARGET),
                                          is_floor_to_stop(NUM_OF_FLOORS, false), curr_state(FREE),
                                          curr_direction(NONE) {}

void Controller::setNewTarget(int floor) {
    this->curr_state = BUSY;
    this->is_floor_to_stop[floor - 1] = true;

    if ((this->curr_direction == UP && floor > this->main_target) ||
        (this->curr_direction == DOWN && floor < this->main_target) || (this->main_target == NO_TARGET))
    {
        this->main_target = floor;
    }

    this->findNearestFloor(floor);
    this->curr_direction = (this->main_target > this->curr_floor) ? UP : DOWN;

    emit go(floor, this->curr_direction);
}

void Controller::handleArrival(int floor) {
    if (this->curr_state != BUSY) return;

    this->curr_floor = floor;
    this->is_floor_to_stop[floor - 1] = false;

    if (this->curr_floor == this->main_target)
    {
        this->main_target = NO_TARGET;
        this->findNewMainTarget();
    }

    if (this->findNearestFloor(floor))
    {
        this->curr_direction = (this->main_target > this->curr_floor) ? UP : DOWN;
        emit go(floor, this->curr_direction);
    }
    else
    {
        this->curr_state = FREE;
    }
}

void Controller::handleFloorPass(const int new_floor) {
    this->curr_floor = new_floor;
    qDebug() << "Лифт движется | Этаж №" << new_floor;
}

void Controller::findNewMainTarget() {
    int is_found = false;

    if (this->curr_direction == UP)
    {
        for (int i = NUM_OF_FLOORS; i >= 1 && !is_found; --i)
            if (this->is_floor_to_stop[i - 1]) this->main_target = i, is_found = true;
    }
    else
    {
        for (int i = 1; i <= NUM_OF_FLOORS && !is_found; ++i)
            if (this->is_floor_to_stop[i - 1]) this->main_target = i, is_found = true;
    }
}

bool Controller::findNearestFloor(int &floor) {
    bool is_found = false;

    if (this->main_target > this->curr_floor)
    {
        for (int i = this->curr_floor; i <= this->main_target && !is_found; ++i)
            if (this->is_floor_to_stop[i - 1]) floor = i, is_found = true;
    }
    else
    {
        for (int i = curr_floor; i >= this->main_target && !is_found; --i)
            if (this->is_floor_to_stop[i - 1]) floor = i, is_found = true;
    }

    return is_found;
}
