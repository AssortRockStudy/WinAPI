#include "pch.h"
#include "CTimeMgr.h"

CTimeMgr::CTimeMgr() :mFrequency{}, mPrevCnt{}, mCurCnt{} {}
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
}
