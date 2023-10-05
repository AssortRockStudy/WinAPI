#pragma once
#include "Component.h"

class Collider : public Component
{
private:
	Vec2 m_vOffsetPos;
	Vec2 m_vScale;
	Vec2 m_vFinalPos;
	int		m_iCollisionCnt;


public:
	virtual void finaltick(float _DT) override;
	virtual void render(HDC _dc) override;

	void SetOffsetPos(Vec2 _vOffsetPos) 
	{ 
		m_vOffsetPos = _vOffsetPos; 
	}

	void SetScale(Vec2 _vScale) 
	{ 
		m_vScale = _vScale;
	}

	Vec2 GetPos()
	{
		return m_vFinalPos;
	}

	Vec2 GetOffsetPos()
	{
		return m_vOffsetPos;
	}
	Vec2 GetScale()
	{
		return m_vScale;
	}

	void BeginOverlap(Collider* _OtherCol);
	void Overlap(Collider* _OtherCol);
	void EndOverlap(Collider* _OtherCol);


public:
	Collider(Obj* _Owner);
	~Collider();
};

