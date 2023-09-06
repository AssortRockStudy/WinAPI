#include "pch.h"
#include "MyEngine.h"

#include "MyTimeMgr.h"
#include "MyLevel.h"

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

	m_Level = new MyLevel;
}

void MyEngine::tick()
{
	MyTimeMgr::GetInst()->tick();

	m_Level->tick();
	m_Level->render(m_DC);
}
