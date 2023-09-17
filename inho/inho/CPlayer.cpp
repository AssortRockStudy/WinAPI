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
#include "CGuidedProjectile.h"


CPlayer::CPlayer() : m_Speed(500.f), m_Image(nullptr) {
    wstring strPath = CPathMgr::GetContentPath();
    strPath += L"texture\\fighter.bmp";

    // 플레이어가 사용할 이미지 비트맵 로딩
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

        for (int i = 0; i < 1; i++) {
            CGuidedProjectile* pProjectile = new CGuidedProjectile;

            Vec2 ProjectilePos = GetPos();
            ProjectilePos.y -= GetScale().y / 2.f;
            
            pProjectile->SetSpeed(1000.f);
            pProjectile->SetAngle((PI / 4.f) * (float)(i + 1));
            pProjectile->SetPos(ProjectilePos);
            pProjectile->SetScale(Vec2(25.f, 25.f));
            pProjectile->SetDir(Vec2(0.f, -1.f));

            CTaskMgr::GetInst()->AddTask(FTask{ CREATE_OBJECT, PLAYER_PJ, (UINT_PTR)pProjectile });
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
    

    TransparentBlt(_dc, vPos.x - (int)m_BitmapInfo.bmWidth / 2,
        vPos.y - (int)m_BitmapInfo.bmHeight / 2,
        m_BitmapInfo.bmWidth,
        m_BitmapInfo.bmHeight,
        m_ImageDC,
        0, 0,
        m_BitmapInfo.bmWidth,
        m_BitmapInfo.bmHeight,
        RGB(255, 0, 255));
}
