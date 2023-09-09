#include "pch.h"

#include "CEngine.h"


// Manager
#include "CPaletteMgr.h"
#include "CTimeMgr.h"

#include "CLevel.h"
#include "CMonster.h"
#include "CPlayer.h"
#include "CKeyMgr.h"
#include "CPathMgr.h"
#include "CLevelMgr.h"

CEngine::CEngine()
    : m_hWnd(nullptr),
    m_ptResolution{},
    m_Level(nullptr),
    m_dc(nullptr),
    m_SubBitMap(nullptr)
 {}

CEngine::~CEngine() {
    ReleaseDC(m_hWnd, m_dc);

    DeleteObject(m_SubBitMap);
    DeleteObject(m_SubDC);

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

    m_SubBitMap = CreateCompatibleBitmap(m_dc, m_ptResolution.x, m_ptResolution.y);
    m_SubDC = CreateCompatibleDC(m_dc);

    DeleteObject((HBITMAP)SelectObject(m_SubDC, m_SubBitMap));

    // Manager �ʱ�ȭ
    CTimeMgr::GetInst()->init();
    CPaletteMgr::GetInst()->init(m_SubDC);
    CKeyMgr::GetInst()->init();
    CPathMgr::init();
    CLevelMgr::GetInst()->init();
}

void CEngine::tick() {
    // TimeMgr
    CTimeMgr::GetInst()->tick();
    CKeyMgr::GetInst()->tick();

    CLevelMgr::GetInst()->tick();
    CLevelMgr::GetInst()->render(m_SubDC);
}