#pragma once
#include <typeinfo>
class CObj;
class CPlayer;
class CMonster;


//
//오브젝트를 vector에 넣는이유
// 
//


class CLevel
{
private:
	vector<CObj*> m_vecObjects;
	CPlayer* pcp;
	CMonster* pcm;

public:
	void tick();
	void render(HDC _dc);
	void AddObject(CObj* _Object)
	{
		m_vecObjects.push_back(_Object);
	}

	__inline void setPlayer(CPlayer* _pcp) { pcp = _pcp; }
	__inline CPlayer* getPlayer() { return pcp; }

	__inline void setMonster(CMonster* _pcm) { pcm = _pcm; }
	__inline CMonster* getMonster()
	{
		//if (nullptr==pcp) {
		//	vector<CObj*>::iterator it;
		//	for (it = m_vecObjects.begin(); m_vecObjects.end() != it; ++it)
		//	{
		//		if ("CMonster" == typeid((*(*it))).name())
		//		{
		//			break;
		//		}
		//	}
		//	pcm= (CMonster*)(*it);
		//}
		return pcm;
	}


public:
	CLevel();
	~CLevel();

};

