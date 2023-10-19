#include "pch.h"
#include "UIMgr.h"
#include "KeyMgr.h"
#include "LevelMgr.h"
#include "Level.h"
#include "Layer.h"
#include "UI.h"

#include "LogMgr.h"

UIMgr::UIMgr()
	: m_FocusedUI(nullptr)
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
	vector<Obj*>& vecUI = pUILayer->m_vecObjects;
	vector<Obj*>::reverse_iterator iter = vecUI.rbegin();


	for (iter; iter!= vecUI.rend(); ++iter)
	{
		UI* pUI = dynamic_cast<UI*>(*iter);
		if (nullptr == pUI)
		{
			LOG(ERR, L"UI Layer에 UI가 아닌 오브젝트가 들어 있음.");
			continue;
		}

		if (pUI->m_bMouseOn)
		{
			m_FocusedUI = pUI;

			pUI = GetPriorityCheck(pUI);

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

				//std::advance(iter, 1);
				++iter;
				vecUI.erase(iter.base());

				vecUI.push_back(m_FocusedUI);
			}

			if (bLBtnReleased)
			{
				pUI->m_bMouseLBtnDown = false;
			}
			break;
		}
		else
		{
			if (pUI->m_bMouseOn_Prev != pUI->m_bMouseOn)
			{ // true != false
				pUI->OnUnHovered(vMousePos);
			}

			if (bLBtnReleased)
			{
				pUI->m_bMouseLBtnDown = false;
			}
		}
		
	}

}

UI* UIMgr::GetPriorityCheck(UI* _ParentUI)
{
	UI* pPriorityUI = nullptr;

	static list<UI*> queue;
	queue.clear();
	queue.push_back(_ParentUI);

	while (!queue.empty())
	{ // BFS
		UI* pUI = queue.front();
		queue.pop_front();

		for (size_t i = 0; i < pUI->m_vecChildUI.size(); ++i)
		{
			queue.push_back(pUI->m_vecChildUI[i]);
		}

		if (pUI->m_bMouseOn)
		{
			pPriorityUI = pUI;
		}
	}

	return pPriorityUI;

}
