#include "pch.h"
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
	Vec2 vPos = GetFinalPos();
	Vec2 vScale = GetScale();
	Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.y + vScale.y);

	// 부모클래스(CUI) 렌더함수 호출(자식 UI 들한테 render 를 호출한다)
	Super::render(_dc);


}

void CBtnUI::OnHovered(Vec2 _vMousePos)
{
}

void CBtnUI::MouseOn(Vec2 _vMousePos)
{

}

void CBtnUI::OnUnHovered(Vec2 _vMousePos)
{

}