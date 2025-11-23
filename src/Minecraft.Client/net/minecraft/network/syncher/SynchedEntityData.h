#pragma once

#include "net/minecraft/world/eINSTANCEOF.h"
#include <unordered_map>

template <typename T>
class EntityDataAccessor;

template <typename T>
class EntityDataSerializer;

class Entity;

class SynchedEntityData {
public:
    static std::unordered_map<eINSTANCEOF, int> sIdMap;

    SynchedEntityData(Entity*);

    static int defineIdInternal(eINSTANCEOF, eINSTANCEOF);

    template <typename T>
    void createDateItem(const EntityDataAccessor<T>*, T);

    template <typename T>
    static EntityDataAccessor<T>* defineId(eINSTANCEOF, eINSTANCEOF, EntityDataSerializer<T>*);

    template <typename T>
    void set(const EntityDataAccessor<T>*, T, bool);

    template <typename T>
    T get(const EntityDataAccessor<T>*);

    void* padding[0x101];
};
