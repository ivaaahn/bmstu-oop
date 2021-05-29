#include "cabin/cabin.h"

#include <QString>

#include <QDebug>


Cabin::Cabin(QObject *parent) : QObject(parent), curr_floor(START_FLOOR), target_floor(NO_TARGET),
                                curr_state(UNLOCKED), direction(STAY) {

    pass_floor_timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(cabinArrived(int)), this, SLOT(cabinStopping()));

    QObject::connect(this, SIGNAL(cabinStopped(int)), this, SLOT(cabinLocking()));

    QObject::connect(this, SIGNAL(cabinLocked()), &this->doors, SLOT(doorsOpening()));

    QObject::connect(&this->doors, SIGNAL(closed()), this, SLOT(cabinUnlocking()));

    QObject::connect(&this->pass_floor_timer, SIGNAL(timeout()), this, SLOT(cabinMoving()));

    QObject::connect(this, SIGNAL(cabinCalled()), this, SLOT(cabinMoving()));
}

void Cabin::goNextFloor() {
    this->curr_floor += this->direction;
    emit floorPassed(this->curr_floor);
}

void Cabin::cabinMoving() {
    if (this->curr_state != PROCESSING && this->curr_state != MOVE) return;

    if (this->curr_state == PROCESSING)
    {
        this->curr_state = MOVE;
    }
    else if (this->curr_state == MOVE)
    {
        this->goNextFloor();
    }


    if (this->curr_floor == this->target_floor)
    {
        emit cabinArrived(this->curr_floor);
    }
    else
    {
        this->pass_floor_timer.start(ONE_FLOOR_PASS_TIME);
    }
}

void Cabin::cabinStopping() {
    if (this->curr_state != MOVE) return;

    this->curr_state = STOP;
    qDebug() << "Лифт остановился | Этаж №" << QString::number(this->curr_floor);

    emit cabinStopped(this->curr_floor);
}

void Cabin::cabinProcessing(int floor, Direction dir) {
    if (this->curr_state != UNLOCKED) return;

    this->curr_state = PROCESSING;
//    qDebug() << "Кабина обрабатывает запросы...";

    this->target_floor = floor;
    this->direction = dir;

    emit cabinCalled();
}

void Cabin::cabinLocking() {
    if (this->curr_state != STOP) return;

    this->curr_state = LOCKED;
    qDebug() << "Движение кабины заблокировано";

    emit cabinLocked();
}

void Cabin::cabinUnlocking() {
    if (this->curr_state != LOCKED) return;

    this->curr_state = UNLOCKED;
    qDebug() << "Движение кабины разблокировано";

    emit cabinUnlocked();
}
