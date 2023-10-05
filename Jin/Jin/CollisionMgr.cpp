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

	for (UINT iRow = 0; iRow < 32; ++iRow)
	{
		for (UINT iCol = iRow; iCol < 32; ++iCol)
		{
			if (!(m_LayerCheck[iRow] & (1 << iCol)))
				continue;
			CollisionBtwLayer((LAYER)iRow, (LAYER)iCol);
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


void CollisionMgr::CollisionBtwLayer(LAYER _Left, LAYER _Right)
{
	Level* pCurLevel = LevelMgr::GetInst()->GetCurLevel();
	const vector<Collider*>& vecLeft = pCurLevel->GetLayer(_Left)->GetColliders();
	const vector<Collider*>& vecRight = pCurLevel->GetLayer(_Right)->GetColliders();

	if (_Left != _Right)
	{
		for (size_t i = 0; i < vecLeft.size(); ++i)
		{
			for (size_t j = 0; j < vecRight.size(); ++j)
			{
				if (IsCollision(vecLeft[i], vecRight[j]))
				{
					vecLeft[i]->Overlap(vecRight[j]);
					vecRight[j]->Overlap(vecLeft[i]);
				}
				else
				{

				}
			}

		}
	}
	else
	{

	}
}

bool CollisionMgr::IsCollision(Collider* _Left, Collider* _Right)
{
	if (fabs(_Left->GetScale().x / 2.f + _Right->GetScale().x / 2.f) >= fabs(_Left->GetPos().x - _Right->GetPos().x) &&
		fabs(_Left->GetScale().y / 2.f + _Right->GetScale().y / 2.f) >= fabs(_Left->GetPos().y - _Right->GetPos().y))
	{
		return true;
	}
	return false;
}