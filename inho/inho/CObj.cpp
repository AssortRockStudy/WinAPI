#include "pch.h"

#include "CObj.h"

CObj::CObj() {}

CObj::~CObj() {}

void CObj::render(HDC _dc) {
    Rectangle(_dc, int(m_Pos.x - m_Scale.x / 2), int(m_Pos.y - m_Scale.y / 2),
              int(m_Pos.x + m_Scale.x / 2), int(m_Pos.y + m_Scale.y / 2));
}
