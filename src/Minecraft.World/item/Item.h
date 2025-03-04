#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include "Minecraft.World/InteractionHand.h"
#include "Minecraft.World/SimpleRegistry.h"
#include "types.h"

class ResourceLocation;
class ItemPropertyFunction;
class Block;
class LivingEntity;
class ItemInstance;
class Level;
class Player;
class BlockState;
class CompoundTag;
class ItemToolTipDataHolder;
class Entity;
class IconRegister;
class EquipementSlot;
class BlockPos;
class Direction;

class Item {
    public:
    Item();
    void addProperty(ResourceLocation, ItemPropertyFunction const*);
    int getId();
    bool canBeDepleted();
    static Item* byId(int id);
    static void registerBlock(Block* block);

    virtual const std::__shared_weak_count* getDefaultInstance(const std::shared_ptr<ItemInstance>&);
    virtual bool verifyTagAfterLoad(CompoundTag*);
    virtual int GetUseTooltip(const ItemToolTipDataHolder&);
    virtual ~Item();
    virtual bool useOn(const std::shared_ptr<Player>&, Level*, const BlockPos&, InteractionHand::EInteractionHand, const Direction*, float, float, float, bool);
    virtual float getDestroySpeed(const std::shared_ptr<ItemInstance>&, BlockState*);
    virtual bool TestUse(Level*, const std::shared_ptr<Player>&, InteractionHand::EInteractionHand);
    virtual void use(uintptr_t unk, Level*, const std::shared_ptr<Player>&, InteractionHand::EInteractionHand); // this def need complete overhaul as it's...
    virtual not_null_ptr<ItemInstance> finishUsingItem(not_null_ptr<ItemInstance>, Level*, const std::shared_ptr<LivingEntity>&);
    virtual int getMaxStackSize();
    virtual int getLevelDataForAuxValue(int);
    virtual bool hurtEnemy(const std::shared_ptr<ItemInstance>&, const std::shared_ptr<LivingEntity>&, const std::shared_ptr<LivingEntity>&);
    virtual bool mineBlock(const std::shared_ptr<ItemInstance>&, Level*, const BlockState*, const BlockPos&, std::shared_ptr<LivingEntity>&);
    virtual int getAttackDamage(const std::shared_ptr<Entity>&);
    virtual bool canDestroySpecial(const BlockState*);
    virtual bool interactEnemy(const std::shared_ptr<ItemInstance>&, const std::shared_ptr<Player>&, const std::shared_ptr<LivingEntity>&, InteractionHand::EInteractionHand);
    virtual bool isHandEquipped();
    virtual bool isMirroredArt();
    virtual int getDescriptionId(int);
    virtual int getDescriptionId(const std::shared_ptr<ItemInstance>&);
    virtual int getUseDescriptionId();
    virtual int getUseDescriptionId(const std::shared_ptr<ItemInstance>&);
    virtual bool shouldOverrideMultiplayerNBT();
    virtual int getColor(const std::shared_ptr<ItemInstance>&, int);
    virtual void inventoryTick(std::shared_ptr<ItemInstance>&, Level*, std::shared_ptr<Entity>&, int, bool);
    virtual void onCraftedBy(const std::shared_ptr<ItemInstance>&, Level*, const std::shared_ptr<Player>&);
    virtual bool isComplex();
    virtual int getUseAnimation(const std::shared_ptr<ItemInstance>&);
    virtual int getUseDuration(const std::shared_ptr<ItemInstance>&);
    virtual void releaseUsing(const std::shared_ptr<ItemInstance>&, Level*, const std::shared_ptr<LivingEntity>&, int);
    virtual void appendHoverText(const std::shared_ptr<ItemInstance>&, const std::shared_ptr<Player>&, void* htmlString, bool);
    virtual void getName(const std::shared_ptr<ItemInstance>&);
    virtual bool isFoil(not_null_ptr<ItemInstance>);
    virtual void getRarity(const std::shared_ptr<ItemInstance>&);
    virtual bool isEnchantable(const std::shared_ptr<ItemInstance>&);
    virtual int getEnchantmentValue();
    virtual bool mayBePlacedInAdventureMode();
    virtual bool isValidRepairItem(const std::shared_ptr<ItemInstance>&, const std::shared_ptr<ItemInstance>&);
    virtual void getDefaultAttributeModifiers(const EquipementSlot*);
    virtual void registerIcons(IconRegister*);
    virtual bool hasMultipleSpriteLayers();
    virtual void* getLayerIcon(int, int, const std::shared_ptr<ItemInstance>&);
    virtual int getIconType();
    virtual void* getIcon(int);
    virtual void* getIcon(const std::shared_ptr<ItemInstance>&);
    virtual int GetArmorType();
    virtual int GetOverrideCount();
    virtual int GetOverrideCountColour();
    virtual void* GetOverrideCountIcon(const std::shared_ptr<ItemInstance>&);

    void* qword8;
    SimpleRegistry<ResourceLocation, const ItemPropertyFunction*>* simpleRegistry;
    int maxStackSize;
    int maxDamage;
    void* icon; // I assume it's pointer to something, idk what though
    int baseItemType;
    int material;
    bool handEquipped;
    bool stackedByData;
    char gap32[6];
    void* craftingRemainingItem;
    std::wstring wstring_1;
    int descriptionId;
    int useDescriptionId;
    std::wstring iconName;
    char byte78; // probably bool but idk
};