#include "pch.h"
#include "MyLayer.h"

#include "MyGCMgr.h"

#include "MyObject.h"

MyLayer::MyLayer()
{
}

MyLayer::~MyLayer()
{
	for (size_t i = 0; i < m_vecObject.size(); ++i)
	{
		delete m_vecObject[i];
	}
}

void MyLayer::begin()
{
	for (size_t i = 0; i < m_vecObject.size(); ++i)
	{
		m_vecObject[i]->begin();
	}
}

void MyLayer::tick(float _DT)
{
	for (size_t i = 0; i < m_vecObject.size(); ++i)
	{
		m_vecObject[i]->tick(_DT);
	}
}

void MyLayer::finaltick(float _DT)
{
	for (size_t i = 0; i < m_vecObject.size(); ++i)
	{
		m_vecObject[i]->finaltick(_DT);
	}

}

void MyLayer::render(HDC _dc)
{
	vector<MyObject*>::iterator iter = m_vecObject.begin();

	for (; iter != m_vecObject.end(); )
	{
		if ((*iter)->IsDead())
		{
			MyGCMgr::GetInst()->AddEntity(*iter);
			iter = m_vecObject.erase(iter);
		}
		else
		{
			(*iter)->render(_dc);
			++iter;
		}
	}
}
