#include "pch.h"
#include "UIMgr.h"
#include "KeyMgr.h"
#include "LevelMgr.h"
#include "Level.h"
#include "Layer.h"
#include "UI.h"

#include "LogMgr.h"

UIMgr::UIMgr()
{

}

UIMgr::~UIMgr()
{

}

void UIMgr::tick()
{
	Vec2 vMousePos = KeyMgr::GetInst()->GetMousePos();
	bool bLBtnTap = KEY_TAP(KEY::LBTN);
	bool bLBtnReleased = KEY_RELEASED(KEY::LBTN);

	Level* pLevel = LevelMgr::GetInst()->GetCurLevel();
	if (nullptr == pLevel)
		return;

	Layer* pUILayer = pLevel->GetLayer(LAYER::UILAYER);
	const vector<Obj*>& vecUI = pUILayer->GetObjects();

	for (size_t i = 0; i < vecUI.size(); ++i)
	{
		UI* pUI = dynamic_cast<UI*>(vecUI[i]);
		if (nullptr == pUI)
		{
			LOG(ERR, L"UI Layer에 UI가 아닌 오브젝트가 들어 있음.");
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
			{ // true != false
				pUI->OnUnHovered(vMousePos);
			}
		}
		if (bLBtnReleased)
		{
			pUI->m_bMouseLBtnDown = false;
		}
	}

}
