#pragma once

class CEntity;

class GCMgr
{
	SINGLETON(GCMgr);

private:
	vector<CEntity*> mEntity;

public:
	void addEntity(CEntity* _ent) {
		mEntity.push_back(_ent);
	}

public:
	void tick();
};

