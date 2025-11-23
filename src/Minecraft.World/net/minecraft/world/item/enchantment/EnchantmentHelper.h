#pragma once

#include "types.h"
#include <memory>

class ItemInstance;
class Enchantment;
class LivingEntity;

class EnchantmentHelper {
public:
    static int getItemEnchantmentLevel(const Enchantment*, const not_null_ptr<ItemInstance>&);
    static int getEnchantmentLevel(Enchantment*, const std::shared_ptr<LivingEntity>&);
    static std::shared_ptr<ItemInstance> getRandomItemWith(const Enchantment*,
                                                           const std::shared_ptr<LivingEntity>&);
    static int getDepthStrider(const std::shared_ptr<LivingEntity>&);
    static float getDamageBonus(const not_null_ptr<ItemInstance>&, const std::shared_ptr<LivingEntity>&);
    static void doPostHurtEffects(const std::shared_ptr<LivingEntity>&, const std::shared_ptr<Entity>&);
    static void doPostDamageEffects(const std::shared_ptr<LivingEntity>&, const std::shared_ptr<Entity>&);
};
