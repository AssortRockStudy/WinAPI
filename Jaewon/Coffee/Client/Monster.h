#pragma once
#include "CObj.h"

class Collider;

class Monster : public CObj
{
	GENERATED_OBJECT(CObj);

private:
	Collider* collider;
	FMonInfo info;

public:
	void setMonsterInfo(const FMonInfo& _info) { info = _info; }

private:
	virtual void begin() override;
	virtual void tick(float _dt) override;
	virtual void render(HDC _dc) override;

	virtual void beginOverLap(Collider* myCol, CObj* _othObj, Collider* _othCol) override;

public:
	Monster();
	~Monster();
};

