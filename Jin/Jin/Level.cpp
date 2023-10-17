#include "pch.h"
#include "Level.h"
#include "TimeMgr.h"
#include "Layer.h"
#include "Obj.h"
#include "Tile.h"


Level::Level()
	: m_TileRow(0)
	, m_TileCol(0)
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i] = new Layer;
	}
}

Level::~Level()
{
	for (UINT  i = 0; i < LAYER::END; ++i)
	{
		if (nullptr != m_Layer[i])
			delete m_Layer[i];
	}
}

void Level::begin()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->begin();
	}
}

void Level::tick()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->clear();
	}

	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->tick(DT);
	}

	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->finaltick(DT);
	}
}

void Level::render(HDC _dc)
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->render(_dc);
	}
}

void Level :: AddObject(LAYER _LayerType, Obj* _Object)
{
	m_Layer[_LayerType]->AddObject(_Object);

	_Object->m_iLayerIdx = _LayerType;
}

void Level::DeleteAllObjects()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->DeleteAllObjects();
	}
}

void Level::DeleteObjectsByLayer(LAYER _LayerType)
{
	m_Layer[_LayerType]->DeleteAllObjects();
}

void Level::CreateTile(UINT _Row, UINT _Col)
{
	DeleteObjectsByLayer(TILE);

	m_TileRow = _Row;
	m_TileCol = _Col;

	for (UINT i = 0; i < _Row; ++i)
	{
		for (UINT j = 0; j < _Col; ++j)
		{
			Tile* pTile = new Tile;
			pTile->SetPos(Vec2(TILE_SIZE * j, TILE_SIZE * i));
			AddObject(LAYER::TILE, pTile);
		}
	}
}
