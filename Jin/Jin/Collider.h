#pragma once
#include "Component.h"

class Collider : public Component
{
private:
	Vec2 m_vOffsetPos;
	Vec2 m_vOffserScale;
	Vec2 m_vFinalPos;

public:
	virtual void finaltick(float _DT) override;
	Vec2 GetPos()
	{
		return m_vFinalPos;
	}

public:
	Collider(Obj* _Owner);
	~Collider();
};

