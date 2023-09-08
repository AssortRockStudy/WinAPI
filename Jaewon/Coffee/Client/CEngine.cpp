#include "pch.h"
#include "CEngine.h"
#include "Player.h"
#include "CLevel.h"
#include "CTimeMgr.h"

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

	// 매니져
	CTimeMgr::GetInst()->init();

	mLevel = new CLevel;

	Player* mPlayer = new Player;
	mPlayer->setPos(Vec2{ 500.f, 500.f });
	mPlayer->setScale(Vec2{ 50.f, 50.f });
	mPlayer->setColor(black);
	mLevel->AddObj(mPlayer);


	Player* redPlayer = new Player;
	redPlayer->setPos(Vec2{ 800.f, 500.f });
	redPlayer->setScale(Vec2{ 50.f, 50.f });
	redPlayer->setColor(red);
	mLevel->AddObj(redPlayer);
}

void CEngine::tick()
{
	CTimeMgr::GetInst()->tick();
	mLevel->tick();
	mLevel->render(mDc);
}
