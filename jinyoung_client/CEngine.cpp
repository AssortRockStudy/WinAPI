#include "pch.h"
#include "CEngine.h"


#include "CLevel.h"
#include "CPlayer.h"


static CEngine* pEngine=nullptr;


CEngine::CEngine()
	: m_hWnd(nullptr)
	, m_ptResolution{}
	, m_Level(nullptr)
	, m_dc(nullptr)
{
}



CEngine::~CEngine()
{
	// DC ����
	ReleaseDC(m_hWnd, m_dc);

	// ���� ����
	if (nullptr != m_Level)
		delete m_Level;
}


void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// �ػ� ����
	SetWindowPos(m_hWnd, nullptr, 1930, 10, m_ptResolution.x, m_ptResolution.y, 0);
	ShowWindow(m_hWnd, true);

	// DC ����
	m_dc = GetDC(m_hWnd);

	// Level ����
	m_Level = new CLevel;

	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(POINT{ 500, 500 });
	pPlayer->SetScale(POINT{ 50, 50 });

	m_Level->AddObject(pPlayer);

}

//tick() 1ȸ ==>1������
//FPS(Frame Per Second
void CEngine::tick()
{
	m_Level->tick();
	m_Level->render(m_dc);
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