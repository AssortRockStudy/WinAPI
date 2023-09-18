#include "pch.h"
#include "CCollisionMgr.h"

#include "CLevel.h"
#include "CLevelMgr.h"

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
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

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

void CCollisionMgr::CheckCollision(LAYER _eLeft, LAYER _eRight)
{
	int iRow = 0, iCol = 0;
	if ((UINT)_eLeft < (UINT)_eRight)
	{
		iRow = (int)_eLeft;
		iCol = (int)_eRight;
	}
	else
	{
		iRow = (int)_eRight;
		iCol = (int)_eLeft;
	}

	m_LayerCheck[iRow] |= (1 << iCol);

}

void CCollisionMgr::UnCheck(LAYER _eLeft, LAYER _eRight)
{
	int iRow = 0, iCol = 0;
	if ((UINT)_eLeft < (UINT)_eRight)
	{
		iRow = (int)_eLeft;
		iCol = (int)_eRight;
	}
	else
	{
		iRow = (int)_eRight;
		iCol = (int)_eLeft;
	}

	m_LayerCheck[iRow] &= ~(1 << iCol);


}

void CCollisionMgr::CollisionBtwLayer(LAYER _eLeft, LAYER _eRight)
{
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

	const vector<CCollider*>& vecLeft = pCurLevel->GetLayer((int)_eLeft)->GetColliders();
	const vector<CCollider*>& vecRight = pCurLevel->GetLayer((int)_eRight)->GetColliders();

	if (_eLeft != _eRight)
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


}

bool CCollisionMgr::IsCollision(CCollider* _pLeft, CCollider* _pRight)
{
	if (_pLeft->GetScale().x / 2.f + _pRight->GetScale().x / 2.f >= fabs(_pLeft->GetPos().x - _pRight->GetPos().x)
		&& _pLeft->GetScale().y / 2.f + _pRight->GetScale().y / 2.f >= fabs(_pLeft->GetPos().y - _pRight->GetPos().y))
	{
		return true;
	}


	return false;
}
