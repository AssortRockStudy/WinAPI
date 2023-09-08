#pragma once

class MyLevelMgr
{
	SINGLETON(MyLevelMgr);

private:
	// 전방선언과 동시에 멤버변수 선언
	class MyLevel* m_pCurLevel;
	
public:
	MyLevel* GetCurLevel() { return m_pCurLevel; }

public:
	void init();
	void tick();
	void render(HDC _dc);
};

