#pragma once
#include "pch.h"
#include "CObj.h"

class CProjectile :
	public CObj
{
private:
	float m_Speed;
	float m_Angle;

public:
	virtual void tick(float _DT) override;
	virtual void render(HDC _dc) override;

public:
	void SetAngle(float _theta) { m_Angle = _theta; } // 방향(PI를 통해서 호도법으로 입력받음)
	void SetSpeed(float _Speed) { m_Speed = _Speed; } // 속도

public:
	float GetSpeed() { return m_Speed; }
	float GetAngle() { return m_Angle; }

public:
	CProjectile();
	~CProjectile();
};

