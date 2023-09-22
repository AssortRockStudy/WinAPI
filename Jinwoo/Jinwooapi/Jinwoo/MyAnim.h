#pragma once
#include "MyEntity.h"

class MyTexture;

struct FFrame
{
    // 아틀라스에서 잘라낼 좌상단 위치
    Vec2 vLeftTop;

    // 좌상단으로부터 얼마나 잘라낼 것인가
    Vec2 vCutSize;

    // 해당 프레임 노출 시간
    float vDuration;
};


class MyAnim :
    public MyEntity
{
private:
    // 애니메이션에는 수많은 프레임과 그것을 포함하는 아틀라스 한 장이 필요하다
    MyTexture*      m_Atlas;
    vector<FFrame>  m_vecFrame;

};

