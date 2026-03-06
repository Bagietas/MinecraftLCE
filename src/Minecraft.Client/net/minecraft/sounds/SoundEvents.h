#pragma once

#include <string>

class SoundEvent;

class SoundEvents {
public:
    static SoundEvent* BACK;
    static SoundEvent* FIRE_AMBIENT;
    static SoundEvent* ENCHANT_THORNS_HIT;
    static SoundEvent* RANDOM_CLICK;
    static SoundEvent* SHOVEL_FLATTEN;
    static SoundEvent* GRASS_BREAK;
    static SoundEvent* GRASS_STEP;
    static SoundEvent* GRASS_PLACE;
    static SoundEvent* GRASS_HIT;
    static SoundEvent* GRASS_FALL;

    static SoundEvent* registerSound(const std::wstring&);

    static void staticCtor();
};
