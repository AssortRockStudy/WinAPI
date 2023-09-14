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

	vector<CComponent*> m_vecComponent;		// ÄÄÆ÷³ÍÆ® º¤ÅÍ

public:
	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }
	Vec2 GetRenderPos() { return CCamera::GetInst()->GetRenderPos(m_vPos); }

	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }


protected:
	template<typename T>
	CComponent* AddComponent()
	{
		T* pNewComponent = new T(this);
		m_vecComponent.push_back(pNewComponent);
		return pNewComponent;
	}

public:
	virtual void tick(float _DT);
	virtual void finaltick(float _DT) final;
	virtual void render(HDC _dc);


private:
	virtual void Abstract() = 0;

public:
	CObj();
	virtual ~CObj();
};

