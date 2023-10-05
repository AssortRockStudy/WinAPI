#include "pch.h"
#include "Level.h"
#include "TimeMgr.h"
#include "Layer.h"
#include "Obj.h"


Level::Level()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i] = new Layer;
	}
}

Level::~Level()
{
	for (UINT  i = 0; i < LAYER::END; ++i)
	{
		if (nullptr != m_Layer[i])
			delete m_Layer[i];
	}
}

void Level::begin()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->begin();
	}
}

void Level::tick()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->clear();
	}

	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->tick(DT);
	}

	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->finaltick(DT);
	}
}

void Level::render(HDC _dc)
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->render(_dc);
	}
}

void Level :: AddObject(LAYER _LayerType, Obj* _Object)
{
	m_Layer[_LayerType]->AddObject(_Object);

	_Object->m_iLayerIdx = _LayerType;
}
