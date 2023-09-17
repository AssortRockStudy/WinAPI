#include "pch.h"

#include "CProjectile.h"
#include "CPaletteMgr.h"

CProjectile::CProjectile() :m_Speed(0.f), m_Angle(PI / 2.f) {}

CProjectile::~CProjectile() {}

void CProjectile::tick(float _dt) {
	Vec2 vPos = GetPos();

	vPos.x += m_Speed * cosf(m_Angle) * _dt;
	vPos.y -= m_Speed * sinf(m_Angle) * _dt;

	SetPos(vPos);
}

void CProjectile::render(HDC _dc) {
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	CPaletteMgr::GetInst()->SelectBrush(CPaletteMgr::BrushColor::BBLACK);
	CPaletteMgr::GetInst()->SelectPen(CPaletteMgr::PenColor::PBLACK);

	Ellipse(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));
}