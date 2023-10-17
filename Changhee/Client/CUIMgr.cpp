#include "pch.h"
#include "CUIMgr.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"

#include "CLevel.h"
#include "CUI.h"

CUIMgr::CUIMgr()
{
}

CUIMgr::~CUIMgr()
{
}


void CUIMgr::tick()
{
	Vec2 vMousePos = CKeyMgr::GetInst()->GetMousePos();
	bool bLBtnTap = KEY_TAP(KEY::LBTN);
	bool bLBtnReleased = KEY_RELEASED(KEY::LBTN);


	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	if (nullptr == pCurLevel)
		return;

	const vector<CObj*> vecUI = pCurLevel->GetObjects(LAYER::UI);

	for (size_t i = 0; i < vecUI.size(); ++i)
	{
		CUI* pUI = dynamic_cast<CUI*>(vecUI[i]);
		if (nullptr == pUI)
		{
			LOG(LOG_LEVEL::ERR, L"UI Layer에 UI가 아닌 오브젝트가 들어있습니다.");
			continue;
		}

		if (pUI->m_bMouseOn)
		{
			//pUI = GetPriorityCheck(pUI);

			if (pUI->m_bMouseOn_Prev != pUI->m_bMouseOn)
			{
				pUI->OnHovered(vMousePos);
			}
			else
			{
				pUI->MouseOn(vMousePos);
			}
			
			if (bLBtnReleased)
			{
				pUI->LBtnUp(vMousePos);

				if (pUI->m_bMouseLBtnDown)
				{
					pUI->LBtnClicked(vMousePos);
				}
			}

			if (bLBtnTap)
			{
				pUI->LBtnDown(vMousePos);
				pUI->m_bMouseLBtnDown = true;
			}

		}
		else
		{
			if (pUI->m_bMouseOn_Prev != pUI->m_bMouseOn)
			{
				pUI->OnUnHovered(vMousePos);
			}
		}
		
		if (bLBtnReleased)
		{
			pUI->m_bMouseLBtnDown = false;
		}

	}


}

CUI* CUIMgr::GetPriorityCheck(CUI* _pParentUI)
{
	_pParentUI;

	return nullptr;
}
