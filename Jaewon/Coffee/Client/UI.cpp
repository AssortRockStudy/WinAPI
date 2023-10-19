#include "pch.h"
#include "UI.h"
#include "KeyMgr.h"

void UI::tick(float _DT)
{
	Super::tick(_DT);
	finalPos = getPos();

	if (nullptr != parentUI)
		finalPos += parentUI->getFinalPos();

	mouseOnPrev = mMouseOn;

	Vec2 vMousePos = KeyMgr::GetInst()->getMousePos();
	if (finalPos.x <= vMousePos.x && vMousePos.x <= finalPos.x + getScale().x
		&& finalPos.y <= vMousePos.y && vMousePos.y <= finalPos.y + getScale().y)
		mMouseOn = true;
	else
		mMouseOn = false;
	for (size_t i = 0; i < vecChildUI.size(); ++i)
		vecChildUI[i]->tick(_DT);
}

void UI::render(HDC _dc)
{
	Super::render(_dc);
	for (size_t i = 0; i < vecChildUI.size(); ++i)
		vecChildUI[i]->render(_dc);
}

UI::UI():parentUI(nullptr), mMouseOn(false), mouseOnPrev(false){}

UI::~UI(){}
