#include "pch.h"
#include "MyStartLevel.h"

#include "MyKeyMgr.h"
#include "MyLevelMgr.h"

void MyStartLevel::init()
{
}

void MyStartLevel::enter()
{

}

void MyStartLevel::exit()
{
	DeleteAllObjects();
}

void MyStartLevel::tick()
{
	MyLevel::tick();

	// Enter키를 누르면 PLAY_LEVEL로 바뀜
	if (KEY_TAP(ENTER))
	{
		ChangeLevel(LEVEL_TYPE::EDITOR_LEVEL);
	}
}
