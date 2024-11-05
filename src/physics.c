#include "../include/physics.h"

Object create_object(int x, int y, int w, int h) {
    return (Object){x, y, w, h};
}

void move_object(Object* to_move, int x_vel, int y_vel, float delta_time) {
    to_move->x += x_vel * delta_time;
    to_move->y += y_vel * delta_time;
}

void edit_object_pos(Object* to_edit, int new_x, int new_y) {
    to_edit->x = new_x;
    to_edit->y = new_y;
}

void edit_object_size(Object* to_edit, int new_w, int new_h) {
    to_edit->w = new_w;
    to_edit->h = new_h;
}

int aabb_collision_detection(Object* obj1, Object* obj2) {
    return (
        obj1->x < obj2->x + obj2->w &&
        obj1->x + obj1->w > obj2->x &&
        obj1->y < obj2->y + obj2->h &&
        obj1->y + obj1->h > obj2->y
    );
}
