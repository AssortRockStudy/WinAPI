#include "pch.h"
#include "CPlayLevel.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "CPlatform.h"

#include "CEngine.h"
#include "CCamera.h"
#include "CCollisionMgr.h"

void CPlayLevel::init()
{
	// 플레이어 생성
	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(Vec2(500.f, 200.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	AddObject(PLAYER, pPlayer);

	// 몬스터 생성
	//CMonster* pMonster = nullptr;

	//pMonster = new CMonster;
	//pMonster->SetPos(Vec2(900.f, 500.f));
	//pMonster->SetScale(Vec2(100.f, 100.f));
	//m_pCurLevel->AddObject(MONSTER, pMonster);

	// 플랫폼 설치
	CPlatform* pPlatform = new CPlatform;
	pPlatform->SetPos(Vec2(800.f, 700.f));
	AddObject(PLATFORM, pPlatform);


	// 카메라 설정
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	// 충돌 설정
	CCollisionMgr::GetInst()->CheckCollision(MONSTER, PLAYER);
	CCollisionMgr::GetInst()->CheckCollision(PLAYER_PJ, MONSTER);
	CCollisionMgr::GetInst()->CheckCollision(PLAYER, PLATFORM);
}