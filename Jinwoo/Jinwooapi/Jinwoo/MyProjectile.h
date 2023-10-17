#pragma once


#include "MyObject.h"

class MyCollider;

class MyProjectile : public MyObject
{
private:
	float m_Speed;
	// 방향
	float m_Angle;

	MyCollider* m_Collider;

public:
	void SetSpeed(float _Speed) { m_Speed = _Speed; }
	void SetAngle(float _Angle) { m_Angle = _Angle; }

	float GetSpeed() { return m_Speed; }
	float GetAngle() { return m_Angle; }

	MyCollider* GetCollider() { return m_Collider; }

public:
	virtual void render(HDC _dc) override;

public:
	MyProjectile();
	~MyProjectile();
};

