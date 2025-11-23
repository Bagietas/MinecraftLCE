#pragma once

#include "net/minecraft/core/BlockPos.h"
#include <memory>

class Vec3;
class Direction;
class Entity;

class HitResult {
public:
    enum Type { MISS, BLOCK, ENTITY };

    ~HitResult();
    HitResult(Vec3*, const Direction*, const BlockPos&);
    HitResult(std::shared_ptr<Entity>);

    const BlockPos& getBlockPos() const;

    BlockPos mBlockPos;
    Type mHitType;
    const Direction* mDirection;
    Vec3* mHitVector;
    std::shared_ptr<Entity> mEntity;
};
