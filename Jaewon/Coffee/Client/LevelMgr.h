#pragma once
// 레벨 매니저
// 레벨을 관리하는 매니저를 생성
class LevelMgr
{
	SINGLETON(LevelMgr);

private:
	class CLevel* curLevel;
	CLevel* arrLevels[(UINT)LEVEL_TYPE::END];

public:
	CLevel* getCurLevel() { return curLevel; }

private:
	void changeLevel(LEVEL_TYPE _Type);

public:
	void init();
	void tick();
	void render(HDC _dc);

	friend class TaskMgr;
};

