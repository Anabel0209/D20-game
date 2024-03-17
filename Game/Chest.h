#pragma once
#include "Container.h"
#include "Cell.h"

class Chest : public Container, public Cell {
public:
    Chest(const Item& item, int x, int y);
    virtual ~Chest();
    virtual Item Open();
    virtual void Put(Item& item);

    bool wasOpened() const;
private:
    bool openStatus;
};