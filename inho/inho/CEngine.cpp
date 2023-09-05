#include "pch.h"
#include "CEngine.h"

// Manager
#include "CTimeMgr.h"



#include "CLevel.h"
#include "CPlayer.h"

CEngine::CEngine()
	: m_hWnd(nullptr)
	, m_ptResolution{}
	, m_Level(nullptr)
	, m_dc(nullptr)
{
}

CEngine::~CEngine()
{
	ReleaseDC(m_hWnd, m_dc);

	if (nullptr != m_Level)
		delete m_Level;
}

void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;


	SetWindowPos(m_hWnd, nullptr, 10, 10, m_ptResolution.x, m_ptResolution.y, 0);
	ShowWindow(m_hWnd, true);

	// DC : Device Context
	// pen : Black 
	// brush : White
	// Bitmap(그림 그릴 곳) : 핸들에 해당하는 윈도우 비트맵
	m_dc = GetDC(m_hWnd);


	// Manager 초기화
	CTimeMgr::GetInst()->init();







	// Level 
	m_Level = new CLevel;

	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	m_Level->AddObject(pPlayer);
}

void CEngine::tick()
{
	// TimeMgr
	CTimeMgr::GetInst()->tick();

	m_Level->tick();
	m_Level->render(m_dc);
}