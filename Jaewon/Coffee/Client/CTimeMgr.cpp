#include "pch.h"
#include "CTimeMgr.h"
#include "CEngine.h"

CTimeMgr::CTimeMgr() :mFrequency{}, mPrevCnt{}, mCurCnt{}, mFTime(0.f), mCall(0) {}
CTimeMgr::~CTimeMgr(){}

void CTimeMgr::init()
{
	QueryPerformanceFrequency(&mFrequency);
	QueryPerformanceCounter(&mPrevCnt);
}

void CTimeMgr::tick()
{
	// tick마다 delta time 계산
	QueryPerformanceCounter(&mCurCnt);
	mDeltaT = float(mCurCnt.QuadPart - mPrevCnt.QuadPart) / float(mFrequency.QuadPart);
	mPrevCnt = mCurCnt;

	mFTime += mDeltaT;
	// 1초마다 frame 측정
	if (1.f <= mFTime) {
		wchar_t szText[50] = {};
		swprintf(szText, 50, L"DeltaTime : %f, FPS : %d", mDeltaT, mCall);
		SetWindowText(CEngine::GetInst()->getMainWin(), szText);
		mCall = 0;
		mFTime = 0.f;

	}
	++mCall;
}
