#pragma once
// ���� �Ŵ���
// ������ �����ϴ� �Ŵ����� ����
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

