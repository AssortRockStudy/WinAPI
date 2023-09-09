#pragma once
// 레벨 매니저
// 레벨을 관리하는 매니저를 생성
class LevelMgr
{
	SINGLETON(LevelMgr);

private:
	class CLevel* curLevel;

public:
	CLevel* getCurLevel() { return curLevel; }

public:
	void init();
	void tick();
	void render(HDC _dc);
};

