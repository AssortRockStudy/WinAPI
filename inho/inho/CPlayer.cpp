﻿#include "pch.h"

#include "CPlayer.h"

#include "CEngine.h"
#include "CKeyMgr.h"
#include "CLevel.h"
#include "CLevelMgr.h"
#include "CPaletteMgr.h"
#include "CPathMgr.h"
#include "CTimeMgr.h"

#include "CGuidedProjectile.h"
#include "CProjectile.h"

#include "CCollider.h"

CPlayer::CPlayer() : m_Speed(500.f), m_Image(nullptr) {
    wstring strPath = CPathMgr::GetContentPath();
    strPath += L"texture\\fighter.bmp";

    // 플레이어가 사용할 이미지 비트맵 로딩
    m_Image = (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0,
                                 LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    m_ImageDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());
    DeleteObject(SelectObject(m_ImageDC, m_Image));
    GetObject(m_Image, sizeof(BITMAP), &m_BitmapInfo);

    // 컴포넌트 추가
    m_Collider = AddComponent<CCollider>(L"PlayerCollider");
    m_Collider->SetOffsetPos(Vec2(0.f, 10.f));
    m_Collider->SetScale(Vec2(40.f, 80.f));
}

CPlayer::~CPlayer() {
    DeleteObject(m_Image);
    DeleteDC(m_ImageDC);
}

void CPlayer::tick(float _DT) {
    Super::tick(_DT);

    Vec2 vPos = GetPos();

    if (KEY_PRESSED(A)) {
        vPos.x -= m_Speed * _DT;
    }

    if (KEY_PRESSED(D)) {
        vPos.x += m_Speed * _DT;
    }

    if (KEY_PRESSED(W)) {
        vPos.y -= m_Speed * _DT;
    }

    if (KEY_PRESSED(S)) {
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

            CTaskMgr::GetInst()->AddTask(
                FTask{CREATE_OBJECT, PLAYER_PJ, (UINT_PTR)pProjectile});
        }
    }

    SetPos(vPos);
}

void CPlayer::render(HDC _dc) {
    Vec2 vPos = GetRenderPos();
    Vec2 vScale = GetScale();

    TransparentBlt(_dc, vPos.x - (int)m_BitmapInfo.bmWidth / 2,
                   vPos.y - (int)m_BitmapInfo.bmHeight / 2,
                   m_BitmapInfo.bmWidth, m_BitmapInfo.bmHeight, m_ImageDC, 0, 0,
                   m_BitmapInfo.bmWidth, m_BitmapInfo.bmHeight,
                   RGB(255, 0, 255));

    Super::render(_dc);
}

void CPlayer::Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
    _OwnCol->GetName();
}
