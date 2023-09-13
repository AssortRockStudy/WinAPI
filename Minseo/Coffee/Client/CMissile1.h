#pragma once
#include "CProjectile.h"
#include "CMonster.h"

// ## 유도탄 1
// 1. 타겟팅 된 몬스터를 향해서 이동
// 
// - 계획
//  init에 가장 가까운 몬스터를 설정하여 그 몬스터를 목적지로 지정
//  tick마다 가까운 몬스터의 좌표 정보로 몬스터의 방향으로 (즉, 가장 짧은 시간으로 이동할 수 있는 방향으로) 1000만큼 이동... 방향은 어떻게 정해야할까?
//  tick 실시간으로 몬스터의 위치를 받아와서 몬스터의 위치로 1000만큼 이동하면 될 것 같음.
// 
//  일단 몬스터의 위치 정보를 틱마다 받아서 오는 것이 기본 전제.
//  CMonster 클래스를 include 해서 해당 객체 안의 Pos 값을 받아온다면 되려나?
//  
//  음... 근데 어떻게 구하는 것이 좋을까.
//  일단 미사일 위치와 몬스터의 위치를 빼면 미사일과 몬스터의 x,y값의 차이 정도를 알 수 있는데,
//  이 것으로 피타고라스 정리를 이용해서 빗변을 구하고 cosf sinf 써서 그 만큼만 딱 다가가면 될 듯.
// 
//  그 전에 몬스터 객체를 만들어볼까?
//  몬스터는 자신이 상하좌우로 1초마다 방향을 바꾸며 움직이는 형식으로 만들었음.
//  멤버로 CMonster* 가 하나 들어간다면 
//  CMonster* 로 몬스터를 가리킬 수 있지 않을까?
//  
//  m_Speed와 m_theta는 그냥 사용할 수 있겠는데, tick, render 함수들은 다 오버라이딩 시켜야 할 듯
//  
//
class CMissile1 :
    public CProjectile
{
private:
    CMonster* m_TargetMonster;

public:
    virtual void tick(float _DT) override;
    //virtual void render(HDC _dc) override;

public:
    virtual void SetTarget(CMonster* monster) { m_TargetMonster = monster; }

public: // 생성자, 소멸자


};

