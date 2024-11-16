#include "game_objects/items.h"

Item createItem(int x, int y, int w, int h, ItemId id, ItemType type,
                float damage, float healing, float hunger_change, float vel_boost)
{
    Item new;

    new.obj = createObject(x, y, w, h);
    new.id = id;
    new.type = type;
    new.damage = damage;
    new.healing = healing;
    new.hunger_change = hunger_change;
    new.vel_boost = vel_boost;
    return new;
}

ItemId getItemId(const Item *item)
{
    return item->id;
}

ItemType getItemType(const Item *item)
{
    return item->type;
}

float getItemDamage(const Item *item)
{
    return item->damage;
}

float getItemHealing(const Item *item)
{
    return item->healing;
}

float getItemHungerChange(const Item *item)
{
    return item->hunger_change;
}

float getItemVelBoost(const Item *item)
{
    return item->vel_boost;
}