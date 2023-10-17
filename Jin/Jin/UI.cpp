#include "pch.h"
#include "UI.h"

UI::UI()
	: m_ParentUI(nullptr)
{
}

UI::~UI()
{
}

void UI::tick(float _DT)
{
	Super::tick(_DT);

	for (size_t i = 0; i < m_vecChildUI.size(); ++i)
	{
		m_vecChildUI[i]->tick(_DT);
	}
}

void UI::render(HDC _dc)
{
	Super::render(_dc);

	for (size_t i = 0; i < m_vecChildUI.size(); ++i)
	{
		m_vecChildUI[i]->render(_dc);
	}
}
