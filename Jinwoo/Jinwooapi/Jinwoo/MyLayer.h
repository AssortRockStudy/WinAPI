#pragma once

#include "MyEntity.h"

class MyObject;
class MyCollider;

class MyLayer : public MyEntity
{
private:
	vector<MyObject*>		m_vecObject;
	vector< MyCollider*>	m_vecCollider;

public:
	void tick(float _DT);
	void finaltick(float _DT);
	void render(HDC _dc);

	void AddObject(MyObject* _Object) { m_vecObject.push_back(_Object); }

public:
	MyLayer();
	~MyLayer();

	friend class MyLevel;
};

