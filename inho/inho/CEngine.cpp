#include "CEngine.h"
#include "pch.h"

// Manager
#include "CPaletteMgr.h"
#include "CTimeMgr.h"

#include "CLevel.h"
#include "CMonster.h"
#include "CPlayer.h"

CEngine::CEngine()
    : m_hWnd(nullptr), m_ptResolution{}, m_Level(nullptr), m_dc(nullptr) {}

CEngine::~CEngine() {
    ReleaseDC(m_hWnd, m_dc);

    if (nullptr != m_Level)
        delete m_Level;
}

void CEngine::init(HWND _hWnd, POINT _ptResolution) {
    m_hWnd = _hWnd;
    m_ptResolution = _ptResolution;

    SetWindowPos(m_hWnd, nullptr, 10, 10, m_ptResolution.x, m_ptResolution.y,
                 0);
    ShowWindow(m_hWnd, true);

    // DC : Device Context
    // pen : Black
    // brush : White
    // Bitmap(�׸� �׸� ��) : �ڵ鿡 �ش��ϴ� ������
    // ��Ʈ��
    m_dc = GetDC(m_hWnd);

    // Manager �ʱ�ȭ
    CTimeMgr::GetInst()->init();
    CPaletteMgr::GetInst()->init(m_dc);

    // Level
    m_Level = new CLevel;

    CPlayer* pPlayer = new CPlayer;

    pPlayer->SetPos(Vec2(500.f, 500.f));
    pPlayer->SetScale(Vec2(50.f, 50.f));

    CMonster* pMonster = new CMonster;
    pMonster->SetPos(Vec2(500.f, 500.f));
    pMonster->SetScale(Vec2(50.f, 50.f));

    m_Level->AddObject(pPlayer);
    m_Level->AddObject(pMonster);
}

void CEngine::tick() {
    // TimeMgr
    CTimeMgr::GetInst()->tick();

    m_Level->tick();
    m_Level->render(m_dc);
}