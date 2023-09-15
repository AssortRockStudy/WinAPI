#pragma once

#include "MyEntity.h"
#include "MyTaskMgr.h"
#include "MyCameraMgr.h"

class MyComponent;

// 게임에서 존재하는 모든 객체들의 부모의 역할을 하는 클래스
// 얘가 객체를 만드는 게 아니다 -> 소멸자를 가상함수로 해야함
// 화면에 출력이 되어야하기 때문에 render가 필요함
// render에 필요한 멤버 -> 위치 & 크기 정보
class MyObject : public MyEntity
{
private:
	Vec2					m_Pos;
	Vec2					m_Scale;
	vector<MyComponent*>	m_vecComponent;

protected:
	template <typename T>
	T* AddComponent()
	{
		T* pNewCom = new T(this);
		m_vecComponent.push_back(pNewCom);
		return pNewCom;
	}

public:
	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }
	Vec2 GetRenderPos() { return MyCameraMgr::GetInst()->GetRenderPos(m_Pos); }

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

public:
	virtual void tick(float _DT);
	// 가상함수 뒤에 final을 붙임으로써 오버라이딩을 막음(finaltick의 final과는 다름)
	virtual void finaltick(float _DT) final;
	virtual void render(HDC _dc);

private:
	// 추상클래스를 위한 함수
	virtual void Abstract() = 0;

public:
	MyObject();
	virtual ~MyObject();
};

