#include "pch.h"
#include "MyUI.h"

MyUI::MyUI()
{
}

MyUI::~MyUI()
{
}



void MyUI::tick(float _DT)
{
	Super::tick(_DT);

	for (size_t i = 0; i < m_vecChildUI.size(); ++i)
	{
		m_vecChildUI[i]->tick(_DT);
	}
}

void MyUI::render(HDC _dc)
{
	Super::render(_dc);

	for (size_t i = 0; i < m_vecChildUI.size(); ++i)
	{
		m_vecChildUI[i]->render(_dc);
	}
}