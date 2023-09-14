#pragma once

#include "MyEntity.h"
#include "MyTaskMgr.h"

// 게임에서 존재하는 모든 객체들의 부모의 역할을 하는 클래스
// 얘가 객체를 만드는 게 아니다 -> 소멸자를 가상함수로 해야함
// 화면에 출력이 되어야하기 때문에 render가 필요함
// render에 필요한 멤버 -> 위치 & 크기 정보
class MyObject : public MyEntity
{
private:
	Vec2 m_Pos;
	Vec2 m_Scale;

public:
	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

public:
	// 순수 가상 함수
	virtual void tick(float _DT) = 0;
	// render는 따로 오버라이딩 하지않아도 부모쪽에서 사용할 수 있도록 구현함
	virtual void render(HDC _dc);

public:
	MyObject();
	virtual ~MyObject();
};

