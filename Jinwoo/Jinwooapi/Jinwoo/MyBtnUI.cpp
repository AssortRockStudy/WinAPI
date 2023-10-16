#include "pch.h"
#include "MyBtnUI.h"

MyBtnUI::MyBtnUI()
{
}

MyBtnUI::~MyBtnUI()
{
}

void MyBtnUI::tick(float _DT)
{

	Super::tick(_DT);
}

void MyBtnUI::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.y + vScale.y);

	Super::render(_dc);
}
