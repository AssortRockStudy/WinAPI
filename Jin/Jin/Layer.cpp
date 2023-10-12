#include "pch.h"
#include "Layer.h"
#include "Obj.h"
#include "GCMgr.h"

Layer::Layer()
{
}

Layer::~Layer()
{
	DeleteAllObjects();
}

void Layer::begin()
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->begin();
	}
}

void Layer::tick(float _DT)
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->tick(_DT);
	}
}

void Layer::render(HDC _dc)
{
	//for (size_t i = 0; i < m_vecObjects.size(); ++i)
	//{
	//	m_vecObjects[i]->render(_dc);
	//}
	vector<Obj*>::iterator iter = m_vecObjects.begin();
	for (; iter != m_vecObjects.end();)
	{
		if ((*iter)->IsDead())
		{
			GCMgr::GetInst()->AddEntity((*iter));
			iter = m_vecObjects.erase(iter);
		}
		else
		{
			(*iter)->render(_dc);
			++iter;
		}
	}
}

void Layer::finaltick(float _DT)
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->finaltick(_DT);
	}
}

void Layer::DeleteAllObjects()
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		delete m_vecObjects[i];
	}
	m_vecObjects.clear();
}
