#pragma once
#include "CObj.h"
class Player : public CObj
{
private:
	float mSpeed;

public:
	virtual void tick(float _dt) override;
	virtual void render(HDC _dc) override;

public:
	Player();
	~Player();
};

