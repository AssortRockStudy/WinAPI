#include "pch.h"
#include "CEngine.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"

#include "CLevel.h"
#include "CPlayer.h"
#include "CMonster.h"


CEngine::CEngine()
	: m_hWnd(nullptr)
	, m_ptResloution{}
	, m_dc(nullptr)
	, m_Level(nullptr)

{
	// pen, brush ����
	CreatePenBrush();
}

CEngine::~CEngine()
{
	// DC ����
	ReleaseDC(m_hWnd, m_dc);


	// Pen,Brush ����
	for (int i = 0; i < (UINT)PEN_TYPE::END; i++)
	{
		DeleteObject(m_arrPen[i]);
	}

	for (int i = 0; i < (UINT)BRUSH_TYPE::END; i++)
	{
		DeleteObject(m_arrBrush[i]);
	}


	// Level ����
	if (nullptr != m_Level)
		delete m_Level;
}



void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	// ��� ���� �ʱ�ȭ
	m_hWnd = _hWnd;
	m_ptResloution = _ptResolution;
	m_dc = GetDC(m_hWnd);

	// �ػ� ����
	SetWindowPos(m_hWnd, nullptr, 50, 50, m_ptResloution.x, m_ptResloution.y, 0);
	ShowWindow(m_hWnd, true);

	// Manager �ʱ�ȭ
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();

	// Level ����
	m_Level = new CLevel;

	// Plyaer ����
	CPlayer* pPlayer = new CPlayer;
	pPlayer->SetPos(Vec2( 500.f,500.f ));
	pPlayer->SetScale(Vec2(50.f, 50.f));
	m_Level->AddObject(pPlayer);

	CMonster* pMonster = new CMonster;
	pMonster->SetPos(Vec2(500.f, 600.f));
	pMonster->SetScale(Vec2(50.f, 50.f));
	m_Level->AddObject(pMonster);
}

void CEngine::tick()
{
	// Manager Tick
	CTimeMgr::GetInst()->tick();
	CKeyMgr::GetInst()->tick();

	m_Level->tick();

	m_Level->render(m_dc);

}

void CEngine::CreatePenBrush()
{
	// red, green, blue blush ����
	m_arrBrush[(UINT)BRUSH_TYPE::RED] = CreateSolidBrush(RGB(255, 0, 0));
	m_arrBrush[(UINT)BRUSH_TYPE::GREEN] = CreateSolidBrush(RGB(0, 255, 0));
	m_arrBrush[(UINT)BRUSH_TYPE::BLUE] = CreateSolidBrush(RGB(0, 0, 255));
	m_arrBrush[(UINT)BRUSH_TYPE::BLACK] = CreateSolidBrush(RGB(0, 0, 0));


	// red, green, blue pen ����
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

}
