#include "pch.h"
#include "BtnUI.h"

void BtnUI::tick(float _DT){
	Super::tick(_DT);
}

void BtnUI::render(HDC _dc){
	Vec2 vPos = getPos();
	Vec2 vScale = getScale();
	Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.y + vScale.y);

	Super::render(_dc);
}

BtnUI::BtnUI()
{
}

BtnUI::~BtnUI()
{
}
