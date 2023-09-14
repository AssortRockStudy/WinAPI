#include "pch.h"
#include "MyLevel.h"

#include "MyTimeMgr.h"
#include "MyObject.h"
#include "MyMonster.h"

MyLevel::MyLevel()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_Layer[i] = new MyLayer;
	}
}

MyLevel::~MyLevel()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		if (nullptr != m_Layer[i])
		{
			delete m_Layer[i];
		}
	}
}

void MyLevel::tick()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_Layer[i]->tick(DT);
	}
}

void MyLevel::render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_Layer[i]->render(_dc);
	}
}