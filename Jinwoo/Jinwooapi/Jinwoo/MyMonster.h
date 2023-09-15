#pragma once

#include "MyObject.h"

class MyMonster : public MyObject
{	
	GENERATED_OBJECT(MyObject);

private:
	float m_Speed;
	float monsterTime;

	Vec2 MonsterPos;
	Vec2 MonsterScale;

public:
	virtual void tick(float _DT) override;
	virtual void render(HDC _dc) override;

public:
	MyMonster();
	~MyMonster();
};

