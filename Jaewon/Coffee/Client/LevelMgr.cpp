#include "pch.h"
#include "LevelMgr.h"
#include "CLevel.h"
#include "Player.h"
#include "CEngine.h"

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
	curLevel->AddObj(mPlayer);

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
