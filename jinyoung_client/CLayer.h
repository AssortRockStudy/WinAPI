#pragma once

#include "CEntity.h"


class CObj;

class CLayer
	: public CEntity
{
private:
	vector<CObj*> 	m_vecObjects;




public:
	void tick(float _DT);
	void render(HDC _dc);


	void AddObject(CObj* _Object) { m_vecObjects.push_back(_Object); }

public:
	CLayer();
	~CLayer();

	friend class CLevel;
};