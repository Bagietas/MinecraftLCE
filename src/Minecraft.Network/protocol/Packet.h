#pragma once

#include <deque>
#include <memory>
#include "Minecraft.Network/PacketType.h"
#include "types.h"

class DataInputStream;
class DataOutputStream;
class PacketListener;

class Packet {
public:
    static std::shared_ptr<Packet> readPacket(DataInputStream*, bool, unsigned int&, bool&);
    static void writePacket(std::shared_ptr<Packet>, DataOutputStream*, bool, unsigned int&);

    Packet();
    virtual ~Packet();
    virtual EPacketType getPacketId() = 0;
    virtual void read(DataInputStream* input) = 0;
    virtual void write(DataOutputStream* output) = 0;
    virtual void handle(PacketListener* listener);
    virtual int getEstimatedSize();
    virtual bool canBeInvalidated();
    virtual bool isInvalidatedBy(std::shared_ptr<Packet> packet);
    virtual bool isAync();
    virtual bool tryReplaceDuplicatePacket(std::deque<std::shared_ptr<Packet>>* duplicatePacket);

    long mCreatedTime;
    bool mShouldDelay;
};

ASSERT_SIZEOF(Packet, 0x18)