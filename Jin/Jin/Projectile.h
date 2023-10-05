#pragma once
#include "Obj.h"
class Projectile : public Obj
{
private:
	float m_Speed;
	float m_Angle;

public:
	void SetAngle(float _theta) { m_Angle = _theta; }
	void SetSpeed(float _Speed) { m_Speed = _Speed; }

	float GetSpeed()
	{
		return m_Speed;
	}

	float GetAngle()
	{
		return m_Angle;
	}

	//virtual void tick(float _DT) override;
	virtual void render(HDC _dc) override;

public:
	Projectile();
	~Projectile();

};

