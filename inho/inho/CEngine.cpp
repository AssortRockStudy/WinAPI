#include "pch.h"

#include "CEngine.h"

// Manager
#include "CPaletteMgr.h"
#include "CTimeMgr.h"

#include "CCamera.h"
#include "CCollisionMgr.h"
#include "CKeyMgr.h"
#include "CLevel.h"
#include "CLevelMgr.h"
#include "CMonster.h"
#include "CPathMgr.h"
#include "CPlayer.h"
#include "CTaskMgr.h"

#include "CGCMgr.h"

CEngine::CEngine()
    : m_hWnd(nullptr), m_ptResolution{}, m_dc(nullptr),
      m_SubBitMap(nullptr), m_bDebugRender(true) {}

CEngine::~CEngine() {
    ReleaseDC(m_hWnd, m_dc);

    DeleteObject(m_SubBitMap);
    DeleteObject(m_SubDC);

}

void CEngine::init(HWND _hWnd, POINT _ptResolution) {
    m_hWnd = _hWnd;
    ChangeWindowSize(_ptResolution, false);
    ShowWindow(m_hWnd, true);

    // DC : Device Context
    // pen : Black
    // brush : White
    // Bitmap(�׸� �׸� ��) : �ڵ鿡 �ش��ϴ�
    // ������ ��Ʈ��
    m_dc = GetDC(m_hWnd);

    m_SubBitMap =
        CreateCompatibleBitmap(m_dc, m_ptResolution.x, m_ptResolution.y);
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
    CCamera::GetInst()->tick();

    if (KEY_TAP(NUM8)) {
        m_bDebugRender = !m_bDebugRender;
    }

    CLevelMgr::GetInst()->tick();
    CCollisionMgr::GetInst()->tick();

    CLevelMgr::GetInst()->render(m_SubDC);

    CTaskMgr::GetInst()->tick();

    CGCMgr::GetInst()->tick();

    
}

void CEngine::ChangeWindowSize(POINT _ptResolution, bool _bMenu)
{
    m_ptResolution = _ptResolution;

    RECT rt = { 0, 0, _ptResolution.x, _ptResolution.y };
    AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, _bMenu);
    SetWindowPos(m_hWnd, nullptr, 10, 10, rt.right - rt.left, rt.bottom - rt.top, 0);
}