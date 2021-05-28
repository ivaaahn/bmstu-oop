#include <doors/doors.h>

#include <QDebug>

Doors::Doors(QObject *parent) : QObject(parent), curr_state(OPEN) {
    this->passenger_waiting_timer.setInterval(PASSENGER_WAITING_DELAY);
    this->passenger_waiting_timer.setSingleShot(true);
    this->open_timer.setSingleShot(true);
    this->close_timer.setSingleShot(true);


    QObject::connect(&this->open_timer, SIGNAL(timeout()), this, SLOT(handleOpening()));
    QObject::connect(this, SIGNAL(opened()), &this->passenger_waiting_timer, SLOT(start()));
    QObject::connect(&this->passenger_waiting_timer, SIGNAL(timeout()), this, SLOT(prepareToGo()));
    QObject::connect(&this->close_timer, SIGNAL(timeout()), this, SLOT(handleClosing()));
}

void Doors::doOpen() {
    if (this->curr_state != CLOSING && this->curr_state != CLOSED) return;

    if (this->curr_state == CLOSED)
    {
        this->open_timer.start(DOORS_DEFAULT_DELAY);
    }
    else
    {
        qDebug() << "Прерываю закрытие дверей...";
        int remaining_time = this->close_timer.remainingTime();
        this->close_timer.stop();
        this->open_timer.start(DOORS_DEFAULT_DELAY - remaining_time);
    }

    this->curr_state = OPENING;
    qDebug() << "Двери открываются...";
}

void Doors::prepareToGo() {
    if (this->curr_state != OPEN && this->curr_state != CLOSED) return;

    if (this->curr_state == CLOSED)
    {
        emit readyToGo();
    }
    else
    {
        this->curr_state = CLOSING;
        qDebug() << "Двери закрываются...";
        this->close_timer.start(DOORS_DEFAULT_DELAY);
    }
}

void Doors::handleOpening() {
    if (this->curr_state != OPENING) return;

    this->curr_state = OPEN;
    qDebug() << "Двери открыты.\nОжидание пассажиров...";

    emit opened();
}

void Doors::handleClosing() {
    if (this->curr_state != CLOSING) return;

    this->curr_state = CLOSED;
    qDebug() << "Двери закрыты.";

    emit readyToGo();
}

