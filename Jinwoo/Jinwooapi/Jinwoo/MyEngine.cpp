#include "pch.h"
#include "MyEngine.h"

#include "MyTimeMgr.h"
#include "MyKeyMgr.h"
#include "MyLevelMgr.h"
#include "MyPathMgr.h"
#include "MyTaskMgr.h"
#include "MyCameraMgr.h"

#include "MyLevel.h"

MyEngine::MyEngine() : m_hWnd(nullptr), m_ptResolution{}, m_DC(nullptr), m_SubBitMap(nullptr), m_SubDC(nullptr)
{

}

MyEngine::~MyEngine()
{
	// DC 해제
	ReleaseDC(m_hWnd, m_DC);

	DeleteObject(m_SubBitMap);
	DeleteDC(m_SubDC);

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
	SetWindowPos(m_hWnd, nullptr,		50, 50, m_ptResolution.x, m_ptResolution.y, 0);
	//				SW_SHOWNORMAL과 같은 의미
	ShowWindow(m_hWnd, true);

	m_DC = GetDC(m_hWnd);

	// 추가 비트맵 버퍼
	//									복사할 DC / 해상도
	m_SubBitMap = CreateCompatibleBitmap(m_DC, m_ptResolution.x, m_ptResolution.y);
	m_SubDC = CreateCompatibleDC(m_DC);

	// m_SubDC가 m_SubBitMap을 목적지로 지정하고
	// 원래 목적지로 지정하고 있던 BitMap이 반환값으로 나오는데 이것을 DeleteObject함수를 통해 삭제함
	DeleteObject((HBITMAP)SelectObject(m_SubDC, m_SubBitMap));

	MyTimeMgr::GetInst()->init();
	MyKeyMgr::GetInst()->init();

	// static 함수로 선언했기 때문에 바로 호출 가능
	// 이미지를 먼저 불러오고 Level에 그려야하기 때문에 먼저 실행한다
	MyPathMgr::init();
	MyLevelMgr::GetInst()->init();
}

void MyEngine::tick()
{
	MyTimeMgr::GetInst()->tick();
	MyKeyMgr::GetInst()->tick();
	MyCameraMgr::GetInst()->tick();

	MyLevelMgr::GetInst()->tick();
	MyLevelMgr::GetInst()->render(m_SubDC);

	MyTaskMgr::GetInst()->tick();
}
