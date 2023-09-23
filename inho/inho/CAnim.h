#pragma once
#include "CEntity.h"

class CTexture;

struct FFrame {
    Vec2 vLeftTop;
    Vec2 vCutSize;
    float Duration;
};


class CAnim :
    public CEntity
{
private:
    vector<FFrame> m_vecFrm;
    CTexture* m_Atlas;

};

