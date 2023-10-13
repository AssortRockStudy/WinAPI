#include "pch.h"
#include "PlayLevel.h"

#include "Player.h"
#include "Monster.h"
#include "Platform.h"

#include "Engine.h"
#include "Camera.h"
#include "CollisionMgr.h"

#include "KeyMgr.h"
#include "LevelMgr.h"

void PlayLevel::init()
{

	Player* pPlayer = new Player;

	pPlayer->SetPos(Vec2(500.f, 200.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	AddObject(PLAYER, pPlayer);

	//Monster* pMonster = nullptr;
	//pMonster = new Monster;
	//pMonster->SetPos(Vec2(900.f, 500.f));
	//pMonster->SetScale(Vec2(100.f, 100.f));
	//m_pCurLevel->AddObject(MONSTER, pMonster);

	Platform* pPlatform = new Platform;
	pPlatform->SetPos(Vec2(800.f, 700.f));
	AddObject(PLATFORM, pPlatform);

	Vec2 vLookAt = Engine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	Camera::GetInst()->SetLookAt(vLookAt);

	CollisionMgr::GetInst()->CheckCollision(MONSTER, PLAYER);
	CollisionMgr::GetInst()->CheckCollision(PLAYER_PJ, MONSTER);
	CollisionMgr::GetInst()->CheckCollision(PLAYER, PLATFORM);

}

void PlayLevel::enter()
{
	init();
}

void PlayLevel::exit()
{
	DeleteAllObjects();
}

void PlayLevel::tick()
{
	Level::tick();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::EDITOR_LEVEL);
	}
}
