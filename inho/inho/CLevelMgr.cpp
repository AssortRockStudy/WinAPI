#include "pch.h"

#include "CLevelMgr.h"

#include "CEngine.h"
#include "CLevel.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "CPaletteMgr.h"

CLevelMgr::CLevelMgr(){}
CLevelMgr::~CLevelMgr() {};

void CLevelMgr::init() {

	m_pCurLevel = new CLevel;

	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	m_pCurLevel->AddObject(pPlayer);

	for (int i = 0; i < 2; ++i) {
		CMonster* pMonster = new CMonster;
		pMonster->SetPos({ 300.f*(i+1) , 300.f});
		pMonster->SetScale({ 25.f, 25.f });

		m_pCurLevel->AddMonster(pMonster);
	}

	
}

void CLevelMgr::tick() {
	m_pCurLevel->tick();
}

void CLevelMgr::render(HDC _dc) {

	POINT ptResolution = CEngine::GetInst()->GetResolution();
	Rectangle(_dc, -1, -1, ptResolution.x, ptResolution.y);

	m_pCurLevel->render(_dc);
	CPaletteMgr::GetInst()->SelectBrush(CPaletteMgr::BrushColor::BWHITE);
	BitBlt(CEngine::GetInst()->GetMainDC(), 0, 0, ptResolution.x, ptResolution.y, _dc, 0, 0, SRCCOPY);
}