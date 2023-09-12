#pragma once
#include "CObj.h"
class Player : public CObj
{
private:
	float mSpeed;
	COLOR col;
	bool reverseMove;

	HBITMAP pImage;
	HDC pImageDc;
	BITMAP pBitMapInfo;


public:
	virtual void tick(float _dt) override;
	virtual void render(HDC _dc) override;
	void setColor(COLOR _col) { col = _col; }
	void setReverseMove(bool _bool) { reverseMove = _bool; }

public:
	Player();
	~Player();
};

