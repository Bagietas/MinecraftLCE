#include "net/minecraft/world/entity/GlobalEntity.h"

class LightningBolt : public GlobalEntity {
public:
    LightningBolt(Level* level, double x, double y, double z, bool onlyVisual);

    eINSTANCEOF GetType() override;
    void defineSynchedData() override;
    void tick() override;
    bool shouldRender(double) override;
    void readAdditionalSaveData(CompoundTag*) override;
    void addAdditonalSaveData(CompoundTag*) override;
    SoundSource::ESoundSource getSoundSource() override;
};