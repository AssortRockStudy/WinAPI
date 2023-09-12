#include "pch.h"

#include "CLevel.h"


#include "CObj.h"
#include "CTimeMgr.h"
#include "CMonster.h"

CLevel::CLevel() {}

CLevel::~CLevel() {
    for (size_t i = 0; i < m_vecObjects.size(); ++i) {
        delete m_vecObjects[i];
    }
    for (size_t i = 0; i < m_vecMonsters.size(); ++i) {
        delete m_vecMonsters[i];
    }
}

void CLevel::tick() {
    float DT = CTimeMgr::GetInst()->GetDeltaTime();

    for (size_t i = 0; i < m_vecObjects.size(); ++i) {
        m_vecObjects[i]->tick(DT);
    }
    for (size_t i = 0; i < m_vecMonsters.size(); ++i) {
        m_vecMonsters[i]->tick(DT);
    }
}

void CLevel::render(HDC _dc) {
    for (size_t i = 0; i < m_vecObjects.size(); ++i) {
        m_vecObjects[i]->render(_dc);
    }
    for (size_t i = 0; i < m_vecMonsters.size(); ++i) {
        m_vecMonsters[i]->render(_dc);
    }
}
