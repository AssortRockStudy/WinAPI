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

	//			�ڵ� / ������â �켱���� / ������â ������ /		 ������â ũ��		/ ������ ũ�⺯�� X
	SetWindowPos(m_hWnd, nullptr,		300, 100, m_ptResolution.x, m_ptResolution.y, 0);
	//				SW_SHOWNORMAL�� ���� �ǹ�
	ShowWindow(m_hWnd, true);
}

void MyEngine::tick()
{
}
