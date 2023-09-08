#include "pch.h"
#include "CEngine.h"

#include "CTimeManager.h"
#include "CKeyman.h"

#include "CLevel.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CKeyman.h"
#include "CEngine.h"




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

	DeleteObject(m_subbitmap);
	//�츮������ dc�� deletedc�� �������Ѵ�
	DeleteDC(m_subdc);
}


void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// �ػ� ����
	SetWindowPos(m_hWnd, nullptr, 20, 10, m_ptResolution.x, m_ptResolution.y, 0);
	ShowWindow(m_hWnd, true);

	// DC : Device Context
	// pen : Black 
	// brush : White
	// Bitmap(�׸� �׸� ��) : �ڵ鿡 �ش��ϴ� ������ ��Ʈ��
	m_dc = GetDC(m_hWnd);
	m_subbitmap= CreateCompatibleBitmap(m_dc, m_ptResolution.x, m_ptResolution.y);
	m_subdc = CreateCompatibleDC(m_dc);

	//m_subdc�� msubbitmap�� �����ϰ� ���� �������� �����մ�
	DeleteObject(SelectObject(m_subdc, m_subbitmap));

	// Manager �ʱ�ȭ
	CTimeManager::GetInst()->init();
	CKeyman::GetInst()->init();


	// Level ����
	m_Level = new CLevel;

	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(Vec2(200.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	m_Level->AddObject(pPlayer);

	CMonster* pMonster = new CMonster;

	pMonster->SetPos(Vec2(600.f, 500.f));
	pMonster->SetScale(Vec2(50.f, 50.f));

	m_Level->AddObject(pMonster);


}

//tick() 1ȸ ==>1������
//FPS(Frame Per Second
void CEngine::tick()
{
	// TimeMgr
	CTimeManager::GetInst()->tick();
	CKeyman::GetInst()->tick();
	m_Level->tick();


	Rectangle(m_dc, 0, 0, m_ptResolution.x, m_ptResolution.y);



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