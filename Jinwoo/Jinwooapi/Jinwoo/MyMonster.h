#pragma once

#include "MyObject.h"

class MyMonster : public MyObject
{
	float m_Speed;

public:
	virtual void tick(float _DT) override;
	virtual void render(HDC _dc) override;

public:
	MyMonster();
	~MyMonster();
};

