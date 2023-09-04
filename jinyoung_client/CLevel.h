#pragma once

class CObj;

//
//오브젝트를 vector에 넣는이유
// 
//


class CLevel
{
private:
	vector<CObj*> m_vecObjects;

public:
	void tick();
	void render(HDC _dc);

public:
	CLevel();
	~CLevel();

};

