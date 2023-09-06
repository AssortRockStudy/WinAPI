#include "pch.h"
#include "MyEngine.h"

MyEngine::MyEngine() : m_hWnd(nullptr), m_ptResolution{}, m_DC(nullptr)
{

}

MyEngine::~MyEngine()
{
	ReleaseDC(m_hWnd, m_DC);


}

void MyEngine::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	//			핸들 / 윈도우창 우선순위 / 윈도우창 시작점 /		 윈도우창 크기		/ 윈도우 크기변경 X
	SetWindowPos(m_hWnd, nullptr,		300, 100, m_ptResolution.x, m_ptResolution.y, 0);
	//				SW_SHOWNORMAL과 같은 의미
	ShowWindow(m_hWnd, true);
}

void MyEngine::tick()
{
}
