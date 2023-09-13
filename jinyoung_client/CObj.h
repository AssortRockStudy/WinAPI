#pragma once

#include "CEntity.h"

class CObj
	: public CEntity
{
private:
	Vec2	m_Pos;
	Vec2	m_Scale;

public:
	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

public:
	// 매 프레임 마다 오브젝트가 할 일
	virtual void tick(float _DT) = 0; // 순수 가상함수 ==> 추상 클래스

	// 매 프레임마다 화면에 오브젝트를 그리는 함수
	virtual void render(HDC _dc);

public:
	CObj();
	virtual ~CObj();
};