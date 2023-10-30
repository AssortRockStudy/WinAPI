#include "pch.h"
#include "CPlayLevel.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "CPlatform.h"

#include "CEngine.h"
#include "CCamera.h"
#include "CCollisionMgr.h"

#include "CKeyman.h"
#include "CLevelMgr.h"


void CPlayLevel::init()
{
	// �÷��̾� ����
	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(Vec2(500.f, 200.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	AddObject(PLAYER, pPlayer);

	// ���� ����
	//CMonster* pMonster = nullptr;

	//pMonster = new CMonster;
	//pMonster->SetPos(Vec2(900.f, 500.f));
	//pMonster->SetScale(Vec2(100.f, 100.f));
	//m_pCurLevel->AddObject(MONSTER, pMonster);

	// �÷��� ��ġ
	CPlatform* pPlatform = new CPlatform;
	pPlatform->SetPos(Vec2(800.f, 700.f));
	AddObject(PLATFORM, pPlatform);


	// ī�޶� ����
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	// �浹 ����
	CCollisionMgr::GetInst()->CheckCollision(MONSTER, PLAYER);
	CCollisionMgr::GetInst()->CheckCollision(PLAYER_PJ, MONSTER);
	CCollisionMgr::GetInst()->CheckCollision(PLAYER, PLATFORM);
}

void CPlayLevel::enter()
{
	init();
}

void CPlayLevel::exit()
{
	DeleteAllObjects();
}

void CPlayLevel::tick()
{
	CLevel::tick();

	// Enter Ű�� ������ StartLevel �� ��ȯ
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::EDITOR_LEVEL);
	}
}