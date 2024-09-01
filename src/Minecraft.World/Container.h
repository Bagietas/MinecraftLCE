#pragma once

#include "Minecraft.World/Nameable.h"
#include "types.h"

class Slot;
class ItemInstance;

class Container : public Nameable {
public:
    virtual ~Container();
    virtual void pure_virtual7() = 0;
    virtual void pure_virtual8() = 0;
    virtual not_null_ptr<ItemInstance> getItem(int slot) = 0;
    virtual std::shared_ptr<ItemInstance> removeItem(int slot, int n) = 0;
    virtual void pure_virtual10() = 0;
    virtual void setItem(int slot, not_null_ptr<ItemInstance> item) = 0;
    virtual int getMaxStackSize() = 0;
    virtual void setChanged() = 0;
    virtual void pure_virtual14() = 0;
    virtual void pure_virtual15() = 0;
    virtual void pure_virtual16() = 0;
    virtual void pure_virtual17() = 0;
    virtual void pure_virtual18() = 0;
    virtual void pure_virtual19() = 0;
    virtual void pure_virtual20() = 0;
};