#include "pch.h"
#include "Tile.h"
#include "CAssetMgr.h"
#include "CTexture.h"


void Tile::addImgIdx()
{
	if (nullptr == atlas)
		return;

	++idx;

	UINT width = atlas->getWidth();
	UINT height = atlas->getHeight();
	UINT maxRow = height / TILE_SIZE;
	UINT maxCol = width / TILE_SIZE;
	UINT maxTileCount = maxRow * maxCol;

	if (maxTileCount <= idx)
		idx = 0;
}

void Tile::tick(float _DT)
{
}

void Tile::render(HDC _dc)
{
	Vec2 vRenderPos = getRenderPos();

	if (nullptr == atlas){
		Rectangle(_dc, vRenderPos.x, vRenderPos.y
			, vRenderPos.x + TILE_SIZE
			, vRenderPos.y + TILE_SIZE);
	}
	else{
		UINT width = atlas->getWidth();
		UINT height = atlas->getHeight();

		UINT maxRow = height / TILE_SIZE;
		UINT maxCol = width / TILE_SIZE;

		UINT maxTileCount = maxRow * maxCol;

		if (maxTileCount <= idx)
			return;

		UINT iRow = idx / maxCol;
		UINT iCol = idx % maxCol;

		Vec2 vLeftTop = Vec2(TILE_SIZE * iCol, TILE_SIZE * iRow);

		BitBlt(_dc, vRenderPos.x, vRenderPos.y
			, TILE_SIZE, TILE_SIZE
			, atlas->getDc()
			, vLeftTop.x, vLeftTop.y, SRCCOPY);
	}
}

Tile::Tile():atlas(nullptr), idx(40)
{
	atlas = CAssetMgr::GetInst()->LoadTexture(L"TileAltas", L"texture\\TILE.bmp");
}

Tile::~Tile()
{
}
