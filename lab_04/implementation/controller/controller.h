#pragma once

#include <QObject>
#include <QVector>

#include <constants.h>

class Controller : public QObject {
Q_OBJECT
    enum PanelState { FREE, BUSY, PROCESSING };

public:
    explicit Controller(QObject *parent = nullptr);

    void addTarget(int floor);

signals:

    void targetIsSet(int floor, Direction dir);

    void targetsNotFound();

    void targetsFound(int floor);

    void haveMainTarget(int floor);


public slots:

    void targetUpdating();

    void finishing();

    void targetSetting(int new_floor);

private:
    int curr_floor;
    int main_target;

    QVector<bool> need_visit;
    PanelState curr_state;
    Direction curr_direct;

    int findNextTarget();

    int findMainTarget();

    bool updateMainTarget(int floor);

    void updateDirection();
};
