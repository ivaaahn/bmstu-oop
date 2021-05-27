#pragma once

#include <QObject>

#include <constants.h>

class Doors : public QObject {
Q_OBJECT
    enum DoorsState { OPENING, OPEN, CLOSING, CLOSED };

public:
    explicit Doors(QObject *parent = nullptr);

signals:

    void closed();

    void opened();

public slots:

    void doOpen();

    void doClose();

private slots:

    void confirmOpening();

    void confirmClosing();

private:
    DoorsState curr_state;
    QTimer open_timer;
    QTimer close_timer;
    QTimer waiting_passengers_timer;
};
