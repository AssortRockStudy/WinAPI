#pragma once
#include "pch.h"
#include "CObj.h"

class CProjectile :
	public CObj
{
private:
	float m_Speed;
	float m_theta;

public:
	virtual void tick(float _DT) override;
	virtual void render(HDC _dc) override;

public:
	void SetDir(float _theta) { m_theta = _theta; } // 방향(PI를 통해서 호도법으로 입력받음)
	void SetSpeed(float _Speed) { m_Speed = _Speed; } // 속도

public:
	float GetSpeed() { return m_Speed; }
	float GetDir() { return m_theta; }

public:
	CProjectile();
	~CProjectile();
};

