#include "pch.h"

#include "CLevelMgr.h"

#include "CCamera.h"
#include "CEngine.h"

#include "CLevel.h"
#include "CMonster.h"
#include "CPaletteMgr.h"
#include "CPlayer.h"
#include "CLogMgr.h"
#include "CCollisionMgr.h"

#include "CPlatform.h"

CLevelMgr::CLevelMgr():m_pCurLevel(nullptr) {}
CLevelMgr::~CLevelMgr() {
    if (nullptr != m_pCurLevel) {
        delete m_pCurLevel;
    }
};

void CLevelMgr::init() {

    m_pCurLevel = new CLevel;

    CPlayer* pPlayer = new CPlayer;

    pPlayer->SetPos(Vec2(500.f, 200.f));
    pPlayer->SetScale(Vec2(50.f, 50.f));

    m_pCurLevel->AddObject(PLAYER, pPlayer);

    CPlatform* pPlatform = new CPlatform;
    pPlatform->SetPos(Vec2(800.f, 700.f));
    m_pCurLevel->AddObject(PLATFORM, pPlatform);
    
    // 카메라 설정
    Vec2 vLookAt = CEngine::GetInst()->GetResolution();
    vLookAt /= 2.f;
    CCamera::GetInst()->SetLookAt(vLookAt);


    CCollisionMgr::GetInst()->CheckCollision(MONSTER, PLAYER);
    CCollisionMgr::GetInst()->CheckCollision(MONSTER, PLAYER_PJ);
    CCollisionMgr::GetInst()->CheckCollision(PLATFORM, PLAYER);

    m_pCurLevel->begin();
}

void CLevelMgr::tick() { m_pCurLevel->tick(); }

void CLevelMgr::render(HDC _dc) {

    POINT ptResolution = CEngine::GetInst()->GetResolution();
    Rectangle(_dc, -1, -1, ptResolution.x, ptResolution.y);

    m_pCurLevel->render(_dc);
    CPaletteMgr::GetInst()->SelectBrush(CPaletteMgr::BrushColor::BWHITE);

    CLogMgr::GetInst()->tick(_dc);
    BitBlt(CEngine::GetInst()->GetMainDC(), 0, 0, ptResolution.x,
           ptResolution.y, _dc, 0, 0, SRCCOPY);
}