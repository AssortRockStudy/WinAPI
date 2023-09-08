#pragma once

#include "MyObject.h"

class MyPlayer : public MyObject
{
	float m_Speed;

	HBITMAP		m_PlayerImage;
	HDC			m_PlayerDC;
	BITMAP		m_BitmapInfo;
	
public:
	virtual void tick(float _DT) override;
	virtual void render(HDC _dc) override;

public:
	MyPlayer();
	~MyPlayer();
};

