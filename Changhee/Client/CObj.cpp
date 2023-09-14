#include "pch.h"
#include "CObj.h"

CObj::CObj()
{
}

CObj::~CObj()
{
}

void CObj::render(HDC _dc)
{
	CPalette tmp(_dc, PEN_TYPE::RED);

	Vec2 vRenderPos = GetRenderPos();

	Rectangle(_dc
		, int(vRenderPos.x - m_vScale.x / 2)
		, int(vRenderPos.y - m_vScale.y / 2)
		, int(vRenderPos.x + m_vScale.x / 2)
		, int(vRenderPos.y + m_vScale.y / 2));

}

