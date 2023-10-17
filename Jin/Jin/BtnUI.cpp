#include "pch.h"
#include "BtnUI.h"

BtnUI::BtnUI()
{
}

BtnUI::~BtnUI()
{
}

void BtnUI::tick(float _DT)
{
	Super::tick(_DT);
}

void BtnUI::render(HDC _dc)
{

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	
	Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.y + vScale.y);

	Super::render(_dc);
}
