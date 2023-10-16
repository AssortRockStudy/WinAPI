#pragma once

#include "MyEntity.h"

class MyObject;
class MyCollider;

class MyLayer : public MyEntity
{
private:
	vector<MyObject*>		m_vecObject;
	vector<MyCollider*>		m_vecCollider;

public:
	void begin();
	void tick(float _DT);
	void finaltick(float _DT);
	void render(HDC _dc);

	void clear() { m_vecCollider.clear(); }
	void AddObject(MyObject* _Object) { m_vecObject.push_back(_Object); }
	void RegisterCollider(MyCollider* _Collider) { m_vecCollider.push_back(_Collider); }

	const vector<MyObject*>& GetObjects() { return m_vecObject; }
	const vector<MyCollider*>& GetCollider() { return m_vecCollider; }

	void DeleteAllObjects();

public:
	MyLayer();
	~MyLayer();

	friend class MyLevel;
};

