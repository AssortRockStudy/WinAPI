﻿#include "pch.h"
#include "CBtnUI.h"

CBtnUI::CBtnUI()
{
}

CBtnUI::~CBtnUI()
{
}

void CBtnUI::tick(float _DT)
{

	Super::tick(_DT);
}

void CBtnUI::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.y + vScale.y);

	Super::render(_dc);
}

