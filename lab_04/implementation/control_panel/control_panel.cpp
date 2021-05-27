#include <control_panel/control_panel.h>

#include <iostream>

#include <QDebug>

ControlPanel::ControlPanel(QObject *parent) : QObject(parent), curr_floor(START_FLOOR), curr_target(NO_TARGET),
                                              is_floor_to_stop(NUM_OF_FLOORS, false), curr_state(FREE), curr_direction(NONE) {}

void ControlPanel::setNewTarget(int new_target) {
    this->curr_state = BUSY;
    this->is_floor_to_stop[new_target - 1] = true;

    if ((this->curr_direction == UP && new_target > this->curr_target) ||
        (this->curr_direction == DOWN && new_target < this->curr_target) ||
        (this->curr_target == NO_TARGET))
    {

        this->curr_target = new_target;
    }

    this->nextTarget(new_target);
    this->curr_direction = (this->curr_target > this->curr_floor) ? UP : DOWN;

    emit gotNewTarget(new_target, this->curr_direction);
}

void ControlPanel::confirmArrival(int floor) {
    if (this->curr_state != BUSY) return;

    this->curr_floor = floor;
    this->is_floor_to_stop[floor - 1] = false;

    if (this->curr_floor == this->curr_target)
    {
        this->curr_target = NO_TARGET;
        this->findNewTarget();
    }

    if (this->nextTarget(floor))
    {
        this->curr_direction = (curr_target > curr_floor) ? UP : DOWN;
        emit gotNewTarget(floor, curr_direction);
    }
    else
    {
        this->curr_state = FREE;
    }
}

void ControlPanel::passedFloor(const int new_floor) {
    this->curr_floor = new_floor;
    qDebug() << "ELEVATOR IS MOVING | FLOOR #" << new_floor;
}

void ControlPanel::findNewTarget() {
    int state = false;

    if (this->curr_direction == UP)
    {
        for (int i = NUM_OF_FLOORS; i >= 1 && !state; --i)
        {
            if (this->is_floor_to_stop[i - 1])
            {
                state = true;
                this->curr_target = i;
            }
        }
    }
    else
    {
        for (int i = 1; i <= NUM_OF_FLOORS && !state; ++i)
        {
            if (this->is_floor_to_stop[i - 1])
            {
                state = true;
                this->curr_target = i;
            }
        }
    }
}

bool ControlPanel::nextTarget(int &floor) {
    bool state = false;

//    Есть ли этажи на данном маршруте, на которых нужно остановиться? (Данный маршрут - имеется ввиду согласно направлению)
    if (this->curr_target > this->curr_floor)
    {
        bool flag = true;
        for (int i = this->curr_floor; i <= NUM_OF_FLOORS && flag; ++i)
        {
            if (this->is_floor_to_stop[i - 1])
            {
                floor = i;
                state = true;
                flag = false;
            }
        }
    }
    else
    {
        bool flag = true;
        for (int i = curr_floor; i >= 1 && flag; --i)
        {
            if (this->is_floor_to_stop[i - 1])
            {
                floor = i;
                state = true;
                flag = false;
            }
        }
    }

    return state;
}
