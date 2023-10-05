#include "pch.h"
#include "Level.h"
#include "TimeMgr.h"
#include "Obj.h"


Level::Level()
{

}

Level::~Level()
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		delete m_vecObjects[i];
	}
}

void Level::tick()
{

	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->tick(DT);
	}
}

void Level::render(HDC _dc)
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->render(_dc);
	}
}
