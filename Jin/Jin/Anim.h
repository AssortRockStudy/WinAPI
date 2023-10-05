#pragma once
#include "Entity.h"
class Texture;


struct FFrame
{
    Vec2 vLeftTop;
    Vec2 vCutSize;
    float Duration;
};

class Anim :
    public Entity
{
private:
    vector<FFrame>  m_vecFrm;
    Texture* m_Atlas;


};

