#pragma once

#include <QObject>

#include <constants.h>

class Doors : public QObject {
Q_OBJECT
    enum DoorsState { OPENING, OPENED, CLOSING, CLOSED };

public:
    explicit Doors(QObject *parent = nullptr);

signals:

    void closed();

    void opened();

public slots:

    void doorsOpening();

    void doorsClosing();

private slots:

    void doorsOpen();

    void doorsClose();

private:
    DoorsState curr_state;
    QTimer open_timer;
    QTimer close_timer;
    QTimer passenger_waiting_timer;
};
