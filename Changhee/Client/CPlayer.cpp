#include "pch.h"
#include "CPlayer.h"

#include "CTimeMgr.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}



void CPlayer::tick()
{
	Vec2 vPos = GetPos();

	float DT = CTimeMgr::GetInst()->GetDeltaTime();


	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
	{
		
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
	{

	}

	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{

	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
	{

	}
}


