#include "pch.h"

#include "CPaletteMgr.h"
#include "CProjectile.h"

CProjectile::CProjectile() : m_Speed(0.f), m_Angle(PI / 2.f) {}

CProjectile::~CProjectile() {}

void CProjectile::render(HDC _dc) {
    Vec2 vPos = GetRenderPos();
    Vec2 vScale = GetScale();

    CPaletteMgr::GetInst()->SelectBrush(CPaletteMgr::BrushColor::BBLACK);
    CPaletteMgr::GetInst()->SelectPen(CPaletteMgr::PenColor::PBLACK);

    Ellipse(_dc, int(vPos.x - vScale.x / 2), int(vPos.y - vScale.y / 2),
            int(vPos.x + vScale.x / 2), int(vPos.y + vScale.y / 2));

    CObj::render(_dc);
}