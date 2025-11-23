#include "net/minecraft/network/protocol/game/ClientboundChatPacket.h"
#include "net/minecraft/world/damagesource/DamageSource.h"

class Entity;
class DamageSource;

class IndirectEntityDamageSource : public DamageSource {
public:
    IndirectEntityDamageSource(ClientboundChatPacket::EChatPacketMessage,
                               ClientboundChatPacket::EChatPacketMessage, std::shared_ptr<Entity>,
                               std::shared_ptr<Entity>, const DamageSource*)
};