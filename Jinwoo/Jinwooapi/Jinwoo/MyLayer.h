#pragma once

#include "MyEntity.h"

class MyObject;

class MyLayer : public MyEntity
{
private:
	vector<MyObject*> m_vecObject;

public:
	void tick(float _DT);
	void render(HDC _dc);

	void AddObject(MyObject* _Object) { m_vecObject.push_back(_Object); }

public:
	MyLayer();
	~MyLayer();

	friend class MyLevel;
};

