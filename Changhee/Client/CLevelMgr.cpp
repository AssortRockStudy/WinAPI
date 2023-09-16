#include "pch.h"
#include "CLevelMgr.h"


#include "CEngine.h"
#include "CLevel.h"
#include "CCollisionMgr.h"


// �ӽ�
#include "CPlayer.h"
#include "CMonster.h"

CLevelMgr::CLevelMgr()
	: m_pCurLevel(nullptr)
{}


CLevelMgr::~CLevelMgr()
{
	if(m_pCurLevel != nullptr)
		delete m_pCurLevel;
}

void CLevelMgr::init()
{
	// ī�޶� ����
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;

	CCamera::GetInst()->SetLookAt(vLookAt);

	// �浹 ����
	CCollisionMgr::GetInst()->CheckCollision(LAYER::MONSTER, LAYER::PLAYER);


	// Level ����
	m_pCurLevel = new CLevel;

	// Plyaer ����
	CPlayer* pPlayer = new CPlayer;
	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	m_pCurLevel->AddObject(LAYER::PLAYER, pPlayer);


}

void CLevelMgr::tick()
{
	m_pCurLevel->tick();
}

void CLevelMgr::render(HDC _dc)
{
	POINT ptResolution = CEngine::GetInst()->GetResolution();

	// ȭ�� clear
	Rectangle(_dc, -1, -1, ptResolution.x + 1, ptResolution.y);

	// Level render
	m_pCurLevel->render(_dc);
}
