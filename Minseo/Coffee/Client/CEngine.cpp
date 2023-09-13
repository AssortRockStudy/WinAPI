#include "pch.h"
#include "CEngine.h"

#include "CPlayer.h"
#include "CLevel.h"

// Manager
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CPathMgr.h"

CEngine::CEngine()
	: m_hWnd(nullptr)
	, m_ptResolution{}
	, m_Level(nullptr)
	, m_DC(nullptr)
	, m_SubBitMap(nullptr)
{
}
CEngine::~CEngine()
{
	ReleaseDC(m_hWnd, m_DC);//윈도우랑 연결 된 경우에만 릴리즈DC

	// 직접 만든 애들은 Delete 써서 지워주어야 한다.
	DeleteObject(m_SubBitMap);
	DeleteDC(m_SubDC);
	
	if (nullptr != m_Level)
		delete m_Level;
}


void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	SetWindowPos(m_hWnd, nullptr, 10, 10, m_ptResolution.x, m_ptResolution.y, 0);
	ShowWindow(m_hWnd, true);

	m_DC = GetDC(m_hWnd);



	// 추가 비트맵 버퍼(현재 윈도우와 같은 크기, 윈도우 쪽 함수를 통한 동적 할당으로 비트맵 버퍼를 만들 것)
	m_SubBitMap = CreateCompatibleBitmap(m_DC, m_ptResolution.x, m_ptResolution.y);// 인자로 매칭시킬 dc, 크기,
	m_SubDC = CreateCompatibleDC(m_DC);

	// 서브dc가 서브bitmap을 목적지로 저장하고, 원래 목적지로 지정하고 있던 비트맵이 반환 값으로 나오는데,
	// 반환된 이 쪼가리 비트맵을 바로 DeleteObject에 넘긴다. 
	// 펜 바꿔치기 할 때 했던거 생각하면 이해하기 쉽다
	DeleteObject((HBITMAP)SelectObject(m_SubDC, m_SubBitMap));

	// Manager 초기화
	CPathMgr::init();
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CLevelMgr::GetInst()->init();


}

// tick 1ȸ => 1 ������
// fps - frame per second
void CEngine::tick()
{
	// Manager
	CTimeMgr::GetInst()->tick();
	CKeyMgr::GetInst()->tick();
	CLevelMgr::GetInst()->tick();
	CLevelMgr::GetInst()->render(m_SubDC); // 서브 DC에 그렸다가 비트맵 복사


}

