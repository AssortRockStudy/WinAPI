#include "pch.h"
#include "Engine.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
//#include "DrawMgr.h"
#include "LevelMgr.h"
#include "PathMgr.h"
#include "TaskMgr.h"
#include "LogMgr.h"
#include "GCMgr.h"
#include "Camera.h"
#include "CollisionMgr.h"


Engine::Engine()
	: m_hWnd(nullptr)
	, m_ptResolution{}
	, m_DC(nullptr)
	, m_SubBitMap(nullptr)
	, m_bDebugRender(true)
	, m_arrPen{}
{
}

Engine::~Engine()
{
	ReleaseDC(m_hWnd, m_DC);
	DeleteObject(m_SubBitMap);
	DeleteDC(m_SubDC);

	for (UINT i = 0; i < PEN_END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}
}

void Engine::CreateDefaultGDI()
{
	m_arrPen[RED_PEN] = CreatePen(PS_SOLID, 1, RGB(255, 20, 20));
	m_arrPen[GREEN_PEN] = CreatePen(PS_SOLID, 1, RGB(20, 255, 20));
	m_arrPen[BLUE_PEN] = CreatePen(PS_SOLID, 1, RGB(20, 20, 255));
}

void Engine::init(HWND _hWnd, POINT _ptResolution)
{

	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;


	SetWindowPos(m_hWnd, nullptr, 10, 10, m_ptResolution.x, m_ptResolution.y, 0);
	ShowWindow(m_hWnd, true);

	m_DC = GetDC(m_hWnd);

	m_SubBitMap = CreateCompatibleBitmap(m_DC, m_ptResolution.x, m_ptResolution.y);
	m_SubDC = CreateCompatibleDC(m_DC);

	DeleteObject((HBITMAP)SelectObject(m_SubDC, m_SubBitMap));


	// Manager ÃÊ±âÈ­
	TimeMgr::GetInst()->init();
	//DrawMgr::GetInst()->init();
	KeyMgr::GetInst()->init();
	PathMgr::init();
	LevelMgr::GetInst()->init();

	CreateDefaultGDI();
	
}

void Engine::tick()
{
	TimeMgr::GetInst()->tick();
	KeyMgr::GetInst()->tick();
	LevelMgr::GetInst()->tick();
	//DrawMgr::GetInst()->tick();
	Camera::GetInst()->tick();

	if (KEY_TAP(KEY::NUM8))
	{
		m_bDebugRender ? m_bDebugRender = false : m_bDebugRender = true;
	}

	CollisionMgr::GetInst()->tick();
	LevelMgr::GetInst()->render(m_SubDC);
	

	TaskMgr::GetInst()->tick();

	GCMgr::GetInst()->tick();

}