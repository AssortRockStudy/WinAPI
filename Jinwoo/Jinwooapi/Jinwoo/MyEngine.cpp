#include "pch.h"
#include "MyEngine.h"

#include "MyTimeMgr.h"
#include "MyKeyMgr.h"

#include "MyLevel.h"
#include "MyPlayer.h"

MyEngine::MyEngine() : m_hWnd(nullptr), m_ptResolution{}, m_DC(nullptr)
{

}

MyEngine::~MyEngine()
{
	// DC 해제
	ReleaseDC(m_hWnd, m_DC);

	if (nullptr != m_Level)
	{
		delete m_Level;
	}
}

void MyEngine::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	//			핸들 / 윈도우창 우선순위 / 윈도우창 시작점 /		 윈도우창 크기		/ 윈도우 크기변경 X
	SetWindowPos(m_hWnd, nullptr,		300, 100, m_ptResolution.x, m_ptResolution.y, 0);
	//				SW_SHOWNORMAL과 같은 의미
	ShowWindow(m_hWnd, true);

	m_DC = GetDC(m_hWnd);

	MyTimeMgr::GetInst()->init();
	MyKeyMgr::GetInst()->init();

	m_Level = new MyLevel;

	MyPlayer* pPlayer = new MyPlayer;

	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	m_Level->AddObject(pPlayer);
}

void MyEngine::tick()
{
	MyTimeMgr::GetInst()->tick();

	m_Level->tick();
	m_Level->render(m_DC);
}
