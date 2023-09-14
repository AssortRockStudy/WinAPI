#pragma once
#include "CEntity.h"

#include "CCamera.h"

class CComponent;

class CObj :
	public CEntity
{
private:
	Vec2				m_vPos;
	Vec2				m_vScale;

	vector<CComponent*> m_vecComponent;

public:
	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }
	Vec2 GetRenderPos() { return CCamera::GetInst()->GetRenderPos(m_vPos); }


	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

public:
	virtual void tick(float _DT) = 0;
	virtual void render(HDC _dc);



public:
	CObj();
	virtual ~CObj();
};

