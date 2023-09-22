#pragma once
#include "CEntity.h"

class CTexture;

struct FFrame
{
    Vec2 vLeftTop;  // 아틀라스 내에서 잘라낼 좌상단 위치
    Vec2 vCutSize;  // 잘라낼 크기
    float Duration; // 해당 프레임 노출 시간
};


class CAnimator;

class CAnim :
    public CEntity
{
private:
    CAnimator* m_pAnimator;

    vector<FFrame>  m_vecFrm;
    CTexture* m_Atlas;
    int             m_iCurFrm;

    // 누적 시간
    float           m_AccTime;

    // animation 재생 완료 체크
    bool            m_bFinish;


public:
    void finaltick();
    void render(HDC _dc);

public:
    void Create(const wstring& _strName, CTexture* _Atlas
        , Vec2 _vLeftTop, Vec2 _vCutSize, float _Duration, int _MaxFrm);

    bool IsFinish() { return m_bFinish; }

    void Reset()
    {
        m_AccTime = 0.f;
        m_iCurFrm = 0;
        m_bFinish = false;
    }

public:
    CAnim();
    ~CAnim();

    friend class CAnimator;
};

