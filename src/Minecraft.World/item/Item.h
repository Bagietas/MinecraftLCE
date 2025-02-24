#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include "Minecraft.World/InteractionHand.h"
#include "Minecraft.World/SimpleRegistry.h"

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

class Item {
    public:
    Item();
    void addProperty(ResourceLocation, ItemPropertyFunction const*);
    int getId();
    bool canBeDepleted();
    static Item* byId(int id);
    static void registerBlock(Block* block);

    virtual void getDefaultInstance(const std::shared_ptr<ItemInstance>&);
    virtual void verifyTagAfterLoad(CompoundTag*);
    virtual int GetUseTooltip(const ItemToolTipDataHolder&);
    virtual ~Item();
    virtual int useOn(const std::shared_ptr<Player>&, Level*, const BlockPos&, InteractionHand::EInteractionHand, uint32_t, float, float, float, bool);
    virtual float getDestroySpeed(const std::shared_ptr<ItemInstance>&, BlockState*);
    virtual void TestUse(Level*, const std::shared_ptr<Player>&, InteractionHand::EInteractionHand);
    virtual uintptr_t use(uintptr_t unk, Level*, const std::shared_ptr<Player>&, InteractionHand::EInteractionHand); // for whatever reason I can't decide if that's correct and what does it return
    virtual void finishUsingItem(const std::shared_ptr<ItemInstance>&, Level*, const std::shared_ptr<LivingEntity>&);
    virtual void getMaxStackSize();
    virtual void getLevelDataForAuxValue(int);
    virtual bool hurtEnemy(const std::shared_ptr<ItemInstance>&, const std::shared_ptr<LivingEntity>&, const std::shared_ptr<LivingEntity>&);
    virtual bool mineBlock(const std::shared_ptr<ItemInstance>&, Level*, const BlockState*, const BlockPos&, std::shared_ptr<LivingEntity>&);
    virtual int getAttackDamage(const std::shared_ptr<Entity>&);
    virtual bool canDestroySpecial(const BlockState*);
    virtual void interactEnemy(const std::shared_ptr<ItemInstance>&, const std::shared_ptr<Player>&, const std::shared_ptr<LivingEntity>&, InteractionHand::EInteractionHand);
    virtual bool isHandEquipped();
    virtual bool isMirroredArt();
    virtual void getDescriptionId(int);
    virtual void getDescriptionId(const std::shared_ptr<ItemInstance>&);
    virtual void getUseDescriptionId();
    virtual void getUseDescriptionId(const std::shared_ptr<ItemInstance>&);
    virtual bool shouldOverrideMultiplayerNBT();
    virtual void getColor(const std::shared_ptr<ItemInstance>&, int);
    virtual void inventoryTick(std::shared_ptr<ItemInstance>&, Level*, std::shared_ptr<Entity>&, int, bool);
    virtual void onCraftedBy(const std::shared_ptr<ItemInstance>&, Level*, const std::shared_ptr<Player>&);
    virtual bool isComplex();
    virtual int getUseAnimation(const std::shared_ptr<ItemInstance>&);
    virtual int getUseDuration(const std::shared_ptr<ItemInstance>&);
    virtual Item* releaseUsing(const std::shared_ptr<ItemInstance>&, Level*, const std::shared_ptr<LivingEntity>&, int);
    virtual void appendHoverText(const std::shared_ptr<ItemInstance>&, const std::shared_ptr<Player>&, void* htmlString, bool);
    virtual void getName(const std::shared_ptr<ItemInstance>&);
    virtual bool isFoil(std::shared_ptr<ItemInstance>);
    virtual void getRarity(const std::shared_ptr<ItemInstance>&);
    virtual bool isEnchantable(const std::shared_ptr<ItemInstance>&);
    virtual int getEnchantmentValue();
    virtual void mayBePlacedInAdventureMode();
    virtual bool isValidRepairItem(const std::shared_ptr<ItemInstance>&, const std::shared_ptr<ItemInstance>&);
    virtual void getDefaultAttributeModifiers(const EquipementSlot*);
    virtual void registerIcons(IconRegister*);
    virtual void hasMultipleSpriteLayers();
    virtual void getLayerIcon(int, int, const std::shared_ptr<ItemInstance>&);
    virtual void getIconType();
    virtual void getIcon(int);
    virtual void getIcon(const std::shared_ptr<ItemInstance>&);
    virtual void GetArmorType();
    virtual void GetOverrideCount();
    virtual void GetOverrideCountColour();
    virtual void GetOverrideCountIcon(const std::shared_ptr<ItemInstance>&);

    void* qword8;
    SimpleRegistry<ResourceLocation, const ItemPropertyFunction*>* simpleRegistry;
    int maxStackSize;
    int maxDamage;
    void* icon; // I assume it's pointer to something, idk what though
    int baseItemType;
    int material;
    bool handEquipped;
    bool somebool;
    char gap32[6];
    void* craftingRemainingItem;
    std::wstring wstring_1;
    int descriptionId;
    int useDescriptionId;
    std::wstring iconName;
    char byte78; // probably bool but idk
};