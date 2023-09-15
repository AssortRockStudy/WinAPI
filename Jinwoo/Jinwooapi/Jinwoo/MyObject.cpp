#include "pch.h"
#include "MyObject.h"

#include "MyComponent.h"

MyObject::MyObject()
{

}

MyObject::~MyObject()
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		if (nullptr != m_vecComponent[i])
		{
			delete m_vecComponent[i];
		}
	}
}


void MyObject::tick(float _DT)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->tick(_DT);
	}
}

void MyObject::finaltick(float _DT)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->finaltick(_DT);
	}
}

void MyObject::render(HDC _dc)
{
	Vec2 vRenderPos = GetRenderPos();

	Rectangle(_dc
		, int(vRenderPos.x - m_Scale.x / 2)
		, int(vRenderPos.y - m_Scale.y / 2)
		, int(vRenderPos.x + m_Scale.x / 2)
		, int(vRenderPos.y + m_Scale.y / 2));
}