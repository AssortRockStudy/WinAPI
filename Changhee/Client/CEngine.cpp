#include "pch.h"
#include "CEngine.h"

#include "CLevel.h"
#include "CPlayer.h"


CEngine::CEngine()
	: m_hWnd(nullptr)
	, m_ptResloution{}
	, m_dc(nullptr)
	, m_Level(nullptr)

{
}

CEngine::~CEngine()
{
	// DC 해제
	ReleaseDC(m_hWnd, m_dc);

	if (nullptr != m_Level)
		delete m_Level;
	

}

void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	// 멤버 변수 초기화
	m_hWnd = _hWnd;
	m_ptResloution = _ptResolution;
	m_dc = GetDC(m_hWnd);


	// 해상도 변경
	SetWindowPos(m_hWnd, nullptr, 50, 50, m_ptResloution.x, m_ptResloution.y, 0);
	ShowWindow(m_hWnd, true);

	m_Level = new CLevel;

	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(POINT{ 500,500 });
	pPlayer->SetScale(POINT{ 50,50 });

	m_Level->AddObject(pPlayer);

}

void CEngine::tick()
{

	m_Level->tick();

	m_Level->render(m_dc);

}
