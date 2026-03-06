#pragma once

#include "net/minecraft/world/entity/Entity.h"
#include <string>

class ItemEntity : public Entity {
public:
    ItemEntity(Level*, double, double, double, not_null_ptr<ItemInstance>);

    eINSTANCEOF GetType() override;
    void defineSynchedData() override;
    void tick() override;
    bool makeStepSound() override;
    void burn(int) override;
    void updateInWaterState() override;
    void playerTouch(std::shared_ptr<Player>) override;
    bool hurt(DamageSource*, float) override;
    void readAdditionalSaveData(CompoundTag*) override;
    void addAdditonalSaveData(CompoundTag*) override;
    std::wstring getName() override;
    bool isAttackable() override;
    void changeDimension(int) override;

    void setNoPickUpDelay();
    void setOwner(const std::wstring&);
    void makeFakeItem();
    not_null_ptr<ItemInstance> getItem();

    static void staticCtor();

    void* padding[8];
};