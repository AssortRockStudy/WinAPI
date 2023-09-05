#pragma once

class CObj
{
private:
	POINT	m_Pos;
	POINT	m_Scale;

public:
	POINT GetPos() { return m_Pos; }
	POINT GetScale() { return m_Scale; }

	void SetPos(POINT _Pos) { m_Pos = _Pos; }
	void SetScale(POINT _Scale) { m_Scale = _Scale; }


public:
	virtual void tick() = 0;
	virtual void render(HDC _dc);



public:
	CObj();
	virtual ~CObj();
};

