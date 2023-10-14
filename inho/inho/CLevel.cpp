﻿#include "pch.h"

#include "CLevel.h"

#include "CLayer.h"
#include "CMonster.h"
#include "CObj.h"
#include "CTimeMgr.h"
#include "CTile.h"

CLevel::CLevel(): m_TileRow(0), m_TileCol(0) {
    for (UINT i = 0; i < LAYER::END; ++i) {
        m_Layer[i] = new CLayer;
    }
}

CLevel::~CLevel() {
    for (UINT i = 0; i < LAYER::END; ++i) {
        delete m_Layer[i];
    }
}

VOID CLevel::begin() {
    for (UINT i = 0; i < LAYER::END; ++i) {
        m_Layer[i]->begin();
    }
}

void CLevel::tick() {
    for (UINT i = 0; i < LAYER::END; ++i) {
        m_Layer[i]->clear();
    }
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

    _Object->m_iLayerIdx = _LayerType;
}

void CLevel::DeleteAllObjects()
{
    for (UINT i = 0; i < LAYER::END; i++) {
        m_Layer[i]->DeleteAllObjects();
    }
}

void CLevel::CreateTile(UINT _Row, UINT _Col)
{
    m_TileRow = _Row;
    m_TileCol = _Col;

    for (UINT i = 0; i < _Row; i++) {
        for (UINT j = 0; j < _Col; j++) {
            CTile* pTile = new CTile;
            AddObject(TILE, pTile);
        }
    }

}
