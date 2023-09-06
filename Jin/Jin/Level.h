#pragma once
class Obj;

class Level
{
private:
	vector<Obj*> m_vecObjects;

public:
	void tick();
	void render(HDC _dc);

public:
	void AddObject(Obj* _Object)
	{
		m_vecObjects.push_back(_Object);
	}

public:
	Level();
	~Level();
};
