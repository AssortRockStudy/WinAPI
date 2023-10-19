#include "pch.h"
#include "UI.h"

#include "KeyMgr.h"

UI::UI()
	: m_ParentUI(nullptr)
	, m_bMouseOn(false)
	, m_bMouseOn_Prev(false)
	, m_bMouseLBtnDown(false)
{
}

UI::~UI()
{
	for (size_t i = 0; i < m_vecChildUI.size(); ++i)
	{
		delete m_vecChildUI[i];
	}
}

void UI::tick(float _DT)
{
	Super::tick(_DT);

	for (size_t i = 0; i < m_vecChildUI.size(); ++i)
	{
		m_vecChildUI[i]->tick(_DT);
	}

	m_vFinalPos = GetPos();

	if (nullptr != m_ParentUI)
	{
		m_vFinalPos += m_ParentUI->GetFinalPos();
	}

	m_bMouseOn_Prev = m_bMouseOn;

	Vec2 vMousePos = KeyMgr::GetInst()->GetMousePos();
	if (m_vFinalPos.x <= vMousePos.x && vMousePos.x <= m_vFinalPos.x + GetScale().x
		&& m_vFinalPos.y <= vMousePos.y && vMousePos.y <= m_vFinalPos.y + GetScale().y)
	{
		m_bMouseOn = true;
	}
	else
	{
		m_bMouseOn = false;
	}

}

void UI::render(HDC _dc)
{
	Super::render(_dc);

	for (size_t i = 0; i < m_vecChildUI.size(); ++i)
	{
		m_vecChildUI[i]->render(_dc);
	}
}
