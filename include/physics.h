#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL2/SDL_rect.h>

typedef SDL_Rect Object;

/// @brief Creates a new Object.
/// @param x The x position of the object.
/// @param y The y position of the object.
/// @param w The width of the object.
/// @param h The height of the object.
/// @return The newly created object.
extern Object create_object(int x, int y, int w, int h);

/// @brief Moves the given object.
/// @param to_move The object to move.
/// @param x_vel The x vel of the object.
/// @param y_vel The y vel of the object.
/// @param delta_time The delta time between the last frame and the frame before that.
extern void move_object(Object* to_move, int x_vel, int y_vel, float delta_time);

/// @brief Edits the position of the given object.
/// @param to_edit The object to edit.
/// @param new_x The new x pos of the object.
/// @param new_y The new y pos of the object.
extern void edit_object_pos(Object* to_edit, int new_x, int new_y);

/// @brief Edits the size of the given object.
/// @param to_edit The object to edit.
/// @param new_w The new width of the object.
/// @param new_h The new height of the object.
extern void edit_object_size(Object* to_edit, int new_w, int new_h);

/// @brief Checks for the collision between the given object.
/// @param obj1 The first object.
/// @param obj2 The second object.
/// @return 0 if obj1 and obj2 don't collide else any other number.
extern int aabb_collision_detection(Object* obj1, Object* obj2);

#endif