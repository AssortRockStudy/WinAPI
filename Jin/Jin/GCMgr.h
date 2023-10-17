#pragma once


class Entity;

class GCMgr
{
	SINGLETON(GCMgr)

private:
	vector<Entity*> m_Entity;

public:
	void AddEntity(Entity* _Entity)
	{
		m_Entity.push_back(_Entity);
	}

	void tick();
};

