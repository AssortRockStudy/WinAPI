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

	template<typename T>
	void GetObjects(vector<T*>& _Out);

public:
	Level();
	~Level();
};

template<typename T>
inline void Level::GetObjects(vector<T*>& _Out)
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		T* pObj = dynamic_cast<T*>(m_vecObjects[i]);

		if (nullptr != pObj)
		{
			_Out.push_back(pObj);
		}
	}
}
