#include <doors/doors.h>

#include <QDebug>

Doors::Doors(QObject *parent) : QObject(parent), curr_state(CLOSED) {
    this->passenger_waiting_timer.setInterval(PASSENGER_WAITING_DELAY);
    this->passenger_waiting_timer.setSingleShot(true);
    this->open_timer.setSingleShot(true);
    this->close_timer.setSingleShot(true);


    QObject::connect(&this->open_timer, SIGNAL(timeout()), this, SLOT(doorsOpen()));
    QObject::connect(this, SIGNAL(opened()), &this->passenger_waiting_timer, SLOT(start()));
    QObject::connect(&this->passenger_waiting_timer, SIGNAL(timeout()), this, SLOT(doorsClosing()));
    QObject::connect(&this->close_timer, SIGNAL(timeout()), this, SLOT(doorsClose()));
}

void Doors::doorsOpening() {
    if (this->curr_state != CLOSING && this->curr_state != CLOSED) return;

    if (this->curr_state == CLOSED)
    {
        this->curr_state = OPENING;
        this->open_timer.start(DOORS_DEFAULT_DELAY);
    }
    else
    {
        this->curr_state = OPENING;
        qDebug() << "Прерываю закрытие дверей...";
        int remaining_time = this->close_timer.remainingTime();
        this->close_timer.stop();
        this->open_timer.start(DOORS_DEFAULT_DELAY - remaining_time);
    }

    qDebug() << "Двери открываются...";
}

void Doors::doorsClosing() {
    if (this->curr_state != OPENED) return;

    this->curr_state = CLOSING;

    this->close_timer.start(DOORS_DEFAULT_DELAY);
    qDebug() << "Двери закрываются...";
}

void Doors::doorsOpen() {
    if (this->curr_state != OPENING) return;

    this->curr_state = OPENED;
    qDebug() << "Двери открыты.\nОжидание пассажиров...";

    emit opened();
}

void Doors::doorsClose() {
    if (this->curr_state != CLOSING) return;

    this->curr_state = CLOSED;
    qDebug() << "Двери закрыты.";

    emit closed();
}

