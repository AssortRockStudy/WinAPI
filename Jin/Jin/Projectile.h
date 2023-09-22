#pragma once
#include "Obj.h"
class Projectile : public Obj
{
private:
	float m_Speed;
	float m_theta;

public:
	void SetDir(float _theta) { m_theta = _theta; }
	void SetSpeed(float _Speed) { m_Speed = _Speed; }

	virtual void tick(float _DT) override;
	virtual void render(HDC _dc) override;

public:
	Projectile();
	~Projectile();

};

