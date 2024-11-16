#ifndef OBJECT_H
#define OBJECT_H

typedef struct Object
{
    int x, y, w, h;
} Object;

typedef struct Bar
{
    float max, curr;
} Bar;

extern Object createObject(int x, int y, int w, int h);
extern void setObjectPos(Object *obj, int x, int y);
extern void setObjectSize(Object *obj, int w, int h);
extern void getObjectPos(const Object *obj, int *pX, int *pY);
extern void getObjectSize(const Object *obj, int *pW, int *pH);
extern Bar createBar(float max, float curr);
extern void setBarMax(Bar *bar, float max);
extern void setBarCurr(Bar *bar, float curr);
extern float getBarMax(const Bar *bar);
extern float getBarCurr(const Bar *bar);

#endif
