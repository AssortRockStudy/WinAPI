#pragma once

class CObj
{
private:
	Vec2	m_Pos;
	Vec2	m_Scale;

public:
	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }


public:
	virtual void tick(float _DT) = 0;
	virtual void render(HDC _dc);



public:
	CObj();
	virtual ~CObj();
};

