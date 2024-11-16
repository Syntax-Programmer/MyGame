#ifndef PLAYER_H
#define PLAYER_H

#include "engine/object.h"
#include "items.h"

#define MAX_INVENTORY_LEN 30

typedef struct Player
{
    Object obj;
    Bar health, hunger, vel;
    Item inventory[MAX_INVENTORY_LEN]; /* First 5 items are in the hotbar. */
    int curr_item_index;               /* 0 - 4 only, as only first 5 items are in the hotbar. */
} Player;

/* TODO: Make a system/struct which can be passed here
with the appropriate data for each inventory slot, This will help us
save player inventory data in a file, which can be referenced while loading. */
extern initInventory(Player *player);

#endif
