#include "pch.h"
#include "Engine.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "DrawMgr.h"
#include "LevelMgr.h"
#include "PathMgr.h"
#include "TaskMgr.h"
#include "Camera.h"


#include "Level.h"

Engine::Engine()
	: m_hWnd(nullptr)
	, m_ptResolution{}
	, m_Level(nullptr)
	, m_DC(nullptr)
	, m_SubBitMap(nullptr)
{
}

Engine::~Engine()
{
	ReleaseDC(m_hWnd, m_DC);
	DeleteObject(m_SubBitMap);
	DeleteDC(m_SubDC);

	if (nullptr != m_Level)
		delete m_Level;
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
	DrawMgr::GetInst()->init();
	KeyMgr::GetInst()->init();
	PathMgr::init();
	LevelMgr::GetInst()->init();
	
}

void Engine::tick()
{
	TimeMgr::GetInst()->tick();
	KeyMgr::GetInst()->tick();
	LevelMgr::GetInst()->tick();
	DrawMgr::GetInst()->tick();
	Camera::GetInst()->tick();

	LevelMgr::GetInst()->render(m_SubDC);

	TaskMgr::GetInst()->tick();

}
