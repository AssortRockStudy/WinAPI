#include "pch.h"
#include "MyColliderMgr.h"

#include "MyLevelMgr.h"
#include "MyLevel.h"
#include "MyObject.h"
#include "MyCollider.h"

MyColliderMgr::MyColliderMgr() : m_LayerCheck{}
{

}

MyColliderMgr::~MyColliderMgr()
{

}

void MyColliderMgr::tick()
{
	MyLevel* pCurLevel = MyLevelMgr::GetInst()->GetCurLevel();

	for (UINT iRow = 0; iRow < 32; ++iRow)
	{
		for (UINT iCol = iRow; iCol < 32; ++iCol)
		{
			if (!(m_LayerCheck[iRow] & (1 << iCol)))
			{
				continue;
			}

			const vector<MyObject*>& vecLeft = pCurLevel->GetObjects((LAYER)iRow);
			const vector<MyObject*>& vecRight = pCurLevel->GetObjects((LAYER)iCol);
		}
	}
}

void MyColliderMgr::CheckCollision(LAYER _Left, LAYER _Right)
{
	int row = 0;
	int col = 0;

	if (_Left < _Right)
	{
		row = (int)_Left;
		col = (int)_Right;
	}
	else
	{
		row = (int)_Right;
		col = (int)_Left;
	}

	m_LayerCheck[row] |= (1 << col);
}

void MyColliderMgr::UncheckCollision(LAYER _Left, LAYER _Right)
{
	int row = 0;
	int col = 0;

	if (_Left < _Right)
	{
		row = (int)_Left;
		col = (int)_Right;
	}
	else
	{
		row = (int)_Right;
		col = (int)_Left;
	}

	m_LayerCheck[row] &= (1 << col);
}
