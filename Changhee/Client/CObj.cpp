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

	Rectangle(_dc
		, int(m_vPos.x - m_vScale.x / 2)
		, int(m_vPos.y - m_vScale.y / 2)
		, int(m_vPos.x + m_vScale.x / 2)
		, int(m_vPos.y + m_vScale.y / 2));

}

