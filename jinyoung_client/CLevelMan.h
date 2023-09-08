#pragma once
#include "pch.h"



class CLevelMan
{
	SINGLETON(CLevelMan);
private:
	class CLevel* m_pCurLevel;

public:
	void init();
	void tick();
};

