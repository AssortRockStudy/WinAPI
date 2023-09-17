#pragma once
#include "CObj.h"

class CProjectile :public CObj
{
private:
	float m_Speed;
	float m_Angle;

public:
	void SetAngle(float _theta) { m_Angle = _theta; }
	void SetSpeed(float _Speed) { m_Speed = _Speed; }

	float GetSpeed() { return m_Speed; }
	float GetAngle() { return m_Angle; }

public:
	
	virtual void render(HDC _dc) override;

public:
	CProjectile();
	~CProjectile();
};

