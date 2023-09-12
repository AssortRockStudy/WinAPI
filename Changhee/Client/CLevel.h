#pragma once


class CObj;


class CLevel
{
private:
	vector<CObj*>	m_vecObjects;


	vector<CObj*>	m_vecMonsters;


public:
	void tick();
	void render(HDC _dc);


public:
	void AddObject(CObj* _Object) { m_vecObjects.push_back(_Object); }


	void AddMonster(CObj* _Object) { m_vecMonsters.push_back(_Object); }
	vector<CObj*> GetMonster() { return m_vecMonsters; }


public:
	CLevel();
	~CLevel();

};

