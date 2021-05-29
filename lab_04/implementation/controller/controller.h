#pragma once

#include <QObject>
#include <QVector>

#include <constants.h>

class Controller : public QObject {
Q_OBJECT
    enum PanelState { FREE, BUSY, PROCESSING };

public:
    explicit Controller(QObject *parent = nullptr);

    void setTarget(int floor);

signals:

    void targetIsSet(int floor, Direction dir);

    void targetsNotFound();

    void targetsFound(int floor);


public slots:

    void targetSetting(int new_floor);

    void targetUpdating();

    void finishing();

private:
    int curr_floor;
    int main_target;

    QVector<bool> need_visit;
    PanelState state;
    Direction direction;

    int findNextTarget();

    int findMainTarget();

    bool updateMainTarget(int floor);

    void updateDirection();
};
