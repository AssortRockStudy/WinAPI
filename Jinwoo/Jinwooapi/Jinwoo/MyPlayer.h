#pragma once

#include "MyObject.h"

class MyPlayer : public MyObject
{
	float m_Speed;
	
public:
	virtual void tick(float _DT) override;
	virtual void render(HDC _dc) override;

public:
	MyPlayer();
	~MyPlayer();
};

