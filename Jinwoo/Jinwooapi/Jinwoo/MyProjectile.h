#pragma once


#include "MyObject.h"

class MyProjectile : public MyObject
{
private:
	float m_Speed;
	// 방향
	float m_Dir;

public:
	void SetSpeed(float _Speed) { m_Speed = _Speed; }
	void SetDir(float _Dir) { m_Dir = _Dir; }

public:
	virtual void tick(float _DT) override;
	virtual void render(HDC _dc) override;

public:
	MyProjectile();
	~MyProjectile();
};

