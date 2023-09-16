#include "pch.h"
#include "CCollisionMgr.h"

#include "CLevel.h"
#include "CLevelMgr.h"


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

			const vector<CObj*>& vecLeft = pCurLevel->GetObjects((LAYER)iRow);
			const vector<CObj*>& vecRight = pCurLevel->GetObjects((LAYER)iCol);

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
