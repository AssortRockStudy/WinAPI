#include "pch.h"

#include "CEngine.h"


static CEngine* pEngine=nullptr;


CEngine::CEngine()
	:m_hWnd(nullptr)
	, m_ptResolution{}
{

}



CEngine::~CEngine()
{
	//Re

	if (nullptr != m_Level)
	{
		delete m_Level;
	}
}


void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	//해상도변경 
	SetWindowPos(m_hWnd, nullptr, 10, 10, _ptResolution.x, _ptResolution.y, 0);
	ShowWindow(m_hWnd, true);


	m_CLevel = new CLevel;

}

//tick() 1회 ==>1프레임
//FPS(Frame Per Second
void CEngine::tick()
{
	static int Call = 0;
	++Call;
	int CurCount = 0;
	static int PrevCount = GetTickCount();


	CurCount = GetTickCount();


	if (1000 < (CurCount - PrevCount))
	{
		Call = 0;
		PrevCount = CurCount;
	}
}