#include "pch.h"
#include "MyLayer.h"

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

void MyLayer::tick(float _DT)
{
	for (size_t i = 0; i < m_vecObject.size(); ++i)
	{
		m_vecObject[i]->tick(_DT);
	}
}

void MyLayer::render(HDC _dc)
{
	for (size_t i = 0; i < m_vecObject.size(); ++i)
	{
		m_vecObject[i]->render(_dc);
	}
}
