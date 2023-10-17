#include "pch.h"
#include "StartLevel.h"
#include "KeyMgr.h"
#include "LevelMgr.h"

void StartLevel::init()
{
}

void StartLevel::enter()
{
}

void StartLevel::exit()
{
	deleteAllObjects();
}

void StartLevel::tick()
{
	CLevel::tick();

	if (KeyMgr::GetInst()->getKeyState(ENTER) == TAP)
		changeLevel(LEVEL_TYPE::PLAY_LEVEL);
}