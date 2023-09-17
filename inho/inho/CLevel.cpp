#include "pch.h"

#include "CLevel.h"

#include "CLayer.h"
#include "CMonster.h"
#include "CObj.h"
#include "CTimeMgr.h"

CLevel::CLevel() {
    for (UINT i = 0; i < LAYER::END; ++i) {
        m_Layer[i] = new CLayer;
    }
}

CLevel::~CLevel() {
    for (UINT i = 0; i < LAYER::END; ++i) {
        delete m_Layer[i];
    }
}

void CLevel::tick() {
    for (UINT i = 0; i < LAYER::END; ++i) {
        m_Layer[i]->tick(DT);
    }
    for (UINT i = 0; i < LAYER::END; ++i) {
        m_Layer[i]->finaltick(DT);
    }
}

void CLevel::render(HDC _dc) {
    for (UINT i = 0; i < LAYER::END; ++i) {
        m_Layer[i]->render(_dc);
    }
}

void CLevel::AddObject(LAYER _LayerType, CObj* _Object) {
    m_Layer[_LayerType]->AddObject(_Object);
}
