#include "pch.h"
#include "MyLevel.h"

#include "MyTimeMgr.h"
#include "MyObject.h"
#include "MyMonster.h"

MyLevel::MyLevel()
{

}

MyLevel::~MyLevel()
{
	for (size_t i = 0; i < m_vecObject.size(); ++i)
	{
		delete m_vecObject[i];
	}
}

void MyLevel::tick()
{
	for (size_t i = 0; i < m_vecObject.size(); ++i)
	{
		m_vecObject[i]->tick(DT);
	}
}

void MyLevel::render(HDC _dc)
{
	for (size_t i = 0; i < m_vecObject.size(); ++i)
	{
		m_vecObject[i]->render(_dc);
	}
}