#include "engine/object.h"

Object createObject(int x, int y, int w, int h)
{
    return (Object){x, y, w, h};
}

void setObjectPos(Object *obj, int x, int y)
{
    obj->x = x;
    obj->y = y;
}

void setObjectSize(Object *obj, int w, int h)
{
    obj->w = w;
    obj->h = h;
}

void getObjectPos(const Object *obj, int *pX, int *pY)
{
    *pX = obj->x;
    *pY = obj->y;
}

void getObjectSize(const Object *obj, int *pW, int *pH)
{
    *pW = obj->w;
    *pH = obj->h;
}

Bar createBar(float max, float curr)
{
    return (Bar){max, curr};
}

void setBarMax(Bar *bar, float max)
{
    bar->max = max;
}

void setBarCurr(Bar *bar, float curr)
{
    bar->curr = curr;
}

float getBarMax(const Bar *bar)
{
    return bar->max;
}

float getBarCurr(const Bar *bar)
{
    return bar->curr;
}
