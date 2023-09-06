#include "pch.h"
#include "MyEngine.h"

#include "MyTimeMgr.h"
#include "MyLevel.h"

MyEngine::MyEngine() : m_hWnd(nullptr), m_ptResolution{}, m_DC(nullptr)
{

}

MyEngine::~MyEngine()
{
	// DC ����
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

	//			�ڵ� / ������â �켱���� / ������â ������ /		 ������â ũ��		/ ������ ũ�⺯�� X
	SetWindowPos(m_hWnd, nullptr,		300, 100, m_ptResolution.x, m_ptResolution.y, 0);
	//				SW_SHOWNORMAL�� ���� �ǹ�
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
