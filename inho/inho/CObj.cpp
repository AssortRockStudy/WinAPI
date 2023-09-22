#include "pch.h"

#include "CComponent.h"
#include "CObj.h"
#include "CTaskMgr.h"

CObj::CObj(): 
    m_iLayerIdx(-1)
{}

CObj::~CObj() {
    for (size_t i = 0; i < m_vecComponent.size(); ++i) {
        if (nullptr != m_vecComponent[i]) {
            delete m_vecComponent[i];
        }
    }
}

void CObj::tick(float _DT) {
    for (size_t i = 0; i < m_vecComponent.size(); ++i) {
        m_vecComponent[i]->tick(_DT);
    }
}

void CObj::finaltick(float _DT) {
    for (size_t i = 0; i < m_vecComponent.size(); ++i) {
        m_vecComponent[i]->finaltick(_DT);
    }
}

void CObj::render(HDC _dc) {
    for (size_t i = 0; i < m_vecComponent.size(); ++i) {
        m_vecComponent[i]->render(_dc);
    }
}

void CObj::Destroy() {
    FTask task;
    task.Type = TASK_TYPE::DELETE_OBJECT;
    task.Param_1 = (INT_PTR)this;
    CTaskMgr::GetInst()->AddTask(task);
}

void CObj::SetDead() {
    m_bDead = true;

    for (size_t i = 0; i < m_vecComponent.size(); ++i) {
        m_vecComponent[i]->m_bDead = true;
    }
}