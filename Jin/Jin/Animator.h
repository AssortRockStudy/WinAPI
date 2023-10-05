#pragma once
#include "Component.h"
class Anim;

class Animator :
    public Component
{
private:
    map<wstring, Anim*> m_mapAnim;
    Anim* m_CurAnim;
    bool m_bRepeat;

public:
    void Play(const wstring& _strName, bool _bRepeat);
    void Stop();
    void CreateAnimation();

    virtual void finaltick(float _DT) override;
    virtual void render(HDC _DC) override;


public:
    Animator(Obj* _Owner);
    ~Animator();
};

