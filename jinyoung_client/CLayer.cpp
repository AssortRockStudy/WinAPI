#include "pch.h"
#include "CLayer.h"

#include "CObj.h"



CLayer::CLayer()
{
}

CLayer::~CLayer()
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		delete m_vecObjects[i];
	}
}

void CLayer::tick(float _DT)
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->tick(_DT);
	}
}

void CLayer::render(HDC _dc)
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->render(_dc);
	}
}