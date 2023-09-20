#include "pch.h"
#include "CLevelMgr.h"

#include "CEngine.h"

#include "CLevel.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CPal.h"
#include "CCamera.h"

#include "CCollisionMgr.h"


CLevelMgr::CLevelMgr()
{

}

CLevelMgr::~CLevelMgr()
{
	if (m_pCurLevel)
	{
		if (nullptr != m_pCurLevel)
			delete m_pCurLevel;
	}
}

void CLevelMgr::init()
{
	// Level 
	m_pCurLevel = new CLevel;

	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));
	m_pCurLevel->setPlayer(pPlayer);

	m_pCurLevel->AddObject(PLAYER, pPlayer);
	//m_pCurLevel->AddObject(pPlayer);

	CMonster* pMonster = new CMonster;

	pMonster->SetPos(Vec2(600.f, 500.f));
	pMonster->SetScale(Vec2(50.f, 50.f));

	m_pCurLevel->setMonster(pMonster);
	//m_pCurLevel->AddObject(pMonster);
	m_pCurLevel->AddObject(MONSTER, pMonster);





	//pMonster = new CMonster;
	//pMonster->SetPos(Vec2(900.f, 500.f));
	//pMonster->SetScale(Vec2(100.f, 100.f));
	//m_pCurLevel->AddObject(pMonster);

	//pMonster = new CMonster;
	//pMonster->SetPos(Vec2(1200.f, 200.f));
	//pMonster->SetScale(Vec2(100.f, 100.f));
	//m_pCurLevel->AddObject(pMonster);

	// dynamic_cast
	//{
	//	CObj* pObj = nullptr;
	//	pObj = new CPlayer;
	//  CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj); // RTTI(Runtime Type Information)
	// 
	//	pObj = new CMonster;
	//	CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj); // RTTI(Runtime Type Information)
	//}

	// 카메라 설정
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	// 충돌 설정
	CCollisionMgr::GetInst()->CheckCollision(MONSTER, PLAYER);
	CCollisionMgr::GetInst()->CheckCollision(PLAYER_PJ, MONSTER);
	// 레벨 시작
	m_pCurLevel->begin();

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
