#ifndef LIVING_H
#define LIVING_H

#include "physics.h"

typedef enum {
    PLAYER, NPC, ENEMY, BOSS
} LivingType; 
typedef struct {
    int health;
    // As only player should have hunger, for rest the hunger is -1.
    int hunger;
    float vel;
    LivingType type;
    /* 
     * Intractability levels:
     * 0: Can't interact at all with other unrelated elements of the world.
     * 1: Can only interact with the player. Like NPCs.
     * 2: Can interact with every element in the world.
     */
    int intractability_level;
} BaseStats;
typedef struct {
    Object object_data;
    BaseStats base_stats;
    int curr_health, curr_hunger;
    int vel_boost_percent;
    int health_boost_percent;
} LivingObj;

/// @brief Creates a new BaseStats struct.
/// @param health The base health.
/// @param vel The base velocity.
/// @param type The type of object.
/// @return The newly created BaseStats struct.
extern BaseStats create_base_stats(int health, float vel, LivingType type);

/// @brief Creates a new LivingObj struct.
/// @param x The x pos of the living object.
/// @param y The y pos of the living object.
/// @param w The width of the living object.
/// @param h The height of the living object.
/// @param base_health The base health of the living object.
/// @param base_vel The base velocity of the living object.
/// @param type The type of living object.
/// @return The newly created LivingObj struct.
extern LivingObj create_living_object(int x, int y, int w, int h, int base_health, int base_vel, LivingType type);

#endif