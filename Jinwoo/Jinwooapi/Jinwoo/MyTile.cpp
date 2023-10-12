#include "pch.h"
#include "MyTile.h"

#include "MyAssetMgr.h"
#include "MyTexture.h"

MyTile::MyTile() : m_Atlas(nullptr), m_Idx(0)
{
	m_Atlas = MyAssetMgr::GetInst()->LoadTexture(L"TileAtlas", L"texture\\TILE.bmp");
}

MyTile::~MyTile()
{
}

void MyTile::tick(float _DT)
{

}

void MyTile::render(HDC _dc)
{
	Vec2 vRenderPos = GetRenderPos();

	if (nullptr == m_Atlas)
	{
		Rectangle(_dc,
			(int)vRenderPos.x,
			(int)vRenderPos.y,
			(int)vRenderPos.x + TILE_SIZE,
			(int)vRenderPos.y + TILE_SIZE);
	}
	else
	{
		UINT width = m_Atlas->GetWidth();
		UINT height = m_Atlas->GetHeight();

		UINT maxRow = height / TILE_SIZE;
		UINT maxCol = width / TILE_SIZE;

		UINT maxTileCount = maxRow * maxCol;

		if (maxTileCount <= (UINT)m_Idx)
		{
			return;
		}

		UINT iRow = m_Idx / maxCol;
		UINT iCol = m_Idx & maxCol;

		Vec2 vLeftTop = Vec2(TILE_SIZE * iCol, TILE_SIZE * iRow);

		BitBlt(_dc, (int)vRenderPos.x, (int)vRenderPos.y,
			TILE_SIZE, TILE_SIZE,
			m_Atlas->GetDC(),
			(int)vLeftTop.x, (int)vLeftTop.y, SRCCOPY);
	}
}
