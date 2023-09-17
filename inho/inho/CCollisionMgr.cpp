﻿#include "pch.h"

#include "CCollisionMgr.h"

#include "CCollider.h"
#include "CLevel.h"
#include "CLevelMgr.h"
#include "CObj.h"

CCollisionMgr::CCollisionMgr() : m_LayerCheck{} {}

CCollisionMgr::~CCollisionMgr() {}

void CCollisionMgr::tick() {
    CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

    for (UINT iRow = 0; iRow < LAYER::END; ++iRow) {
        for (UINT iCol = iRow; iCol < LAYER::END; ++iCol) {
            if (!(m_LayerCheck[iRow] & (1 << iCol)))
                continue;

            const vector<CObj*>& vecLeft = pCurLevel->GetObjects((LAYER)iRow);
            const vector<CObj*>& vecRight = pCurLevel->GetObjects((LAYER)iCol);
        }
    }
}

void CCollisionMgr::CheckCollision(LAYER _Left, LAYER _Right) {
    int row = 0, col = 0;

    if (_Left < _Right) {
        row = _Left;
        col = _Right;
    } else {
        col = _Left;
        row = _Right;
    }

    m_LayerCheck[row] |= (1 << col);
}

void CCollisionMgr::UncheckCollision(LAYER _Left, LAYER _Right) {
    int row = 0, col = 0;

    if (_Left < _Right) {
        row = _Left;
        col = _Right;
    } else {
        col = _Left;
        row = _Right;
    }

    m_LayerCheck[row] &= ~(1 << col);
}