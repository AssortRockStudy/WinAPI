#pragma once
class LevelMgr
{
	SINGLETON(LevelMgr);

private:
	class Level* m_CurLevel;

public:
	Level* GetCurLevel()
	{
		return m_CurLevel;
	}
	void init();
	void tick();
	void render(HDC _dc);

};

