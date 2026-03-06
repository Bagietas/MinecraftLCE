#pragma once

#include "net/minecraft/world/item/FoodItem.h"
class SeedFoodItem : public FoodItem {
public:
    SeedFoodItem(int nutrition, float saturation, Block* seedBlock, Block* land);

    char fill[40];
};