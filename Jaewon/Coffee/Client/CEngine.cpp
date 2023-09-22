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
#include "CollisionMgr.h"

CEngine::CEngine():mHwnd(nullptr), mPtResolution(), mDc(nullptr), subBitMap(nullptr), subDc(nullptr), debugRender(true), arrPen{}
{
}

CEngine::~CEngine()
{
	// DC 해제 및 레벨 해제
	ReleaseDC(mHwnd, mDc);

	DeleteObject(subBitMap);
	DeleteDC(subDc);
	for (UINT i = 0; i < PEN_END; ++i)
		DeleteObject(arrPen[i]);
}

void CEngine::createGDI()
{
	arrPen[RED_PEN] = CreatePen(PS_SOLID, 1, RGB(255, 20, 20));
	arrPen[GREEN_PEN] = CreatePen(PS_SOLID, 1, RGB(20, 255, 20));
	arrPen[BLUE_PEN] = CreatePen(PS_SOLID, 1, RGB(20, 20, 255));
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
	
	createGDI();
}

void CEngine::tick()
{
	CTimeMgr::GetInst()->tick();
	KeyMgr::GetInst()->tick();
	Camera::GetInst()->tick();

	if (KeyMgr::GetInst()->getKeyState(NUM8) == TAP)
		debugRender ? debugRender = false : debugRender = true;

	LevelMgr::GetInst()->tick();
	CollisionMgr::GetInst()->tick();
	LevelMgr::GetInst()->render(subDc);

	TaskMgr::GetInst()->tick();
}
