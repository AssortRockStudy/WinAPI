#include "pch.h"
#include "MyLevel.h"

#include "MyTimeMgr.h"
#include "MyLayer.h"
#include "MyObject.h"
#include "MyTile.h"

MyLevel::MyLevel() : m_TileRow(0), m_TileCol(0)
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_Layer[i] = new MyLayer;
	}
}

MyLevel::~MyLevel()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		if (nullptr != m_Layer[i])
		{
			delete m_Layer[i];
		}
	}
}

void MyLevel::AddObject(LAYER _LayerType, MyObject* _Object)
{
	m_Layer[(UINT_PTR)_LayerType]->AddObject(_Object);

	// 레이어 인덱스값을 오브젝트에 세팅해준다(오브젝트가 자신이 소속된 레이어 인덱스를 알게 한다)
	_Object->m_LayerIdx = (int)_LayerType;
}

void MyLevel::DeleteAllObjects()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_Layer[i]->DeleteAllObjects();
	}
}

void MyLevel::CreateTile(UINT _Row, UINT _Col)
{
	m_TileRow = _Row;
	m_TileCol = _Col;

	for (UINT i = 0; i < _Row; ++i)
	{
		for (UINT j = 0; j < _Col; ++j)
		{
			MyTile* pTile = new MyTile;

			pTile->SetPos(Vec2(TILE_SIZE * j, TILE_SIZE * i));

			AddObject(LAYER::TILE, pTile);
		}
	}
}

void MyLevel::begin()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_Layer[i]->begin();
	}
}

void MyLevel::tick()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_Layer[i]->clear();
	}

	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_Layer[i]->tick(DT);
	}

	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_Layer[i]->finaltick(DT);
	}
}

void MyLevel::render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		m_Layer[i]->render(_dc);
	}
}