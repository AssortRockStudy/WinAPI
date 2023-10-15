#include "pch.h"
#include "MyPlayLevel.h"

#include "MyEngine.h"

#include "MyCameraMgr.h"
#include "MyColliderMgr.h"
#include "MyKeyMgr.h"

#include "MyPlayer.h"
#include "MyMonster.h"
#include "MyPlatform.h"


void MyPlayLevel::init()
{
	MyPlayer* pPlayer = new MyPlayer;
	pPlayer->SetPos(Vec2(500.f, 200.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));
	AddObject(LAYER::PLAYER, pPlayer);

	//MyMonster* pMonster = new MyMonster;
	//pMonster->SetPos(Vec2(200.f, 200.f));
	//pMonster->SetScale(Vec2(80.f, 80.f));
	//AddObject(LAYER::MONSTER, pMonster);
	
	//MyMonster* pMonster2 = new MyMonster;
	//pMonster2->SetPos(Vec2(800.f, 200.f));
	//pMonster2->SetScale(Vec2(80.f, 80.f));

	//AddObject(LAYER::MONSTER, pMonster2);

	// 플랫폼 설치
	MyPlatform* pPlatform = new MyPlatform;
	pPlatform->SetPos(Vec2(800.f, 700.f));
	AddObject(LAYER::PLATFORM, pPlatform);

	Vec2 vLookAt = MyEngine::GetInst()->GetMainResolution();
	vLookAt /= 2.f;
	MyCameraMgr::GetInst()->SetLookAt(vLookAt);

	//MyColliderMgr::GetInst()->CheckCollision(LAYER::MONSTER, LAYER::PLAYER);
	//MyColliderMgr::GetInst()->CheckCollision(LAYER::MONSTER, LAYER::PLAYERBULLET);
	MyColliderMgr::GetInst()->CheckCollision(LAYER::PLAYER, LAYER::PLATFORM);
}

void MyPlayLevel::enter()
{
	init();
}

void MyPlayLevel::exit()
{
	DeleteAllObjects();
}

void MyPlayLevel::tick()
{
	MyLevel::tick();

	// Enter키를 누르면 START_LEVEL로 바뀜
	if (KEY_TAP(ENTER))
	{
		ChangeLevel(LEVEL_TYPE::EDITOR_LEVEL);
	}
}
