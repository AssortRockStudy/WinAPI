#pragma once
#include "CComponent.h"

class CAnim;
class CTexture;

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

    CAnim* FindAnim(const wstring& _strName);
    void CreateAnimation(const wstring& _strName, CTexture* _Altas, Vec2 _vLeftTop, Vec2 _vCutSize, float _duration, int _MaxFrm);


public:
    virtual void finaltick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    CAnimator(CObj* _Owner);
    ~CAnimator();
};

