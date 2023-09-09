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
	// tick���� delta time ���
	QueryPerformanceCounter(&mCurCnt);
	mDeltaT = float(mCurCnt.QuadPart - mPrevCnt.QuadPart) / float(mFrequency.QuadPart);
	mPrevCnt = mCurCnt;
}
