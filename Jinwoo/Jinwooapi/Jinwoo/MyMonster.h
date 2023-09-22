#pragma once

#include "MyObject.h"

class MyCollider;
class MyTexture;

class MyMonster : public MyObject
{	
	GENERATED_OBJECT(MyObject);

private:
	float m_Speed;
	float monsterTime;

	MyCollider* m_Collider;
	FMonInfo	m_Info;
	MyTexture*	m_Texture;

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

