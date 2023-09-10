#include "pch.h"
#include "CLevelMgr.h"

#include "CEngine.h"

#include "CLevel.h"
#include "CPlayer.h"
#include "CPal.h"



CLevelMgr::CLevelMgr()
{

}

CLevelMgr::~CLevelMgr()
{

}

void CLevelMgr::init()
{
	// Level 
	m_pCurLevel = new CLevel;

	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	m_pCurLevel->AddObject(pPlayer);
}

void CLevelMgr::tick()
{
	m_pCurLevel->tick();
}

void CLevelMgr::render(HDC _dc)
{
	// Level Render
	// 화면 Clear
	POINT ptResolution = CEngine::GetInst()->GetResolution();
	SelectObject(_dc, CPal::GetInst()->getHPen(WHITE));
	SelectObject(_dc, CPal::GetInst()->getHBrush(WHITE));
	Rectangle(_dc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	// 레벨 render
	m_pCurLevel->render(_dc);

	// m_SubDC -> m_DC 로 비트맵 복사
	BitBlt(CEngine::GetInst()->GetMainDC(), 0, 0, ptResolution.x, ptResolution.y, _dc, 0, 0, SRCCOPY);
}
