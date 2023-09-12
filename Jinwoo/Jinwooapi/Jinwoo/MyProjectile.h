#pragma once


#include "MyObject.h"

class MyProjectile : public MyObject
{
private:
	float m_Speed;
	// 방향
	float m_Angle;

public:
	void SetSpeed(float _Speed) { m_Speed = _Speed; }
	void SetDir(float _Angle) { m_Angle = _Angle; }

	float GetSpeed() { return m_Speed; }
	float GetAngle() { return m_Angle; }

public:
	virtual void tick(float _DT) override;
	virtual void render(HDC _dc) override;

public:
	MyProjectile();
	~MyProjectile();
};

