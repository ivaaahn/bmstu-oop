#include <controller/controller.h>

#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent), curr_floor(START_FLOOR), main_target(NO_TARGET),
                                          need_visit(NUM_OF_FLOORS, false), curr_state(FREE),
                                          curr_direct(STAY), nearest_target(NUM_OF_FLOORS + 1) {}

void Controller::addTarget(const int floor) {
    if (this->need_visit[floor - 1]) return;

    this->curr_state = BUSY;
    this->need_visit[floor - 1] = true;

    if (this->updateMainTarget(floor)) this->updateDirection();

    if (this->updateNearestTarget(floor)) emit nearestTargetChanged(this->nearest_target, this->curr_direct);
}


void Controller::handleStopping(const int floor) {
    if (this->curr_state != BUSY) return;

    this->need_visit[floor - 1] = false;


    if (this->curr_floor == this->main_target)
    {
        if (this->findMainTarget())
        {
            this->updateDirection();
        }
        else
        {
            this->resetParams();
            return;
        }
    }

    this->findNearestTarget();
    emit nearestTargetChanged(this->nearest_target, this->curr_direct);
}

void Controller::handleFloorPass(const int new_floor) {
    this->curr_floor = new_floor;
    qDebug() << "Лифт движется | Этаж №" << new_floor;
}


bool Controller::findMainTarget() {
    int is_found = false;
    if (this->curr_direct == UP)
    {
        for (int i = 1; i <= this->curr_floor && !is_found; ++i)
            if (this->need_visit[i - 1]) this->main_target = i, is_found = true;
    }
    else
    {
        for (int i = NUM_OF_FLOORS; i >= this->curr_floor && !is_found; --i)
            if (this->need_visit[i - 1]) this->main_target = i, is_found = true;
    }

    return is_found;
}

bool Controller::findNearestTarget() {
    bool is_target_exist = false;

    if (this->main_target > this->curr_floor)
    {
        for (int i = this->curr_floor; i <= this->main_target && !is_target_exist; ++i)
            if (this->need_visit[i - 1]) this->nearest_target = i, is_target_exist = true;
    }
    else
    {
        for (int i = this->curr_floor; i >= this->main_target && !is_target_exist; --i)
            if (this->need_visit[i - 1]) this->nearest_target = i, is_target_exist = true;
    }

    return is_target_exist;
}

void Controller::updateDirection() {
    this->curr_direct = main_target < curr_floor ? DOWN : UP;
}

bool Controller::updateMainTarget(const int floor) {
    bool is_updated = false;

    if ((this->main_target == NO_TARGET) ||
        (this->curr_direct == UP && floor > this->main_target) ||
        (this->curr_direct == DOWN && floor < this->main_target))
    {
        is_updated = true;
        this->main_target = floor;
    }

    return is_updated;
}

bool Controller::updateNearestTarget(const int floor) {
    bool is_updated = false;

    if ((this->nearest_target == NO_TARGET) ||
        (this->curr_direct == UP && floor < this->nearest_target && floor > this->curr_floor) ||
        (this->curr_direct == DOWN && floor > this->nearest_target && floor < this->curr_floor))
    {
        is_updated = true;
        this->nearest_target = floor;
    }

    return is_updated;
}

void Controller::resetParams() {
    this->main_target = NO_TARGET;
    this->nearest_target = NO_TARGET;
    this->curr_state = FREE;
    this->curr_direct = STAY;
}



