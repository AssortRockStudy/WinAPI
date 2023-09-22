#pragma once

#include "MyObject.h"

class MyCollider;

class MyPlayer : public MyObject
{
	GENERATED_OBJECT(MyObject);

private:
	float m_Speed;

	HBITMAP		m_PlayerImage;
	HDC			m_PlayerDC;
	BITMAP		m_BitmapInfo;

	MyCollider* m_Collider;
	
public:
	virtual void tick(float _DT) override;
	virtual void render(HDC _dc) override;
	
	virtual void Overlap(MyCollider* _OwnCol, MyObject* _OtherObject, MyCollider* _OtherCol) override;

public:
	MyPlayer();
	~MyPlayer();
};

