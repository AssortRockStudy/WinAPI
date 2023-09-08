#pragma once
#include "CObj.h"
class Player : public CObj
{
private:
	float mSpeed;
	COLOR col;

public:
	virtual void tick(float _dt) override;
	virtual void render(HDC _dc) override;
	void setColor(COLOR _col) { col = _col; }

public:
	Player();
	~Player();
};

