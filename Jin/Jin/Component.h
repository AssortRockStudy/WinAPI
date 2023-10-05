#pragma once
#include "Entity.h"

class Obj;

class Component : public Entity
{
private:
	Obj* const m_pOwner;

public:
	Obj* GetOwner()
	{
		return m_pOwner;
	}

	virtual void tick(float _DT)
	{}
	virtual void finaltick(float _DT) = 0;
	virtual void render(HDC _dc)
    {}


public:
	Component(Obj* _Owner);
	~Component();

};

