#include "pch.h"
#include "CEngine.h"

#include "CTimeMgr.h"


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


	// Pen,Brush 삭제
	for (int i = 0; i < (UINT)PEN_TYPE::END; i++)
	{
		DeleteObject(m_arrPen[i]);
	}

	for (int i = 0; i < (UINT)BRUSH_TYPE::END; i++)
	{
		DeleteObject(m_arrBrush[i]);
	}


	// Level 해제
	if (nullptr != m_Level)
		delete m_Level;
}

void CEngine::CreatePenBrush()
{
	// red, green, blue blush 생성
	m_arrBrush[(UINT)BRUSH_TYPE::RED] = CreateSolidBrush(RGB(255, 0, 0));
	m_arrBrush[(UINT)BRUSH_TYPE::GREEN] = CreateSolidBrush(RGB(0, 255, 0));
	m_arrBrush[(UINT)BRUSH_TYPE::BLUE] = CreateSolidBrush(RGB(0, 0, 255));

	// red, green, blue pen 생성
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

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

	// Manager 초기화
	CTimeMgr::GetInst()->init();

	// pen, brush 초기화
	CreatePenBrush();


	m_Level = new CLevel;

	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(Vec2( 500.f,500.f ));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	m_Level->AddObject(pPlayer);

}

void CEngine::tick()
{
	// Manager Tick
	CTimeMgr::GetInst()->tick();


	m_Level->tick();

	m_Level->render(m_dc);

}
