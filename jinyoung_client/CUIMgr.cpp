#include "pch.h"
#include "CUIMgr.h"

#include "CKeyman.h"

#include "CLevelMgr.h"
#include "CLevel.h"
#include "CLayer.h"
#include "CUI.h"

#include "CLogMgr.h"

CUIMgr::CUIMgr()
{

}

CUIMgr::~CUIMgr()
{

}

void CUIMgr::tick()
{
	Vec2 vMousePos = CKeyman::GetInst()->GetMousePos();
	bool bLBtnTap = KEY_TAP(KEY::LBTN);
	bool bLbtnReleased = KEY_RELEASED(KEY::LBTN);

	CLevel* pLevel = CLevelMgr::GetInst()->GetCurLevel();
	if (nullptr == pLevel)
		return;

	CLayer* pUILayer = pLevel->GetLayer(LAYER::UI);
	const vector<CObj*>& vecUI = pUILayer->GetObjects();

	for (size_t i = 0; i < vecUI.size(); ++i)
	{
		CUI* pUI = dynamic_cast<CUI*>(vecUI[i]);
		if (nullptr == pUI)
		{
			LOG(ERR, L"UI Layer 에 UI 가 아닌 오브젝트가 들어 있음");
			continue;
		}

		if (pUI->m_bMouseOn)
		{
			if (pUI->m_bMouseOn_Prev != pUI->m_bMouseOn)
			{
				pUI->OnHovered(vMousePos);
			}
			else
			{
				pUI->MouseOn(vMousePos);
			}

			if (bLbtnReleased)
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
		if (bLbtnReleased)
		{
			pUI->m_bMouseLBtnDown = false;
		}

	}
}