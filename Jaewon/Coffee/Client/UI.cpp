#include "pch.h"
#include "UI.h"

void UI::tick(float _DT)
{
	Super::tick(_DT);
	for (size_t i = 0; i < vecChildUI.size(); ++i)
		vecChildUI[i]->tick(_DT);
}

void UI::render(HDC _dc)
{
	Super::render(_dc);
	for (size_t i = 0; i < vecChildUI.size(); ++i)
		vecChildUI[i]->render(_dc);
}

UI::UI():parentUI(nullptr){}

UI::~UI(){}
