#include <controller/controller.h>

#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent), curr_floor(START_FLOOR), main_target(NO_TARGET),
                                          need_visit(NUM_OF_FLOORS, false), state(FREE),
                                          direction(STAY) {
    QObject::connect(this, SIGNAL(targetsFound(int)), this, SLOT(targetSetting(int)));
}

void Controller::setTarget(const int floor) {
    if (this->need_visit[floor - 1]) return;

    this->state = BUSY;

    this->need_visit[floor - 1] = true;
    if (this->updateMainTarget(floor)) this->updateDirection();

    emit targetIsSet(this->findNextTarget(), this->direction);
}


void Controller::targetUpdating() {
    if (this->state != BUSY) return;

    this->state = FREE;
    this->need_visit[this->curr_floor - 1] = false;

    auto new_target = this->findMainTarget();
    if (this->curr_floor == this->main_target && new_target == NO_TARGET)
    {
        this->direction = STAY;
        this->main_target = NO_TARGET;
    }
    else
    {
        emit targetsFound(new_target);
    }
}

void Controller::targetSetting(const int new_floor) {
    if (this->state == FREE)
    {
        this->state = BUSY;

        if (this->curr_floor == this->main_target && new_floor != NO_TARGET)
        {
            this->main_target = new_floor;
            this->updateDirection();
        }
        emit targetIsSet(this->findNextTarget(), this->direction);
    }
    else
    {
        this->state = BUSY;

        this->curr_floor = new_floor;
        qDebug() << "Лифт движется | Этаж №" << new_floor;
    }
}

int Controller::findMainTarget() {
    int target = NO_TARGET;

    if (this->direction == UP)
    {
        for (int i = 1; i <= this->curr_floor && target == NO_TARGET; ++i)
            if (this->need_visit[i - 1]) target = i;
    }
    else
    {
        for (int i = NUM_OF_FLOORS; i >= this->curr_floor && target == NO_TARGET; --i)
            if (this->need_visit[i - 1]) target = i;
    }

    return target;
}

bool Controller::updateMainTarget(const int floor) {
    bool is_updated = false;

    if ((this->main_target == NO_TARGET) ||
        (this->direction == UP && floor > this->main_target) ||
        (this->direction == DOWN && floor < this->main_target))
    {
        is_updated = true;
        this->main_target = floor;
    }

    return is_updated;
}

int Controller::findNextTarget() {
    int target = NO_TARGET;

    if (this->main_target > this->curr_floor)
    {
        for (int i = this->curr_floor; i <= this->main_target && target == NO_TARGET; ++i)
            if (this->need_visit[i - 1]) target = i;
    }
    else
    {
        for (int i = this->curr_floor; i >= this->main_target && target == NO_TARGET; --i)
            if (this->need_visit[i - 1]) target = i;
    }

    return target;
}

void Controller::updateDirection() {
    this->direction = main_target < curr_floor ? DOWN : UP;
}
