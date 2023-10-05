#pragma once
class LevelMgr
{
	SINGLETON(LevelMgr);

private:
	class Level* m_pCurLevel;

public:
	Level* GetCurLevel()
	{
		return m_pCurLevel;

	}
	void init();
	void tick();
	void render(HDC _dc);

};

