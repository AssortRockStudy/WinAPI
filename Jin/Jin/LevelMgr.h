#pragma once
class LevelMgr
{
	SINGLETON(LevelMgr);

private:
	class Level* m_pCurLevel;
	Level* m_arrLevels[(UINT)LEVEL_TYPE::END];

public:
	Level* GetCurLevel()
	{
		return m_pCurLevel;

	}
	void init();
	void tick();
	void render(HDC _dc);

};

