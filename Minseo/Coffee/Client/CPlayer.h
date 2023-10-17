#pragma once
#include "CObj.h"

class CPlayer :
    public CObj // 모든 객체는 CObj를 상속받아야 한다
{
private:
    float m_Speed;
    //float m_Acc;

    HBITMAP m_Image;
    HDC m_ImageDC;
    BITMAP      m_BitmapInfo; // 비트맵을 GetObjectW함수를 통해서 저장할 멤버

public:
    virtual void tick(float _DT) override; // 순수가상함수를 재정의 함으로써 추상화를 해제
    virtual void render(HDC _dc) override;
public:
    CPlayer();
    ~CPlayer();
};

