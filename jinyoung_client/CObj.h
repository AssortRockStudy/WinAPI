#pragma once

#include "CEntity.h"
#include "CTaskMgr.h"
#include "CCamera.h"



class CComponent;
class CCollider;


class CObj
	: public CEntity
{
private:
	Vec2	m_Pos;
	Vec2	m_Scale;
	vector<CComponent*>	m_vecComponent;
	int					m_iLayerIdx;

public:
	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }
	Vec2 GetRenderPos() { return CCamera::GetInst()->GetRenderPos(m_Pos); }

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

	int GetLayerIdx() { return m_iLayerIdx; }
protected:
	template<typename T>
	T* AddComponent(const wstring& _strName = L"")
	{
		T* pNewCom = new T(this);
		m_vecComponent.push_back(pNewCom);
		pNewCom->SetName(_strName);
		return pNewCom;
	}
	
public:
	// Level 이 시작할 때 Level 안에 들어있던 오브젝트 or 레벨이 시작되고나서 레벨에 합류하는 오브젝트
	virtual void begin() {};

	// 매 틱마다 호출
	// 매 프레임 마다 오브젝트가 할 일
	virtual void tick(float _DT);
	// 상속받은 자식 클래스에서 재정의(override) 할 수 없음
	virtual void finaltick(float _DT) final;

	// 렌더링 함수
	// 매 프레임마다 화면에 오브젝트를 그리는 함수
	virtual void render(HDC _dc);

	// 오버랩 발생 시 호출
	virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) {}



public:
	CObj();
	virtual ~CObj();
private:
	virtual void Abstract() = 0;
	

	friend class CLevel;
};