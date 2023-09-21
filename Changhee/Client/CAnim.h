#pragma once
#include "CEntity.h"

class CTexture;

struct FFrame
{
    Vec2    LeftTop;
    Vec2    CutSize;
    float   Duration;
};

class CAnim :
    public CEntity
{
private:
    vector<FFrame>  m_vecFrm;
    CTexture*       m_pAtlas;


public:
    CAnim();
    ~CAnim();
};

