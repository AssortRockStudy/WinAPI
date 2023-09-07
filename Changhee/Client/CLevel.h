#pragma once


class CObj;


class CLevel
{
private:
	vector<CObj*>	m_vecObjects;


public:
	void tick();
	void render(HDC _dc);


public:
	void AddObject(CObj* _Object) { m_vecObjects.push_back(_Object); }

public:
	CLevel();
	~CLevel();

};

