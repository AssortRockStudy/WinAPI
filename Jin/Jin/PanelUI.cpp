#include "pch.h"
#include "PanelUI.h"
#include "KeyMgr.h"

PanelUI::PanelUI()
{
}

PanelUI::~PanelUI()
{
}

void PanelUI::tick(float _DT)
{
	if (IsLBtnDown())
	{
		Vec2 vDiff = m_vLBtnDownPos - KeyMgr::GetInst()->GetMousePos();
		Vec2 vPos = GetPos();
		vPos -= vDiff;
		SetPos(vPos);

		m_vLBtnDownPos = KeyMgr::GetInst()->GetMousePos();
	}



	Super::tick(_DT);
}

void PanelUI::render(HDC _dc)
{
	Vec2 vPos = GetFinalPos();
	Vec2 vScale = GetScale();
	Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.y+vScale.y);

	Super::render(_dc);
}

void PanelUI::LBtnDown(Vec2 _MousePos)
{
	m_vLBtnDownPos = _MousePos;
}
