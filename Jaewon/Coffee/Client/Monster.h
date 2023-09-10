#pragma once
#include "CObj.h"
class Monster : public CObj
{
private:
	float mSpeed;

private:
	virtual void tick(float _dt) override;
	virtual void render(HDC _dc) override;
public:
	Monster();
	~Monster();
};

