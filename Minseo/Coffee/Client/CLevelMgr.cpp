#include "pch.h"
#include "CLevelMgr.h"

#include "CEngine.h"

#include "CLevel.h"
#include "CPlayer.h"
#include "CMonster.h"


void CLevelMgr::init()
{
	// Level 
	m_pCurLevel = new CLevel;

	// 플레이어 생성
	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	m_pCurLevel->AddObject(pPlayer); // 나중에 레이어도 넣어야겠지?

	// 몬스터 생성
	CMonster* pMonster = nullptr;

	pMonster = new CMonster;
	pMonster->SetPos(Vec2(900.f, 500.f));
	pMonster->SetScale(Vec2(100.f, 100.f));
	m_pCurLevel->AddObject(pMonster);

}

void CLevelMgr::tick()
{
	// Level tick
	m_pCurLevel->tick();

	// 나중에 레벨 별로 다른 tick를 수행하거나, 상황 별로 실행할 tick 예외 처리를 여기서 하면 될 듯?
}

void CLevelMgr::render(HDC _DC)
{
	// 사용을 위해 엔진 쪽 멤버를 함수로 받아옴.
	POINT ptResolution = CEngine::GetInst()->GetResolution();

	// 화면 클리어(커다란 네모)
	Rectangle(_DC, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	// Level render
	m_pCurLevel->render(_DC);// 이제 모든 그림은 SubDC에 그려짐

	// 마지막으로 m_SubDC->m_DC로 비트맵 복사하기
	BitBlt(CEngine::GetInst()->GetMainDC(), 0, 0, ptResolution.x, ptResolution.y, _DC, 0, 0, SRCCOPY);
}

CLevelMgr::~CLevelMgr() {}
CLevelMgr::CLevelMgr(){}