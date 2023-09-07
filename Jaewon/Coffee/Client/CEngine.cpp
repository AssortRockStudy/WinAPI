#include "pch.h"
#include "CEngine.h"
#include "Player.h"
#include "CLevel.h"

CEngine::CEngine():mHwnd(nullptr), mPtResolution(), mDc(nullptr)
{
}

CEngine::~CEngine()
{
	// DC 해제 및 레벨 해제
	ReleaseDC(mHwnd, mDc);
	if (nullptr != mLevel)
		delete mLevel;
}

void CEngine::init(HWND _hwnd, POINT _ptResolution)
{
	mHwnd = _hwnd;
	mPtResolution = _ptResolution;

	// 해상도 설정
	SetWindowPos(mHwnd, nullptr, 10, 10, mPtResolution.x, mPtResolution.y, 0);
	ShowWindow(mHwnd, true);

	// DC 생성
	// 그림 그리는 도구로 생각
	mDc = GetDC(mHwnd);

	mLevel = new CLevel;

	Player* mPlayer = new Player;
	mPlayer->setPos(POINT{ 500, 500 });
	mPlayer->setScale(POINT{ 50, 50 });
	mLevel->AddObj(mPlayer);
}

void CEngine::tick()
{
	mLevel->tick();
	mLevel->render(mDc);
}
