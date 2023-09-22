#pragma once

#include "MyObject.h"

class MyCollider;

class MyMonster : public MyObject
{	
	GENERATED_OBJECT(MyObject);

private:
	float m_Speed;
	float monsterTime;

	Vec2 MonsterPos;
	Vec2 MonsterScale;

	MyCollider* m_Collider;
	FMonInfo	m_Info;

public:
	virtual void begin() override;
	virtual void tick(float _DT) override;
	virtual void render(HDC _dc) override;

public:
	virtual void BeginOverlap(MyCollider* _OwnCol, MyObject* _OtherObject, MyCollider* _OtherCol) override;

public:
	MyMonster();
	~MyMonster();
};

