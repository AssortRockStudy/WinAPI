#include "pch.h"
#include "LevelMgr.h"
#include "CLevel.h"
#include "Player.h"
#include "CEngine.h"
#include "Monster.h"

LevelMgr::LevelMgr(){}
LevelMgr::~LevelMgr(){
	if (nullptr != curLevel)
		delete curLevel;
}

void LevelMgr::init()
{
	curLevel = new CLevel;

	Player* mPlayer = new Player;
	mPlayer->setPos(Vec2{ 500.f, 500.f });
	mPlayer->setScale(Vec2{ 50.f, 50.f });
	mPlayer->setColor(black);
	mPlayer->setReverseMove(true);
	mPlayer->setType(PLAYER);
	curLevel->AddObj(mPlayer);

	Monster* mMonster = new Monster;
	mMonster->setPos(Vec2{ 100.f, 100.f });
	mMonster->setScale(Vec2{ 80.f, 80.f });
	mMonster->setType(MONSTER);
	curLevel->AddObj(mMonster);


	Monster* m2Monster = new Monster;
	m2Monster->setPos(Vec2{ 700.f, 600.f });
	m2Monster->setScale(Vec2{ 80.f, 80.f });
	m2Monster->setType(MONSTER);
	curLevel->AddObj(m2Monster);

}

void LevelMgr::tick()
{
	curLevel->tick();
	
}

void LevelMgr::render(HDC _dc)
{
	// 이중 버퍼 구현
	POINT ptResolution = CEngine::GetInst()->getMainResol();
	Rectangle(_dc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	curLevel->render(_dc);

	// 메인DC로 비트맵 복사
	BitBlt(CEngine::GetInst()->getMainDc(), 0, 0, ptResolution.x, ptResolution.y, _dc, 0, 0, SRCCOPY);
}
