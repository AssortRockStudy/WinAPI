#pragma once
#include "CProjectile.h"

class CMonster; // 몬스터 클래스 전방 선언

class CGuided :
    public CProjectile
{
private:
    CMonster*   m_Target; // 유도탄이 날아갈 타겟

    float       m_fMass; // 질량
    Vec2        m_vAccel; // 가속도
    Vec2        m_vVelocity; // 속도
    Vec2        m_vForce; // 힘

    Vec2        m_vDir; // 방향 벡터 (빗변의 길이가 1인 방향만 나타내는 벡터)

    float       m_fRotateSpeed; // 회전 속도(dt를 곱해서 회전)

public:
    virtual void tick(float _DT) override;
    
    void SetDir(Vec2 _vDir)
    {
        m_vDir = _vDir;
        m_vDir.Normalize();
    }



private:
    virtual void FindTarget();

    void Update_1(); 
    void Update_2();
    void Update_3();

public:
    CGuided();
    ~CGuided();
};
