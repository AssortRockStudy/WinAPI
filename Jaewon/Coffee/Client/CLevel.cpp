#include "pch.h"
#include "CLevel.h"
#include "CObj.h"
#include "CTimeMgr.h"
#include "Monster.h"
#include "Tile.h"

void CLevel::begin()
{
	for (UINT i = 0; i < LAYER::END; ++i) {
		m_Layer[i]->begin();
	}
	
}

// 레벨에 들어있는 오브젝트들의 tick을 다 실행
void CLevel::tick()
{
	for (UINT i = 0; i < LAYER::END; ++i) {
		m_Layer[i]->clear();
	}
	for (UINT i = 0; i < LAYER::END; ++i){
		m_Layer[i]->tick();
	}
	for (UINT i = 0; i < LAYER::END; ++i) {
		m_Layer[i]->finalTick();
	}
}

// 레벨에 들어있는 오브젝트들의 render을 다 실행
void CLevel::render(HDC _dc)
{
	for (UINT i = 0; i < LAYER::END; ++i){
		m_Layer[i]->render(_dc);
	}
}

void CLevel::addObject(LAYER _type, CObj* _obj)
{
	m_Layer[_type]->AddObj(_obj);

	_obj->mLayerIdx = _type;
}

void CLevel::deleteAllObjects()
{
	for (UINT i = 0; i < LAYER::END; ++i)
		m_Layer[i]->deleteAllObjects();
}

void CLevel::deleteObjByLayrt(LAYER _layer)
{
	m_Layer[_layer]->deleteAllObjects();
}

void CLevel::createTile(UINT _Row, UINT _Col)
{
	deleteObjByLayrt(LAYER::TILE);
	tileRow = _Row;
	tileCol = _Col;

	for (UINT i = 0; i < _Row; ++i)
	{
		for (UINT j = 0; j < _Col; ++j)
		{
			Tile* pTile = new Tile;
			pTile->setPos(Vec2(TILE_SIZE * j, TILE_SIZE * i));
			addObject(LAYER::TILE, pTile);
		}
	}
}

CLevel::CLevel() : tileRow(0), tileCol(0)
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i] = new CLayer;
	}
}

// vector에 들어 있는 오브젝트들을 다 delete해주어야 됨
CLevel::~CLevel()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		if (nullptr != m_Layer[i])
			delete m_Layer[i];
	}
}
