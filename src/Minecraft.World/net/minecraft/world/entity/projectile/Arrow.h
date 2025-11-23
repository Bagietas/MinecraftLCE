#pragma once

#include "net/minecraft/world/entity/Entity.h"
#include "net/minecraft/world/entity/projectile/Projectile.h"

class Arrow : public Entity, public Projectile {
public:
    static Predicate<std::shared_ptr<Entity>>* ARROW_TARGETS;

    void setCritArrow(bool);
};
