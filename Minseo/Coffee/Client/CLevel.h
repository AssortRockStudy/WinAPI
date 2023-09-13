#pragma once
#include "CMonster.h"

class CObj; 

class CLevel
{
private:
	vector<CObj*> 	m_vecObjects;

	CMonster* m_Monster1;
	CMonster* m_Monster2;
public:
	void tick();
	void render(HDC _dc);

public:
	void AddObject(CObj* _Object)
	{
		m_vecObjects.push_back(_Object);
	}

	CMonster* GetMonster1() { return m_Monster1; }
	void SetMonster1(CMonster* mon1) { m_Monster1 = mon1; }

	CMonster* GetMonster2() { return m_Monster2; }
	void SetMonster2(CMonster* mon2) { m_Monster2 = mon2; }

	CMonster* GetCurruntMonster(Vec2 playerPos);
public:
	CLevel();
	~CLevel();
};
