#pragma once
class LevelMgr
{
	SINGLETON(LevelMgr);

private:
	class Level* m_pCurLevel;
	Level* m_arrLevels[(UINT)LEVEL_TYPE::END];


	void ChangeLevel(LEVEL_TYPE _Type);

public:
	Level* GetCurLevel()
	{
		return m_pCurLevel;


	}
	void init();
	void tick();
	void render(HDC _dc);

	friend class TaskMgr;
};

