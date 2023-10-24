#pragma once
#include "Obj.h"
#include "Collider.h"

class Collider;

class Projectile : public Obj
{
private:
	Collider* m_Collider;
	float m_Speed;
	float m_Angle;

public:
	void SetAngle(float _theta) { m_Angle = _theta; }
	void SetSpeed(float _Speed) { m_Speed = _Speed; }
	Collider* GetCollider()
	{
		return m_Collider;
	}

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
	CLONE(Projectile);
	Projectile();
	Projectile(const Projectile& _Origin);
	~Projectile();

};

