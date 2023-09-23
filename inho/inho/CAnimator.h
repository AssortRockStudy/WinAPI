#pragma once
#include "CComponent.h"

class CAnim;

class CAnimator :
    public CComponent
{
private:
    map<wstring, CAnim*> m_mapAnim;

    CAnim* m_CurAnim;

    bool  m_bRepeat;

public:
    void Play(const wstring& _strName, bool _bRepeat);
    void Stop();
    void CreateAnimation();

public:
    virtual void finaltick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    CAnimator(CObj* _Owner);
    ~CAnimator();
};

