#include "pch.h"


#include "CPlayer.h"

#include "CPaletteMgr.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLevel.h"
#include "CPathMgr.h"
#include "CEngine.h"

#include "CProjectile.h"
#include "CPosGuidedProjectile.h"
#include "CAccGuidedProjectile.h"
#include "CAngularGuidedProjectile.h"


CPlayer::CPlayer() : m_Speed(500.f), m_Image(nullptr) {
    wstring strPath = CPathMgr::GetContentPath();
    strPath += L"texture\\fighter.bmp";

    // �÷��̾ ����� �̹��� ��Ʈ�� �ε�
    m_Image = (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    m_ImageDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());
    DeleteObject(SelectObject(m_ImageDC, m_Image));
    GetObject(m_Image, sizeof(BITMAP), & m_BitmapInfo);
    
}

CPlayer::~CPlayer() {
    DeleteObject(m_Image);
    DeleteDC(m_ImageDC);
}

void CPlayer::tick(float _DT) {
    Vec2 vPos = GetPos();

    if (KEY_PRESSED(LEFT)) {
        vPos.x -= m_Speed * _DT;
    }

    if (KEY_PRESSED(RIGHT)) {
        vPos.x += m_Speed * _DT;
    }

    if (KEY_PRESSED(UP)) {
        vPos.y -= m_Speed * _DT;
    }

    if (KEY_PRESSED(DOWN)) {
        vPos.y += m_Speed * _DT;
    }

    if (KEY_TAP(SPACE)) {
        CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

        for (int i = 0; i < 3; i++) {
            CAngularGuidedProjectile* pProjectile = new CAngularGuidedProjectile;

            Vec2 ProjectilePos = GetPos();
            ProjectilePos.y -= GetScale().y / 2.f;
            
            pProjectile->SetSpeed(1000.f);
            pProjectile->SetDir((PI / 4.f) * (float)(i + 1));
            pProjectile->SetPos(ProjectilePos);
            pProjectile->SetScale(Vec2(25.f, 25.f));

            pCurLevel->AddObject(pProjectile);
        }
    }

    SetPos(vPos);
}

void CPlayer::render(HDC _dc) {
    Vec2 vPos = GetPos();
    Vec2 vScale = GetScale();

    CPaletteMgr* palette = CPaletteMgr::GetInst();

    palette->SelectPen(CPaletteMgr::PenColor::PBLACK);
    palette->SelectBrush(CPaletteMgr::BrushColor::BBLACK);
    
    BitBlt(_dc, vPos.x - m_BitmapInfo.bmWidth / 2.f,
        vPos.y - m_BitmapInfo.bmHeight / 2.f,
        m_BitmapInfo.bmWidth,
        m_BitmapInfo.bmHeight,
        m_ImageDC,
        0, 0, SRCCOPY);
}