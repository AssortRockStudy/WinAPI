#pragma once

#include "MyProjectile.h"

class MyMonster;

class HomingBullet : public MyProjectile
{
	GENERATED_OBJECT(MyProjectile);

private:
	MyMonster*		m_TargetMonster;

	float	m_Mass;
	
	Vec2	m_Velocity;
	Vec2	m_Accel;
	Vec2	m_Force;
	Vec2	m_Dir;

	float	m_RotateSpeed;

public:
	// 혹시 이 유도탄 클래스를 상속받는 자식 클래스가
	// 다른 방식으로 유도할 수 있어서 가상함수로 일단 만듦
	virtual void FindTarget();

	// 몬스터 위치로 직진
	void Fire01();
	// 몬스터 위치로 가속을 받으며 직진
	// 다만 몬스터가 피할 수 있음
	void Fire02();
	// 몬스터 위치로 회전하며 총알 날라감
	// 일반적으로 생각하는 유도탄 느낌
	void Fire03();

public:
	// 방향을 찾아서 단위벡터로 만드는 함수
	void SetDir(Vec2 _Dir)
	{
		m_Dir = _Dir;
		_Dir.Normalize();
	}

public:
	virtual void begin() override;
	virtual void tick(float _DT) override;

	virtual void BeginOverlap(MyCollider* _OwnCol, MyObject* _OtherObject, MyCollider* _OtherCol) override;

public:
	HomingBullet();
	~HomingBullet();
};

