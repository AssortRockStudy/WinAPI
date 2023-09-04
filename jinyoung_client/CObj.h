#pragma once
#include "pch.h"

class CObj
{
private:
	POINT	m_Pos;
	POINT	m_Scale;

public:
	POINT GetPos() { return m_Pos; }
	POINT GetScale() { return m_Scale; }

	void SetPos(POINT _Pos) { m_Pos = _Pos; }
	void SetScale(POINT _Scale) { m_Scale = _Scale; }

public:
	// 매 프레임 마다 오브젝트가 할 일
	virtual void tick() = 0; // 순수 가상함수 ==> 추상 클래스

	// 매 프레임마다 화면에 오브젝트를 그리는 함수
	virtual void render(HDC _dc);

public:
	CObj();
	virtual ~CObj();
};

