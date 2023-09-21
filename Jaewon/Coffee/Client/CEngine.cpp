#include "pch.h"
#include "CEngine.h"
#include "Player.h"
#include "CLevel.h"
#include "CTimeMgr.h"
#include "KeyMgr.h"
#include "LevelMgr.h"
#include "CPathMgr.h"
#include "Camera.h"
#include "TaskMgr.h"

CEngine::CEngine():mHwnd(nullptr), mPtResolution(), mDc(nullptr), subBitMap(nullptr), subDc(nullptr)
{
}

CEngine::~CEngine()
{
	// DC 해제 및 레벨 해제
	ReleaseDC(mHwnd, mDc);

	DeleteObject(subBitMap);
	DeleteDC(subDc);
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

	// 더블 버퍼 구현
	// 추가 비트맵(윈도우), DC 생성
	// 그림 완성 후에 바꿔줄 윈도우
	subBitMap = CreateCompatibleBitmap(mDc, mPtResolution.x, mPtResolution.y);
	subDc = CreateCompatibleDC(mDc);

	DeleteObject((HBITMAP)SelectObject(subDc, subBitMap));

	// 매니져
	CPathMgr::init();
	CTimeMgr::GetInst()->init();
	KeyMgr::GetInst()->init();
	LevelMgr::GetInst()->init();
	
	
}

void CEngine::tick()
{
	CTimeMgr::GetInst()->tick();
	KeyMgr::GetInst()->tick();
	Camera::GetInst()->tick();
	LevelMgr::GetInst()->tick();
	LevelMgr::GetInst()->render(subDc);

	TaskMgr::GetInst()->tick();
}
