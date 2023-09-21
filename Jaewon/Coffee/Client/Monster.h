#pragma once
#include "CObj.h"

class Collider;

class Monster : public CObj
{
	GENERATED_OBJECT(CObj);
private:
	Collider* collider;

private:
	virtual void tick(float _dt) override;
	virtual void render(HDC _dc) override;
public:
	Monster();
	~Monster();
};

