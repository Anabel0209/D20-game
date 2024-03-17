#pragma once
#include "Cell.h"

class Door : Cell {
public:
    Door(int x, int y);
    virtual ~Door();

    void unlock();
    void lock();
    bool isLocked() const;

    int getX() const;
    int getY() const;
private:
    bool lockedStatus;
};