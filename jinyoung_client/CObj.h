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
		T* pNewCom = new T(this);
		m_vecComponent.push_back(pNewCom);
		return pNewCom;
	}
	
public:
	virtual void tick(float _DT);
	virtual void finaltick(float _DT) final; // 상속받은 자식 클래스에서 재정의(override) 할 수 없음
	// 매 프레임 마다 오브젝트가 할 일

	// 매 프레임마다 화면에 오브젝트를 그리는 함수
	virtual void render(HDC _dc);

public:
	CObj();
	virtual ~CObj();
private:
	virtual void Abstract() = 0;
};