#include "cabin/cabin.h"

#include <QString>

#include <QDebug>


Cabin::Cabin(QObject *parent) : QObject(parent), curr_floor(START_FLOOR), target_floor(NO_TARGET),
                                state(UNLOCKED), direction(STAY) {

    pass_floor_timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(arrived(int)), this, SLOT(cabinStopping()));

    QObject::connect(this, SIGNAL(stopped(int)), this, SLOT(cabinLocking()));

    QObject::connect(this, SIGNAL(locked()), &this->doors, SLOT(doorsOpening()));

    QObject::connect(&this->doors, SIGNAL(closed()), this, SLOT(cabinUnlocking()));

    QObject::connect(&this->pass_floor_timer, SIGNAL(timeout()), this, SLOT(cabinMoving()));

    QObject::connect(this, SIGNAL(processed()), this, SLOT(cabinMoving()));
}

void Cabin::goNextFloor() {
    this->curr_floor += this->direction;
    emit floorPassed(this->curr_floor);
}

void Cabin::cabinMoving() {
    if (this->state != PROCESSING && this->state != MOVE) return;

    if (this->state == PROCESSING)
    {
        this->state = MOVE;
    }
    else if (this->state == MOVE)
    {
        this->goNextFloor();
    }


    if (this->curr_floor == this->target_floor)
    {
        emit arrived(this->curr_floor);
    }
    else
    {
        this->pass_floor_timer.start(ONE_FLOOR_PASS_TIME);
    }
}

void Cabin::cabinStopping() {
    if (this->state != MOVE) return;

    this->state = STOP;
    qDebug() << "Лифт остановился | Этаж №" << QString::number(this->curr_floor);

    emit stopped(this->curr_floor);
}

void Cabin::cabinProcessing(int floor, Direction dir) {
    if (this->state != UNLOCKED) return;

    this->state = PROCESSING;

    this->target_floor = floor;
    this->direction = dir;

    emit processed();
}

void Cabin::cabinLocking() {
    if (this->state != STOP) return;

    this->state = LOCKED;
    qDebug() << "Движение кабины заблокировано";

    emit locked();
}

void Cabin::cabinUnlocking() {
    if (this->state != LOCKED) return;

    this->state = UNLOCKED;
    qDebug() << "Движение кабины разблокировано";

    emit unlocked();
}
