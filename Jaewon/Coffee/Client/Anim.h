#pragma once
#include "CEntity.h"

class CTexture;
class Animator;

struct Frame {
    Vec2 leftTop;
    Vec2 cutSize;
    Vec2 offset;
    float duration;
};

class Anim :
    public CEntity
{
private:
    Animator* mAnimator;
    vector<Frame> vecFrm;
    CTexture* mAtlas;
    int mCurFrame;
    float accTime;
    bool finished;

public:
    void finalTick();
    void render(HDC _dc);

public:
    void create(const wstring& _name, CTexture* _atlas, Vec2 _lTop, Vec2 _cutSize, Vec2 offset, float _duration, int _maxFrm);
    bool isFinish() { return finished; }
    void reset(){
        accTime = 0.f;
        mCurFrame = 0;
        finished = false;
    }
    bool save(const wstring& _path);
    void load(const wstring& _path);

public:
    Anim();
    ~Anim();

    friend class Animator;
};

