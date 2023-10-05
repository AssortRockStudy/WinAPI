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
	void tick(float _DT);
	void render(HDC _dc);
	void finaltick(float _DT);

	void AddObject(Obj* _Object)
	{
		m_vecObjects.push_back(_Object);
	}

public:
	Layer();
	~Layer();

	friend class Level;



};

