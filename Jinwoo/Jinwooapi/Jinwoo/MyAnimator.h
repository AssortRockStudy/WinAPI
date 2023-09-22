#pragma once
#include "MyComponent.h"

class MyAnim;

class MyAnimator :
    public MyComponent
{
private:
    // Animator가 보유하고 있는 Animation 목록을 탐색하기 위해 map으로 생성
    map<wstring, MyAnim*> m_mapAnim;

    // 현재 재생중인 애니메이션
    MyAnim* m_CurAnim;

    // 반복재생 여부
    bool m_Repeat;

public:
    void Play(const wstring& _strName, bool _repeat);
    void Stop();
    void CreateAnimation();

public:
    virtual void finaltick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    MyAnimator(MyObject* _Object);
    ~MyAnimator();
};

