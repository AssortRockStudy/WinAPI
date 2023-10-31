#include "pch.h"
#include "CPanelUI.h"

#include "CKeyman.h"

CPanelUI::CPanelUI()
{
}

CPanelUI::~CPanelUI()
{
}

void CPanelUI::tick(float _DT)
{
	if (IsLBtnDown())
	{
		Vec2 vDiff = m_vLbtnDownPos - CKeyman::GetInst()->GetMousePos();
		Vec2 vPos = GetPos();
		vPos -= vDiff;
		SetPos(vPos);

		m_vLbtnDownPos = CKeyman::GetInst()->GetMousePos();
	}

	Super::tick(_DT);
}

void CPanelUI::render(HDC _dc)
{
	Vec2 vPos = GetFinalPos();
	Vec2 vScale = GetScale();
	SELECT_PEN(_dc, RED_PEN);
	Rectangle(_dc, vPos.x, vPos.y, vPos.x + vScale.x, vPos.y + vScale.y);

	Super::render(_dc);
}
void CPanelUI::LBtnDown(Vec2 _MousePos)
{
	// 마우스 왼쪽 버튼이 눌렸을 때 마우스의 위치를 기록
	m_vLbtnDownPos = _MousePos;
}
