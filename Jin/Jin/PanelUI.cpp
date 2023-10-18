#include "pch.h"
#include "PanelUI.h"

PanelUI::PanelUI()
{
}

PanelUI::~PanelUI()
{
}

void PanelUI::tick(float _DT)
{
	Super::tick(_DT);
}

void PanelUI::render(HDC _dc)
{
	Vec2 vPos = GetFinalPos();
	Vec2 vScale = GetScale();
	Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.x+vScale.y);

	Super::render(_dc);
}
