#pragma once
#include "Component.h"
class Anim;
class Texture;

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

    Anim* FindAnim(const wstring& _strName);
    void CreateAnimation(const wstring& _strName, Texture* _Atlas, Vec2 _vLeftTop, Vec2 _vCutSize, 
         Vec2 _vOffset, float _Duration, int _MaxFrm);

    void SaveAnimations(const wstring& _strRelativePath);
    void LoadAnimation(const wstring& _strRelativePath);

    virtual void finaltick(float _DT) override;
    virtual void render(HDC _dc) override;


public:
    CLONE(Animator);
    Animator(Obj* _Owner);
    Animator(const Animator& _Origin);
    ~Animator();
};

