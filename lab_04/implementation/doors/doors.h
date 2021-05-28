#pragma once

#include <QObject>

#include <constants.h>

class Doors : public QObject {
Q_OBJECT
    enum DoorsState { OPENING, OPEN, CLOSING, CLOSED };

public:
    explicit Doors(QObject *parent = nullptr);

signals:

    void readyToGo();

    void opened();

public slots:

    void doOpen();

    void prepareToGo();

private slots:

    void handleOpening();

    void handleClosing();

private:
    DoorsState curr_state;
    QTimer open_timer;
    QTimer close_timer;
    QTimer passenger_waiting_timer;
};
