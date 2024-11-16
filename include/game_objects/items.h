#ifndef ITEMS_H
#define ITEMS_H

#include "engine/object.h"

typedef enum
{
    WEAPON,
    CONSUMABLE,
    MISCELLANEOUS,
    NO_ITEM
} ItemType;
typedef enum
{
    EMPTY, BASE_SWORD /* TODO: ADD NEW ITEMS HERE */
} ItemId;
typedef struct Item
{
    Object obj;
    ItemId id;
    ItemType type;
    float damage, healing, hunger_change, vel_boost; /* TODO: Make a xml that stores item id and their stats.*/
} Item;

/* As items can't change their attrs during game-play so, it doesn't make
sense to have setters for this struct. Getters are only needed to get what the
object does and identify the item. */

extern Item createItem(int x, int y, int w, int h, ItemId id, ItemType type,
                       float damage, float healing, float hunger_change, float vel_boost);
extern ItemId getItemId(const Item *item);
extern ItemType getItemType(const Item *item);
extern float getItemDamage(const Item *item);
extern float getItemHealing(const Item *item);
extern float getItemHungerChange(const Item *item);
extern float getItemVelBoost(const Item *item);

#endif
