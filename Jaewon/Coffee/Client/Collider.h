#pragma once
#include "Component.h"
class Collider :
    public Component
{
private:
    Vec2 offsetPos;
    Vec2 scale;
    Vec2 finalPos;
    int collisionCnt;

public:
    Vec2 getPos() { return finalPos; }
    Vec2 getOffsetPos() { return offsetPos; }
    Vec2 getScale() { return scale; }
    void setOffsetPos(Vec2 _pos) { offsetPos = _pos; }
    void setScale(Vec2 _scale) { scale = _scale; }

public:
    virtual void finalTick(float _dt) override;
    virtual void render(HDC _dc) override;
    void beginOverLap(Collider* _oth);
    void overLap(Collider* _oth);
    void endOverLap(Collider* _oth);

public:
    Collider(CObj* _owner);
    ~Collider();
};

