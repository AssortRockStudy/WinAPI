#include "pch.h"
#include "Layer.h"
#include "Obj.h"

Layer::Layer()
{
}

Layer::~Layer()
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		delete m_vecObjects[i];
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
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->render(_dc);
	}
}