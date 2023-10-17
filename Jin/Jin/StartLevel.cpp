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
	DeleteAllObjects();
}

void StartLevel::tick()
{
	Level::tick();

	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::PLAY_LEVEL);
	}
}
