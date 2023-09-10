﻿#include "pch.h"
#include "CEngine.h"


#include "CLevel.h"
#include "CPlayer.h"
#include "CMonster.h"

#include "CTimeManager.h"
#include "CKeyman.h"
#include "CLevelMgr.h"
#include "CPathMgr.h"




CEngine::CEngine()
	: m_hWnd(nullptr)
	, m_ptResolution{}
	, m_Level(nullptr)
	, m_dc(nullptr)
{
}



CEngine::~CEngine()
{
	// DC 해제
	ReleaseDC(m_hWnd, m_dc);


	DeleteObject(m_subbitmap);
	//우리가만든 dc는 deletedc로 지워야한다
	DeleteDC(m_subdc);

	// 레벨 해제
	if (nullptr != m_Level)
		delete m_Level;
}


void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// 해상도 변경
	SetWindowPos(m_hWnd, nullptr, 20, 10, m_ptResolution.x, m_ptResolution.y, 0);
	ShowWindow(m_hWnd, true);

	// DC : Device Context
	// pen : Black 
	// brush : White
	// Bitmap(그림 그릴 곳) : 핸들에 해당하는 윈도우 비트맵
	m_dc = GetDC(m_hWnd);


	// 추가 비트맵 버퍼
	m_subbitmap= CreateCompatibleBitmap(m_dc, m_ptResolution.x, m_ptResolution.y);
	m_subdc = CreateCompatibleDC(m_dc);

	//m_subdc가 msubbitmap을 저장하고 원래 목적지로 갖고잇던BitMap 이 반환값으로 나오는데, 
	// 이걸 바로 DeleteObject 함수에 전달시켜서 삭제요청한다.
	DeleteObject((HBITMAP)SelectObject(m_subdc, m_subbitmap));

	// Manager 초기화
	CTimeManager::GetInst()->init();
	CKeyman::GetInst()->init();
	CLevelMgr::GetInst()->init();
	CPathMgr::init();

	//레벨매니저로 이관
	//// Level 생성
	//m_Level = new CLevel;

	//CPlayer* pPlayer = new CPlayer;

	//pPlayer->SetPos(Vec2(200.f, 500.f));
	//pPlayer->SetScale(Vec2(50.f, 50.f));

	//m_Level->AddObject(pPlayer);

	//CMonster* pMonster = new CMonster;

	//pMonster->SetPos(Vec2(600.f, 500.f));
	//pMonster->SetScale(Vec2(50.f, 50.f));

	//m_Level->AddObject(pMonster);


}

//tick() 1회 ==>1프레임
//FPS(Frame Per Second
void CEngine::tick()
{
	// TimeMgr
	CTimeManager::GetInst()->tick();
	CKeyman::GetInst()->tick();
	
	

	//m_Level->tick();
	//m_Level->render(m_dc);
	//Rectangle(m_dc, 0, 0, m_ptResolution.x, m_ptResolution.y);

	// LevelMgr
	CLevelMgr::GetInst()->tick();
	CLevelMgr::GetInst()->render(m_subdc);

	/*static int Call = 0;
	++Call;
	int CurCount = 0;
	static int PrevCount = GetTickCount();


	CurCount = GetTickCount();


	if (1000 < (CurCount - PrevCount))
	{
		Call = 0;
		PrevCount = CurCount;
	}*/
}