#pragma once
#include "Entity.h"

class Obj;
class Collider;


class Layer : public Entity
{
private:
	vector<Obj*>				m_vecObjects;
	vector<Collider*>		m_vecCollider;

public:
	void begin();
	void tick(float _DT);
	void render(HDC _dc);
	void finaltick(float _DT);
	void clear()
	{
		m_vecCollider.clear();
	}

	void AddObject(Obj* _Object)
	{
		m_vecObjects.push_back(_Object);
	}

	void RegisterCollider(Collider* _Collider)
  	{
		m_vecCollider.push_back(_Collider);
	}


	const vector<Obj*>& GetObjects() 
	{ 
		return  m_vecObjects; 
	}

	const vector<Collider*>& GetColliders()
	{
		return m_vecCollider;
	}

	void DeleteAllObjects();

public:
	Layer();
	~Layer();

	friend class Level;



};

