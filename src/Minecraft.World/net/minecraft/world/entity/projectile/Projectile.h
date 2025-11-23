#pragma once

#include <memory>

class Entity;
class HitResult;
class Level;
class LivingEntity;

class Projectile {
public:
    Projectile(Level*, const std::shared_ptr<LivingEntity>&);

    virtual ~Projectile();
    virtual void shoot(double, double, double, float, float) = 0;
    virtual void shootFromRotation(std::shared_ptr<Entity>, float, float, float, float, float) = 0;
    virtual bool onHit(const HitResult*);
};
