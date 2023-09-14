#pragma once
#include "CEntity.h"

class CObj;

class CLayer : 
	public CEntity
{
private:
	vector<CObj*>	m_vecObjects;

public:
	void tick(float _DT);
	void finaltick(float _DT);
	void render(HDC _dc);

	void AddObject(CObj* _pObject) { m_vecObjects.push_back(_pObject); }

public:
	CLayer();
	~CLayer();

	friend class CLevel;
};

