#include "pch.h"

#include "CPlayer.h"

#include "CEngine.h"
#include "CKeyMgr.h"
#include "CLevel.h"
#include "CLevelMgr.h"
#include "CPaletteMgr.h"
#include "CPathMgr.h"
#include "CTimeMgr.h"
#include "CAssetMgr.h"
#include "CTexture.h"

#include "CGuidedProjectile.h"
#include "CProjectile.h"

#include "CCollider.h"
#include "CAnimator.h"
#include "CAnim.h"

#include "CLogMgr.h"


CPlayer::CPlayer() : m_Speed(500.f) {
    
    // 컴포넌트 추가
    m_Collider = AddComponent<CCollider>(L"PlayerCollider");
    m_Collider->SetOffsetPos(Vec2(0.f, 10.f));
    m_Collider->SetScale(Vec2(40.f, 80.f));
    m_Collider->SetOffsetPos(Vec2(0.f, -40.f));

    CTexture* pAtlas = CAssetMgr::GetInst()->LoadTexture(L"PlayerAtlas", L"texture\\link.bmp");
    m_Animator = AddComponent<CAnimator>(L"Animator");
    Vec2 offset(0.f, -60.f);
    m_Animator->CreateAnimation(L"WalkDown", pAtlas, Vec2(0.f, 520.f), Vec2(120, 130), offset, 0.05f, 10);
    m_Animator->CreateAnimation(L"WalkLeft", pAtlas, Vec2(0.f, 650.f), Vec2(120, 130), offset, 0.05f, 10);
    m_Animator->CreateAnimation(L"WalkUp", pAtlas, Vec2(0.f, 780.f), Vec2(120, 130), offset, 0.05f, 10);
    m_Animator->CreateAnimation(L"WalkRight", pAtlas, Vec2(0.f, 910.f), Vec2(120, 130), offset, 0.05f, 10);

    m_Animator->CreateAnimation(L"IdleDown", pAtlas, Vec2(0.f, 0.f), Vec2(120, 130), offset, 0.05f, 3);
    m_Animator->CreateAnimation(L"IdleLeft", pAtlas, Vec2(0.f, 130.f), Vec2(120, 130), offset, 0.05f, 3);
    m_Animator->CreateAnimation(L"IdleUp", pAtlas, Vec2(0.f, 260.f), Vec2(120, 130), offset, 0.05f, 1);
    m_Animator->CreateAnimation(L"IdleRight", pAtlas, Vec2(0.f, 390.f), Vec2(120, 130), offset, 0.05f, 3);

    m_Animator->SaveAnimation(L"animdata");

    m_Animator->Play(L"WalkDown", true);

    m_pTexture = CAssetMgr::GetInst()->LoadTexture(L"PlayerTexture", L"texture\\fighter.bmp");
}

CPlayer::~CPlayer() {
    
}

void CPlayer::tick(float _DT) {
    Super::tick(_DT);

    Vec2 vPos = GetPos();

    if (KEY_PRESSED(A))
    {
        vPos.x -= m_Speed * _DT;
        m_Animator->Play(L"WalkLeft", true);
    }

    if (KEY_RELEASED(A))
    {
        m_Animator->Play(L"IdleLeft", true);
    }

    if (KEY_PRESSED(D))
    {
        vPos.x += m_Speed * _DT;
        m_Animator->Play(L"WalkRight", true);
    }
    if (KEY_RELEASED(D))
    {
        m_Animator->Play(L"IdleRight", true);
    }


    if (KEY_PRESSED(W))
    {
        vPos.y -= m_Speed * _DT;
        m_Animator->Play(L"WalkUp", true);
    }
    if (KEY_RELEASED(W))
    {
        m_Animator->Play(L"IdleUp", true);
    }

    if (KEY_PRESSED(S))
    {
        vPos.y += m_Speed * _DT;
        m_Animator->Play(L"WalkDown", true);
    }
    if (KEY_RELEASED(S))
    {
        m_Animator->Play(L"IdleDown", true);
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
        
        LOG(WARNING, L"경고");
    }


    SetPos(vPos);
}


void CPlayer::Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
    _OwnCol->GetName();
}
