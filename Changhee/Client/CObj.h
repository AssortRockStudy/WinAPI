#pragma once

class CObj
{
private:
	Vec2	m_vPos;
	Vec2	m_vScale;

public:
	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }


public:
	virtual void tick(float _DT) = 0;
	virtual void render(HDC _dc);



public:
	CObj();
	virtual ~CObj();
};

