#pragma once
#include "CObj.h"

class Collider;
class CTexture;
class Animator;
class Movement;

class Player : public CObj
{
	GENERATED_OBJECT(CObj);
private:
	float mSpeed;
	COLOR col;
	bool reverseMove;

	HBITMAP pImage;
	HDC pImageDc;
	BITMAP pBitMapInfo;

	Collider* mCollider;
	CTexture* mTexture;
	Animator* mAnimator;
	Movement* mMovement;

public:
	void setColor(COLOR _col) { col = _col; }
	void setReverseMove(bool _bool) { reverseMove = _bool; }

public:
	virtual void tick(float _dt) override;
	virtual void beginOverLap(Collider* myCol, CObj* _othObj, Collider* _othCol) override;
	virtual void endOverLap(Collider* myCol, CObj* _othObj, Collider* _othCol) override;

public:
	Player();
	~Player();
};

