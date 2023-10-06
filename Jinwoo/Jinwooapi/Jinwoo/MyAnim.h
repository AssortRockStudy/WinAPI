#pragma once
#include "MyEntity.h"

class MyTexture;
class MyAnimator;

struct FFrame
{
    // 아틀라스에서 잘라낼 좌상단 위치
    Vec2 vLeftTop;

    // 좌상단으로부터 얼마나 잘라낼 것인가
    Vec2 vCutSize;

    // 오브젝트 중심에서 얼마나 떨어져있는가
    Vec2 vOffset;

    // 해당 프레임 노출 시간
    float Duration;
};

class MyAnim :
    public MyEntity
{
private:
    MyAnimator*     m_Animator;

    // 애니메이션에는 수많은 프레임과 그것을 포함하는 아틀라스 한 장이 필요하다
    MyTexture*      m_Atlas;
    vector<FFrame>  m_vecFrame;
    int             m_iCurFrame;

    // 누적 시간
    float           m_AccTime;
    
    // animation 재생이 끝났는가
    bool            m_Finish;

public:
    void finaltick();
    void render(HDC _dc);

public:
    void Create(const wstring& _strName, MyTexture* _Atlas, Vec2 _vLeftTop, Vec2 _vCutSize, Vec2 _vOffset, float _Duration, int _MaxFrame);

    bool IsFinish() { return m_Finish; }

    void Reset()
    {
        m_iCurFrame = 0;
        m_AccTime = 0.f;
        m_Finish = false;
    }

    bool Save(const wstring& _FilePath);
    bool Load(const wstring& _FilePath);

public:
    MyAnim();
    ~MyAnim();

    friend class MyAnimator;
};

