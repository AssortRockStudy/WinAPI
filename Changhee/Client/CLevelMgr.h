#pragma once

class CLevel;

class CLevelMgr
{
	SINGLETON(CLevelMgr);

private:
	CLevel* m_pCurLevel;

public:
	CLevel* GetCurLevel() { return m_pCurLevel; }
	
public:
	void init();
	void tick();
	void render(HDC _dc);

};

