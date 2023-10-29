#pragma once
#include "pch.h"



class CLevelMgr
{
	SINGLETON(CLevelMgr);
private:
	class CLevel* m_pCurLevel;
	CLevel* m_arrLevels[(UINT)LEVEL_TYPE::END];

public:
	CLevel* GetCurLevel() { return m_pCurLevel; }

public:
	void init();
	void tick();
	void render(HDC _dc);
};