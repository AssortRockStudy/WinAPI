#pragma once

class CObj;

//
//������Ʈ�� vector�� �ִ�����
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

