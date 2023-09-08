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
	// DC ���� �� ���� ����
	ReleaseDC(mHwnd, mDc);
	if (nullptr != mLevel)
		delete mLevel;
}

void CEngine::init(HWND _hwnd, POINT _ptResolution)
{
	mHwnd = _hwnd;
	mPtResolution = _ptResolution;

	// �ػ� ����
	SetWindowPos(mHwnd, nullptr, 10, 10, mPtResolution.x, mPtResolution.y, 0);
	ShowWindow(mHwnd, true);

	// DC ����
	// �׸� �׸��� ������ ����
	mDc = GetDC(mHwnd);

	// �Ŵ���
	CTimeMgr::GetInst()->init();

	mLevel = new CLevel;

	Player* mPlayer = new Player;
	mPlayer->setPos(Vec2{ 500.f, 500.f });
	mPlayer->setScale(Vec2{ 50.f, 50.f });
	mLevel->AddObj(mPlayer);
}

void CEngine::tick()
{
	CTimeMgr::GetInst()->tick();
	mLevel->tick();
	mLevel->render(mDc);
}
