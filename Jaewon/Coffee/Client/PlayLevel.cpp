#include "pch.h"
#include "PlayLevel.h"
#include "Player.h"
#include "Monster.h"
#include "Platform.h"
#include "CEngine.h"
#include "Camera.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "LevelMgr.h"

void PlayLevel::init()
{
	Player* mPlayer = new Player;
	mPlayer->setPos(Vec2{ 500.f, 500.f });
	mPlayer->setScale(Vec2{ 50.f, 50.f });
	mPlayer->setColor(black);
	mPlayer->setReverseMove(true);
	addObject(PLAYER, mPlayer);

	/*
	Monster* mMonster = new Monster;
	mMonster->setPos(Vec2{ 100.f, 100.f });
	mMonster->setScale(Vec2{ 80.f, 80.f });
	curLevel->addObject(MONSTER, mMonster);


	Monster* m2Monster = new Monster;
	m2Monster->setPos(Vec2{ 700.f, 600.f });
	m2Monster->setScale(Vec2{ 80.f, 80.f });
	curLevel->addObject(MONSTER, m2Monster);
	*/

	Platform* pPlatform = new Platform;
	pPlatform->setPos(Vec2(800.f, 700.f));
	addObject(PLATFORM, pPlatform);

	Vec2 vLookAt = CEngine::GetInst()->getMainResol();
	vLookAt /= 2.f;
	Camera::GetInst()->SetLookAt(vLookAt);
	CollisionMgr::GetInst()->checkCollision(MONSTER, PLAYER);
	CollisionMgr::GetInst()->checkCollision(PLAYER_PJ, MONSTER);
	CollisionMgr::GetInst()->checkCollision(PLAYER, PLATFORM);
}

void PlayLevel::enter()
{
	init();
}

void PlayLevel::exit()
{
	deleteAllObjects();
}

void PlayLevel::tick()
{
	CLevel::tick();

	if (KeyMgr::GetInst()->getKeyState(ENTER) == TAP)
		changeLevel(LEVEL_TYPE::START_LEVEL);
}