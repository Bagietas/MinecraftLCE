#pragma once

#include "net/minecraft/world/level/block/BaseEntityBlock.h"

class DyeColor;

class ShulkerBoxBlock : public BaseEntityBlock {
public:
    ShulkerBoxBlock(const DyeColor*);
};
