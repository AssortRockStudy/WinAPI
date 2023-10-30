#include "pch.h"
#include "CTile.h"

#include "CAssetMgr.h"
#include "CTexture.h"


CTile::CTile()
	: m_Atlas(nullptr)
	, m_Idx(40)
{
	m_Atlas = CAssetMgr::GetInst()->LoadTexture(L"TileAltas", L"texture\\TILE.bmp");
}

CTile::~CTile()
{
}

void CTile::tick(float _DT)
{

}

void CTile::render(HDC _dc)
{
	Vec2 vRenderPos = GetRenderPos();

	if (nullptr == m_Atlas)
	{
		Rectangle(_dc, vRenderPos.x, vRenderPos.y
			, vRenderPos.x + TILE_SIZE
			, vRenderPos.y + TILE_SIZE);
	}
	else
	{
		UINT width = m_Atlas->GetWidth();
		UINT height = m_Atlas->GetHeight();

		UINT maxRow = height / TILE_SIZE;
		UINT maxCol = width / TILE_SIZE;

		UINT maxTileCount = maxRow * maxCol;

		if (maxTileCount <= m_Idx)
		{
			return;
		}

		UINT iRow = m_Idx / maxCol;
		UINT iCol = m_Idx % maxCol;

		Vec2 vLeftTop = Vec2(TILE_SIZE * iCol, TILE_SIZE * iRow);

		BitBlt(_dc, vRenderPos.x, vRenderPos.y
			, TILE_SIZE, TILE_SIZE
			, m_Atlas->GetDC()
			, vLeftTop.x, vLeftTop.y, SRCCOPY);
	}
}