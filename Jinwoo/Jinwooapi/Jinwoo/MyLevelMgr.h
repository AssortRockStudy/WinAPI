#pragma once

class MyLevelMgr
{
	SINGLETON(MyLevelMgr);

private:
	// 전방선언과 동시에 멤버변수 선언
	class MyLevel*	m_pCurLevel;
	MyLevel*		m_arrLevels[(UINT)LEVEL_TYPE::END];
	
public:
	MyLevel* GetCurLevel() { return m_pCurLevel; }
	void ChangeLevel(LEVEL_TYPE _Type);

public:
	void init();
	void tick();
	void render(HDC _dc);

	friend class MyTaskMgr;
};

