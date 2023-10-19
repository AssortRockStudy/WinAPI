#include "pch.h"
#include "PanelUI.h"

void PanelUI::tick(float _DT)
{
	Super::tick(_DT);
}

void PanelUI::render(HDC _dc)
{
	Vec2 vPos = getFinalPos();
	Vec2 vScale = getScale();
	Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.y + vScale.y);
	Super::render(_dc);
}

PanelUI::PanelUI(){}

PanelUI::~PanelUI(){}

