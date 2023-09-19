#include "pch.h"
#include "CCollisionMgr.h"

#include "CLevelMgr.h"
#include "CLevel.h"
#include "CObj.h"
#include "CCollider.h"


CCollisionMgr::CCollisionMgr()
	: m_LayerCheck{}
{
}

CCollisionMgr::~CCollisionMgr()
{

}

void CCollisionMgr::tick()
{
	//CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

	for (UINT iRow = 0; iRow < 32; ++iRow)
	{
		for (UINT iCol = iRow; iCol < 32; ++iCol)
		{
			if (!(m_LayerCheck[iRow] & (1 << iCol)))
				continue;

			/*const vector<CObj*>& vecLeft = pCurLevel->GetObjects((LAYER)iRow);
			const vector<CObj*>& vecRight = pCurLevel->GetObjects((LAYER)iCol);*/

			CollisionBtwLayer((LAYER)iRow, (LAYER)iCol);
			//const vector<CCollider*>& vecLeft = pCurLevel->GetLayer((LAYER)iRow)->GetColliders();
			//const vector<CCollider*>& vecRight = pCurLevel->GetLayer((LAYER)iCol)->GetColliders();

		}
	}
}

void CCollisionMgr::CheckCollision(LAYER _Left, LAYER _Right)
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

void CCollisionMgr::UncheckCollision(LAYER _Left, LAYER _Right)
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


void CCollisionMgr::CollisionBtwLayer(LAYER _Left, LAYER _Right)
{
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

	const vector<CCollider*>& vecLeft = pCurLevel->GetLayer(_Left)->GetColliders();
	const vector<CCollider*>& vecRight = pCurLevel->GetLayer(_Right)->GetColliders();


	// 서로 다른 레이어끼리 충돌 검사
	if (_Left != _Right)
	{
		for (size_t i = 0; i < vecLeft.size(); ++i)
		{
			for (size_t j = 0; j < vecRight.size(); ++j)
			{
				if (IsCollision(vecLeft[i], vecRight[j]))
				{
					// 충돌 중이다.
					vecLeft[i]->Overlap(vecRight[j]);
					vecRight[j]->Overlap(vecLeft[i]);
				}
				else
				{
					// 충돌하지 않는다.

				}
			}
		}
	}

	// 같은 레이어 내에서 충돌 검사
	else
	{

	}
}

bool CCollisionMgr::IsCollision(CCollider* _Left, CCollider* _Right)
{
	if (fabs(_Left->GetScale().x / 2.f + _Right->GetScale().x / 2.f) >= fabs(_Left->GetPos().x - _Right->GetPos().x)
		&& fabs(_Left->GetScale().y / 2.f + _Right->GetScale().y / 2.f) >= fabs(_Left->GetPos().y - _Right->GetPos().y))
	{
		return true;
	}

	return false;
}
