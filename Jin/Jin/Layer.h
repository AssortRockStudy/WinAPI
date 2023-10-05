#pragma once
#include "Entity.h"

class Obj;


class Layer : public Entity
{
private:
	vector<Obj*> m_vecObjects;

public:
	void tick(float _DT);
	void render(HDC _dc);

	void AddObject(Obj* _Object)
	{
		m_vecObjects.push_back(_Object);
	}

public:
	Layer();
	~Layer();

	friend class Level;



};

