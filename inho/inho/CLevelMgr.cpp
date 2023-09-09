#include "pch.h"

#include "CLevelMgr.h"

#include "CEngine.h"
#include "CLevel.h"

#include "CPlayer.h"

CLevelMgr::CLevelMgr(){}
CLevelMgr::~CLevelMgr() {};

void CLevelMgr::init() {

	m_pCurLevel = new CLevel;

	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	m_pCurLevel->AddObject(pPlayer);
}

void CLevelMgr::tick() {
	m_pCurLevel->tick();
}

void CLevelMgr::render(HDC _dc) {

	POINT ptResolution = CEngine::GetInst()->GetResolution();
	Rectangle(_dc, -1, -1, ptResolution.x, ptResolution.y);

	m_pCurLevel->render(_dc);

	BitBlt(CEngine::GetInst()->GetMainDC(), 0, 0, ptResolution.x, ptResolution.y, _dc, 0, 0, SRCCOPY);
}