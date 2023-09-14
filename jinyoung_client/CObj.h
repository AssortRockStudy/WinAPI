#pragma once

#include "CEntity.h"
#include "CTaskMgr.h"
#include "CCamera.h"



class CComponent;
class CObj
	: public CEntity
{
private:
	Vec2	m_Pos;
	Vec2	m_Scale;
	vector<CComponent*>	m_vecComponent;

public:
	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }
	Vec2 GetRenderPos() { return CCamera::GetInst()->GetRenderPos(m_Pos); }

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }
	
protected:
	template<typename T>
	T* AddComponent()
	{
		T* pNewCom = new T;
		m_vecComponent.push_back(pNewCom);
		return pNewCom;
	}
	
public:
	// 매 프레임 마다 오브젝트가 할 일
	virtual void tick(float _DT) = 0; // 순수 가상함수 ==> 추상 클래스

	// 매 프레임마다 화면에 오브젝트를 그리는 함수
	virtual void render(HDC _dc);

public:
	CObj();
	virtual ~CObj();
};