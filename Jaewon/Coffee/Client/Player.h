#pragma once
#include "CObj.h"
class Player : public CObj
{
public:
	virtual void tick() override;
	virtual void render(HDC _dc) override;

public:
	Player();
	~Player();
};

