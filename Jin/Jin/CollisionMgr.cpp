#include "pch.h"
#include "CollisionMgr.h"
#include "LevelMgr.h"
#include "Level.h"
#include "Obj.h"
#include "Collider.h"

CollisionMgr::CollisionMgr()
	: m_LayerCheck{}
{}

CollisionMgr::~CollisionMgr()
{}

void CollisionMgr::tick()
{
	Level* pCurLevel = LevelMgr::GetInst()->GetCurLevel();

	for (UINT iRow = 0; iRow < 32; ++iRow)
	{
		for (UINT iCol = iRow; iCol < 32; ++iCol)
		{
			if (!(m_LayerCheck[iRow] & (1 << iCol)))
				continue;

			const vector<Collider*>& vecLeft = pCurLevel->GetLayer((LAYER)iRow)->GetColliders();
			const vector<Collider*>& vecRight = pCurLevel->GetLayer((LAYER)iCol)->GetColliders();
		}
	}
}

void CollisionMgr::CheckCollision(LAYER _Left, LAYER _Right)
{
	int row = 0, col = 0;

	if (_Left < _Right)
	{
		row = _Left;
		col = _Right;
	}
	else
	{
		col = _Left;
		row = _Right;
	}

	m_LayerCheck[row] |= (1 << col);
}

void CollisionMgr::UncheckCollision(LAYER _Left, LAYER _Right)
{
	int row = 0, col = 0;

	if (_Left < _Right)
	{
		row = _Left;
		col = _Right;
	}
	else
	{
		col = _Left;
		row = _Right;
	}

	m_LayerCheck[row] &= ~(1 << col);
}
