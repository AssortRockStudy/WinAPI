#include "pch.h"
#include "MyUI.h"

#include "MyKeyMgr.h"

MyUI::MyUI() : m_ParentUI(nullptr), m_bMouseOn(false), m_bMouseOn_Prev(false)
{
}

MyUI::~MyUI()
{
}



void MyUI::tick(float _DT)
{
	Super::tick(_DT);

	// 최종 좌표 연산하기
	m_vFinalPos = GetPos();

	if (nullptr != m_ParentUI)
	{
		// 부모 클래스가 있다면 부모 UI의 최종 좌표를 기점으로
		// 자신의 위치를 결정한다
		m_vFinalPos += m_ParentUI->GetFinalPos();
	}

	// 마우스 상태 체크
	m_bMouseOn_Prev = m_bMouseOn;

	Vec2 vMousePos = MyKeyMgr::GetInst()->GetMousePos();

	if (m_vFinalPos.x <= vMousePos.x && vMousePos.x <= m_vFinalPos.x + GetScale().x
		&& m_vFinalPos.y <= vMousePos.y && vMousePos.y <= m_vFinalPos.y + GetScale().y)
	{
		m_bMouseOn = true;
	}
	else
	{
		m_bMouseOn = false;
	}

	// 자식 UI tick 호출
	for (size_t i = 0; i < m_vecChildUI.size(); ++i)
	{
		m_vecChildUI[i]->tick(_DT);
	}
}

void MyUI::render(HDC _dc)
{
	Super::render(_dc);

	for (size_t i = 0; i < m_vecChildUI.size(); ++i)
	{
		m_vecChildUI[i]->render(_dc);
	}
}