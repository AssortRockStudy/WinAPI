#pragma once
#include "Component.h"

class Anim;
class CTexture;

class Animator :
    public Component
{
private:
    map<wstring, Anim*> mapAnim;
    Anim* curAnim;
    bool repeat;

public:
    void play(const wstring& _strName, bool _bRepeat);
    void stop();

    Anim* findAnim(const wstring& _name);
    void createAnimation(const wstring& _name, CTexture* _atlus, Vec2 _lTop, Vec2 _cutSize, Vec2 _offset, float _duration, int _maxFrm);
    void saveAnimation(const wstring& _path);
    void loadAnimation(const wstring& _path);

public:
    virtual void finalTick(float _dt) override;
    virtual void render(HDC _dc) override;

public:
    Animator(CObj* _Owner);
    ~Animator();
};

