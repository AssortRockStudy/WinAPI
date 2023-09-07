#include "pch.h"
#include "CEngine.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"



CEngine::CEngine()
	: m_hWnd(nullptr)
	, m_ptResloution{}
	, m_hDC(nullptr)
	, m_hSubBitMap(nullptr)
	, m_hSubDC(nullptr)
{
	// pen, brush 생성
	CreatePenBrush();
}

CEngine::~CEngine()
{
	// DC 해제
	ReleaseDC(m_hWnd, m_hDC);

	// SubDC, Bitmap 삭제
	DeleteObject(m_hSubBitMap);
	DeleteDC(m_hSubDC);
	
	// Pen,Brush 삭제
	for (int i = 0; i < (UINT)PEN_TYPE::END; i++)
	{
		DeleteObject(m_arrPen[i]);
	}

	for (int i = 0; i < (UINT)BRUSH_TYPE::END; i++)
	{
		DeleteObject(m_arrBrush[i]);
	}

}



void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	// 멤버 변수 초기화
	m_hWnd = _hWnd;
	m_ptResloution = _ptResolution;
	m_hDC = GetDC(m_hWnd);

	// 해상도 변경
	SetWindowPos(m_hWnd, nullptr, 50, 50, m_ptResloution.x, m_ptResloution.y, 0);
	ShowWindow(m_hWnd, true);

	// 추가 비트맵 버퍼
	m_hSubBitMap = CreateCompatibleBitmap(m_hDC, m_ptResloution.x, m_ptResloution.y);
	m_hSubDC = CreateCompatibleDC(m_hDC);
	
	// m_SubDC가 디폴트로 들고있던 비트맵을 삭제
	DeleteObject((HBITMAP)SelectObject(m_hSubDC, m_hSubBitMap));

	// Manager 초기화
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CLevelMgr::GetInst()->init();

}

void CEngine::tick()
{
	// ------------ Manager Update ------------
	CTimeMgr::GetInst()->tick();
	CKeyMgr::GetInst()->tick();


	// ------------ update ------------
	CLevelMgr::GetInst()->tick();


	// ------------ render ------------
	CLevelMgr::GetInst()->render(m_hSubDC);



	// SubDC -> mainDC 복사
	CopyBackBuffer();
	
}

void CEngine::CreatePenBrush()
{
	// red, green, blue blush 생성
	m_arrBrush[(UINT)BRUSH_TYPE::RED] = CreateSolidBrush(RGB(255, 0, 0));
	m_arrBrush[(UINT)BRUSH_TYPE::GREEN] = CreateSolidBrush(RGB(0, 255, 0));
	m_arrBrush[(UINT)BRUSH_TYPE::BLUE] = CreateSolidBrush(RGB(0, 0, 255));
	m_arrBrush[(UINT)BRUSH_TYPE::BLACK] = CreateSolidBrush(RGB(0, 0, 0));


	// red, green, blue pen 생성
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

}

void CEngine::CopyBackBuffer()
{
	// m_SubDC -> m_DC 로 복사
	BitBlt(m_hDC, 0, 0, m_ptResloution.x, m_ptResloution.y, m_hSubDC, 0, 0, SRCCOPY);
}
