#include "pch.h"
#include "Obj.h"
#include "Component.h"


Obj::Obj()
{
}

Obj::~Obj()
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		if (nullptr != m_vecComponent[i])
			delete m_vecComponent[i];
	}
}

void Obj::tick(float _DT)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->tick(_DT);
	}
}

void Obj::finaltick(float _DT)
{
	for (size_t i = 0; i < m_vecComponent.size(); ++i)
	{
		m_vecComponent[i]->finaltick(_DT);
	}
}

void Obj::render(HDC _dc)
{
	Vec2 vRenderPos = GetRenderPos();

	Rectangle(_dc
		, int(vRenderPos.x - m_Scale.x / 2)
		, int(vRenderPos.y - m_Scale.y / 2)
		, int(vRenderPos.x + m_Scale.x / 2)
		, int(vRenderPos.y + m_Scale.y / 2));
}
