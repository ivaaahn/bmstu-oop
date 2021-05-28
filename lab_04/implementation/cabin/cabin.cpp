#include "cabin/cabin.h"

#include <QString>

#include <QDebug>


Cabin::Cabin(QObject *parent) : QObject(parent), curr_floor(START_FLOOR), target_floor(NO_TARGET),
                                curr_state(STOP), direction(STAY) {

    pass_floor_timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(called()), &this->doors, SLOT(doClose()));

    QObject::connect(this, SIGNAL(arrived(int)), this, SLOT(doStop()));

    QObject::connect(this, SIGNAL(stopped(int)), &this->doors, SLOT(doOpen()));

    QObject::connect(&this->doors, SIGNAL(closed()), this, SLOT(doMove()));

    QObject::connect(&this->pass_floor_timer, SIGNAL(timeout()), this, SLOT(doMove()));
}


void Cabin::goNextFloor() {
    this->curr_floor += this->direction;
    emit floorPassed(this->curr_floor);
}

void Cabin::doMove() {
    if (this->curr_state == WAIT)
    {
        this->curr_state = MOVE;
    }
    else if (this->curr_state == MOVE)
    {
        this->goNextFloor();
    }
    else
    {
        qDebug() << "Лифт ожидает на" << this->curr_floor << "этаже";
        this->direction = STAY;
        return;
    }

    if (this->curr_floor == this->target_floor)
            emit arrived(this->curr_floor);
    else
        this->pass_floor_timer.start(ONE_FLOOR_PASS_TIME);
}

void Cabin::doStop() {
    if (this->curr_state != MOVE) return;

    this->curr_state = STOP;
    qDebug() << "Лифт остановился | ЭТАЖ №" << QString::number(this->curr_floor);

    emit stopped(this->curr_floor);
}

void Cabin::handleCall(int floor, Direction dir) {
    this->target_floor = floor;
    this->direction = dir;

    if (this->curr_state == STOP)
    {
        this->curr_state = WAIT;
        emit called();

//        if (this->curr_floor == this->target_floor)
//            emit stopped(floor);
//        else
//        {
//            this->curr_state = WAIT;
//            emit called();
//        }
    }
}

