#include "pch.h"
#include "PanelUI.h"
#include "KeyMgr.h"

void PanelUI::tick(float _DT)
{
	if (isLBtnDown()){
		Vec2 diff = LbtnDownPos - KeyMgr::GetInst()->getMousePos();
		Vec2 vPos = getPos();
		vPos -= diff;
		setPos(vPos);
		LbtnDownPos = KeyMgr::GetInst()->getMousePos();
	}
	Super::tick(_DT);
}

void PanelUI::render(HDC _dc)
{
	Vec2 vPos = getFinalPos();
	Vec2 vScale = getScale();
	Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.y + vScale.y);
	Super::render(_dc);
}

void PanelUI::LBtnDown(Vec2 _vMousePos)
{
	LbtnDownPos = _vMousePos;
}

PanelUI::PanelUI(){}

PanelUI::~PanelUI(){}

