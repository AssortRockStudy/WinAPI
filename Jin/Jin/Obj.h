#pragma once
#include "Entity.h"
#include "TaskMgr.h"
#include "Camera.h"

class Component;

class Obj : public Entity
{
private:
	Vec2			m_Pos;
	Vec2			m_Scale;
	vector<Component*> m_vecComponent;

public:
	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }
	Vec2 GetRenderPos()
	{
		return Camera::GetInst()->GetRenderPos(m_Pos);
	}

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

public:
	virtual void tick(float _DT) = 0;
	virtual void render(HDC _dc);

protected:
	template<typename T>
	T* AddComponent()
	{
		T* pNewComponent = new T;
		m_vecComponent.push_back(pNewComponent);
		return pNewComponent;
	}

public:
	Obj();
	virtual ~Obj();
};

