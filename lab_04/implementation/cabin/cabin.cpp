#include "cabin/cabin.h"

#include <QString>

#include <QDebug>


Cabin::Cabin(QObject *parent) : QObject(parent), curr_floor(START_FLOOR), target_floor(NO_TARGET),
                                new_target_is_received(false),
                                curr_state(STOP), curr_direction(NONE) {

    pass_floor_timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(called()), &this->doors, SLOT(doClose()));

    QObject::connect(this, SIGNAL(arrived(int)), this, SLOT(doStop()));

    QObject::connect(this, SIGNAL(stopped(int)), &this->doors, SLOT(doOpen()));

    QObject::connect(&this->doors, SIGNAL(closed()), this, SLOT(doMove()));

    QObject::connect(&this->pass_floor_timer, SIGNAL(timeout()), this, SLOT(doMove()));
}

void Cabin::doMove() {
    if (this->new_target_is_received && this->curr_state == WAIT)
    {
        this->curr_state = MOVE;

        if (this->curr_floor == this->target_floor)
                emit arrived(this->curr_floor);
        else
            this->pass_floor_timer.start(ONE_FLOOR_PASS_TIME);
    }
    else if (this->curr_state == MOVE)
    {
        this->curr_floor += this->curr_direction;

        if (this->curr_floor == this->target_floor)
        {
            emit floorPassed(this->curr_floor, this->curr_direction);
            emit arrived(this->curr_floor);
        }
        else
        {
            emit floorPassed(this->curr_floor, this->curr_direction);
            this->pass_floor_timer.start(ONE_FLOOR_PASS_TIME);
        }
    }
}

void Cabin::doStop() {
    if (this->curr_state != MOVE) return;

    this->curr_state = STOP;
    this->pass_floor_timer.stop(); // TODO
    qDebug() << "Лифт остановился | ЭТАЖ №" << QString::number(this->curr_floor);
    emit stopped(this->curr_floor);
}

void Cabin::handleCall(int floor, Direction dir) {
//    qDebug() << "Into Cabin::handleCall()";
//    if (this->curr_state != STOP) { qDebug() << "OOOPS"; return; } TODO


    this->new_target_is_received = true;
    this->target_floor = floor;
    this->curr_direction = dir;

    this->curr_state = WAIT;

//    qDebug() << "END Cabin::handleCall()";

    emit called();
}
