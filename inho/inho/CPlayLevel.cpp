#include "pch.h"
#include "CPlayLevel.h"

#include "CPlayer.h"
#include "CPlatform.h"

#include "CEngine.h"
#include "CCollisionMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"

void CPlayLevel::init()
{

    CPlayer* pPlayer = new CPlayer;

    pPlayer->SetPos(Vec2(500.f, 200.f));
    pPlayer->SetScale(Vec2(50.f, 50.f));

    AddObject(PLAYER, pPlayer);

    CPlatform* pPlatform = new CPlatform;
    pPlatform->SetPos(Vec2(800.f, 700.f));
    AddObject(PLATFORM, pPlatform);

    // 카메라 설정
    Vec2 vLookAt = CEngine::GetInst()->GetResolution();
    vLookAt /= 2.f;
    CCamera::GetInst()->SetLookAt(vLookAt);


    CCollisionMgr::GetInst()->CheckCollision(MONSTER, PLAYER);
    CCollisionMgr::GetInst()->CheckCollision(MONSTER, PLAYER_PJ);
    CCollisionMgr::GetInst()->CheckCollision(PLATFORM, PLAYER);
}

void CPlayLevel::enter()
{
    init();
}

void CPlayLevel::exit()
{
    DeleteAllObjects();
}

void CPlayLevel::tick()
{
    CLevel::tick();

    if (KEY_TAP(KEY::ENTER)) {
        ChangeLevel(LEVEL_TYPE::EDITOR_LEVEL);
    }
}
