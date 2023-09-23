#pragma once
#include "CEntity.h"

class CTexture;
class CAnimator;

struct FFrame {
    Vec2 vLeftTop;
    Vec2 vCutSize;
    float Duration;
};


class CAnim :
    public CEntity
{
private:
    CAnimator* m_pAnimator;

    vector<FFrame> m_vecFrm;
    CTexture* m_Atlas;
    int m_iCurFrm;

    float m_AccTime;
    bool m_bFinish;

public:
    void finaltick();
    void render(HDC _dc);

public:
    void Create(const wstring& _strName, CTexture* _Atlas
        , Vec2 _vLeftTop, Vec2 _vCutSize, float _Duration, int _MaxFrm);

    bool IsFinish() { return m_bFinish; }

    void Reset() {
        m_AccTime = 0.f;
        m_iCurFrm = 0;
        m_bFinish = false;
    }

public:
    CAnim();
    ~CAnim();

    friend class CAnimator;
};

