#include "pch.h"
#include "LevelMgr.h"
#include "CLevel.h"
#include "Player.h"
#include "CEngine.h"
#include "Monster.h"
#include "Camera.h"
#include "CollisionMgr.h"
#include "LogMgr.h"
#include "Platform.h"
#include "PlayLevel.h"
#include "StartLevel.h"
#include "EditorLevel.h"

LevelMgr::LevelMgr():curLevel(nullptr){}
LevelMgr::~LevelMgr(){
	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i){
		if (nullptr != arrLevels[i])
			delete arrLevels[i];
	}
}

void LevelMgr::init()
{
	arrLevels[(UINT)LEVEL_TYPE::START_LEVEL] = new StartLevel;
	arrLevels[(UINT)LEVEL_TYPE::PLAY_LEVEL] = new PlayLevel;
	arrLevels[(UINT)LEVEL_TYPE::EDITOR_LEVEL] = new EditorLevel;

	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i){
		arrLevels[i]->init();
	}

	curLevel = arrLevels[(UINT)LEVEL_TYPE::PLAY_LEVEL];

	curLevel->begin();

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

	LogMgr::GetInst()->tick(_dc);

	// 메인DC로 비트맵 복사
	BitBlt(CEngine::GetInst()->getMainDc(), 0, 0, ptResolution.x, ptResolution.y, _dc, 0, 0, SRCCOPY);
}
