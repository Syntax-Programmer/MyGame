#include "../include/living.h"

BaseStats create_base_stats(int health, float vel, LivingType type) {
    BaseStats new;
    new.health = health;
    new.type = type;
    new.vel = vel;
    new.hunger = (type == PLAYER) ? 100 : -1;
    switch (type) {
        case PLAYER:
            new.intractability_level = 2;
            break;
        case NPC:
            new.intractability_level = 1;
            break;
        default:
            new.intractability_level = 0;
    }
    return new;
}

LivingObj create_living_object(int x, int y, int w, int h, int base_health, int base_vel, LivingType type) {
    LivingObj new;
    new.object_data = create_object(x, y, w, h);
    new.base_stats = create_base_stats(base_health, base_vel, type);
    new.curr_health = new.base_stats.health;
    new.curr_hunger = new.base_stats.hunger;
    new.vel_boost_percent = 0;
    new.health_boost_percent = 0;
    return new;
}