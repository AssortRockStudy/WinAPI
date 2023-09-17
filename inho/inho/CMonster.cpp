#include "pch.h"


#include "CMonster.h"

#include "CPaletteMgr.h"
#include "CTimeMgr.h"

CMonster::CMonster() {
    
}

CMonster::~CMonster() {}

void CMonster::tick(float _DT) {
    Super::tick(_DT);

    Vec2 vPos = GetPos();

    /*if (GetAsyncKeyState('A') & 0x8001) {
        vPos.x += m_Speed * _DT;
    }

    if (GetAsyncKeyState('D') & 0x8001) {
        vPos.x -= m_Speed * _DT;
    }

    if (GetAsyncKeyState('W') & 0x8001) {
        vPos.y += m_Speed * _DT;
    }

    if (GetAsyncKeyState('S') & 0x8001) {
        vPos.y -= m_Speed * _DT;
    }*/

    static float ftime = 0;
    static bool flag = false;
    ftime += CTimeMgr::GetInst()->GetDeltaTime();
    /*if (ftime > 1.f) {
        if (!flag) {
            flag = true;
        }
        else {
            flag = false;
        }
        ftime = 0;
    }
    if (flag) {
        vPos.x += m_Speed * _DT;
    }
    else {
        vPos.x -= m_Speed * _DT;
    }*/

    SetPos(vPos);
}

void CMonster::render(HDC _dc) {
    Vec2 vPos = GetRenderPos();
    Vec2 vScale = GetScale();

    CPaletteMgr* palette = CPaletteMgr::GetInst();

    palette->SelectPen(CPaletteMgr::PenColor::PRED);
    palette->SelectBrush(CPaletteMgr::BrushColor::BRED);
    Ellipse(_dc, int(vPos.x - vScale.x / 2), int(vPos.y - vScale.y / 2),
            int(vPos.x + vScale.x / 2), int(vPos.y + vScale.y / 2));
}
