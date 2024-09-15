#pragma once

#include "Minecraft.World/ArrayWithLength.h"

class DataInput {
public:
    virtual ~DataInput();
    virtual void readBoolean() = 0;
    virtual unsigned char readByte() = 0;
    virtual void readUnsignedByte() = 0;
    virtual void readUnsignedShort() = 0;
    virtual char readChar() = 0;
    virtual void readFully(arrayWithLength<unsigned char>) = 0;
    virtual void readFully(arrayWithLength<char>) = 0;
    virtual void readBytes(arrayWithLength<unsigned char>) = 0;
    virtual double readDouble() = 0;
    virtual float readFloat() = 0;
    virtual int readInt() = 0;
    virtual long readLong() = 0;
    virtual short readShort() = 0;
    virtual void readUTF() = 0;
    virtual void readUTFChar() = 0;
    virtual void readPlayerUID() = 0;
    virtual void skipBytes(long long) = 0;
};