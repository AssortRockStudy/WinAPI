#include "pch.h"
#include "Engine.h"

#include "KeyMgr.h"
#include "TimeMgr.h"
#include "AssetMgr.h"
//#include "DrawMgr.h"
#include "LevelMgr.h"
#include "PathMgr.h"
#include "TaskMgr.h"
#include "LogMgr.h"
#include "GCMgr.h"
#include "UIMgr.h"
#include "SoundMgr.h"
#include "Camera.h"
#include "CollisionMgr.h"

#include "Texture.h"

Engine::Engine()
	: m_hWnd(nullptr)
	, m_ptResolution{}
	, m_DC(nullptr)
	, m_bDebugRender(true)
	, m_arrPen{}
{
}

Engine::~Engine()
{
	ReleaseDC(m_hWnd, m_DC);

	for (UINT i = 0; i < PEN_END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}
}

void Engine::ChangeWindowSize(POINT _ptResolution, bool _bMenu)
{
	m_ptResolution = _ptResolution;

	RECT rt = { 0,0, _ptResolution.x, _ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, _bMenu);
	SetWindowPos(m_hWnd, nullptr, 10, 10, rt.right - rt.left, rt.bottom - rt.top ,0);
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
	ChangeWindowSize(_ptResolution, false);
	ShowWindow(m_hWnd, true);

	m_DC = GetDC(m_hWnd);

	m_SubTex = AssetMgr::GetInst()->CreateTexture(L"SubTex", m_ptResolution.x, m_ptResolution.y);

	// Manager ÃÊ±âÈ­
	TimeMgr::GetInst()->init();
	//DrawMgr::GetInst()->init();
	KeyMgr::GetInst()->init();
	PathMgr::init();
	SoundMgr::GetInst()->init();
	LevelMgr::GetInst()->init();

	CreateDefaultGDI();
	
}

void Engine::tick()
{
	TimeMgr::GetInst()->tick();
	KeyMgr::GetInst()->tick();
	//DrawMgr::GetInst()->tick();
	Camera::GetInst()->tick();

	if (KEY_TAP(KEY::NUM8))
	{
		m_bDebugRender ? m_bDebugRender = false : m_bDebugRender = true;
	}

	LevelMgr::GetInst()->tick();
	CollisionMgr::GetInst()->tick();
	UIMgr::GetInst()->tick();

	LevelMgr::GetInst()->render(m_SubTex->GetDC());
	Camera::GetInst()->render(m_SubTex->GetDC());

	BitBlt(Engine::GetInst()->GetMainDC()
		, 0, 0
		, m_ptResolution.x, m_ptResolution.y
		, m_SubTex->GetDC()
		, 0, 0, SRCCOPY);
	
	TaskMgr::GetInst()->tick();

	GCMgr::GetInst()->tick();

}

