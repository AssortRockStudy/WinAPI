#pragma once
#include "CProjectile.h"

class CMonster;

class CGuided :
    public CProjectile
{
    GENERATED_OBJECT(CProjectile);
private:
    CMonster* m_Target;
    float       m_fMass;
    Vec2        m_vVelocity;

    Vec2        m_vAccel;
    Vec2        m_vForce;
    Vec2        m_vDir;

    float       m_fRotateSpeed;


public:
    virtual void FindTarget();
    void update1();
    void update2();
    void update3();
    void SetDir(Vec2 _vDir)
    {
        m_vDir = _vDir;
        m_vDir.Normalize();
    }

    - 230926화 무브먼트컴포넌트
    - 위치는 오브젝트가 들고있다
    - 무브먼트 컴포넌트의 멤버
        - 힘
        - 질량
        - 가속도(힘과 질량에서 유도됨)
        - 속도
        - 최대속력
        - bool 그라운드
        - 중력(캐릭터가 들고있는게 가변중력을 구현하기 쉽다)

public:
    virtual void begin() override;
    virtual void tick(float _DT) override;

    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;


public:
    CGuided();
    ~CGuided();
};

