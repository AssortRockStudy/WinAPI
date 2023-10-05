#pragma once
#include "Entity.h"
class Texture;
class Animator;

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
    Animator* m_pAnimator;
    vector<FFrame>  m_vecFrm;
    Texture* m_Atlas;

    int m_iCurFrm;
    float m_Acctime;
    bool m_bFinish;

public:
    void finaltick();
    void render(HDC _dc);

    void Create(const wstring& _strName, Texture* _Atlas
        , Vec2 _vLeftTop, Vec2 _vCutSize, float _Duration, int _MaxFrm);

    bool IsFinish()
    {
        return m_bFinish;
    }

    void Reset()
    {
        m_Acctime = 0.f;
        m_iCurFrm = 0;
        m_bFinish = false;
    }


public:
    Anim();
    ~Anim();

    friend class Animator;
};

