#include <doors/doors.h>

#include <QDebug>

Doors::Doors(QObject *parent) : QObject(parent), curr_state(CLOSED) {
    this->waiting_passengers_timer.setInterval(WAITING_TIME);
    this->waiting_passengers_timer.setSingleShot(true);
    QObject::connect(&this->waiting_passengers_timer, SIGNAL(timeout()), this, SLOT(doClose()));
    QObject::connect(this, SIGNAL(opened()), &this->waiting_passengers_timer, SLOT(start()));


    this->open_timer.setSingleShot(true);
    QObject::connect(&this->open_timer, SIGNAL(timeout()), this, SLOT(confirmOpening()));

    this->close_timer.setSingleShot(true);
    QObject::connect(&this->close_timer, SIGNAL(timeout()), this, SLOT(confirmClosing()));
}

void Doors::doOpen() {
    if (this->curr_state != CLOSED && this->curr_state != CLOSING)  return;

    if (this->curr_state == CLOSED)
    {
        this->curr_state = OPENING;
        qDebug() << "DOORS: OPENING";

        this->open_timer.start(DOORS_DEFAULT_DELAY);
    }
    else
    {
        this->curr_state = OPENING;
        qDebug() << "DOORS: OPENING";

        int remaining_time = this->close_timer.remainingTime();
        this->close_timer.stop();
        this->open_timer.start(DOORS_DEFAULT_DELAY - remaining_time);
    }
}

void Doors::doClose() {
    if (this->curr_state != OPEN && this->curr_state != CLOSED) return;

    if (this->curr_state == CLOSED)
        emit closed();
    else
    {
        this->curr_state = CLOSING;
        qDebug() << "DOORS: CLOSING";
        this->close_timer.start(DOORS_DEFAULT_DELAY);
    }
}

void Doors::confirmOpening() {
    if (this->curr_state != OPENING) return;

    this->curr_state = OPEN;
    qDebug() << "DOORS: OPEN | WAITING FOR PASSENGERS";

    emit opened();
}

void Doors::confirmClosing() {
    if (curr_state != CLOSING) return;

    this->curr_state = CLOSED;
    qDebug() << "DOORS: CLOSED";

    emit closed();
}
