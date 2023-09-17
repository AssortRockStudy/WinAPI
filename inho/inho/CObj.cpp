#include "pch.h"

#include "CObj.h"
#include "CComponent.h"

CObj::CObj() {}

CObj::~CObj() {
    for (size_t i = 0; i < m_vecComponent.size(); ++i) {
        if (nullptr != m_vecComponent[i]) {
            delete m_vecComponent[i];
        }
    }
}

void CObj::tick(float _DT)
{
    for (size_t i = 0; i < m_vecComponent.size(); ++i) {
        m_vecComponent[i]->tick(_DT);
    }
}

void CObj::finaltick(float _DT)
{
    for (size_t i = 0; i < m_vecComponent.size(); ++i) {
        m_vecComponent[i]->finaltick(_DT);
    }
}

void CObj::render(HDC _dc) {
    for (size_t i = 0; i < m_vecComponent.size(); ++i) {
        m_vecComponent[i]->render(_dc);
    }
}
