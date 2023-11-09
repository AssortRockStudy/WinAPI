#include "pch.h"
#include "UIMgr.h"
#include "KeyMgr.h"
#include "CLevel.h"
#include "LevelMgr.h"
#include "UI.h"

void UIMgr::tick(){
	Vec2 vMousePos = KeyMgr::GetInst()->getMousePos();
	bool bLBtnTap = KeyMgr::GetInst()->getKeyState(LBTN) == TAP;
	bool bLbtnReleased = KeyMgr::GetInst()->getKeyState(LBTN) == RELEASED;

	CLevel* pLevel = LevelMgr::GetInst()->getCurLevel();
	if (nullptr == pLevel)
		return;

	CLayer* pUILayer = pLevel->GetLayer(LAYER::UI);
	vector<CObj*>& vecUI = pUILayer->mVecObjects;
	vector<CObj*>::reverse_iterator it = vecUI.rbegin();

	for (; it != vecUI.rend(); ++it)
	{
		class UI* pUI = dynamic_cast<class UI*>(*it);
		if (nullptr == pUI){
			LOG(ERR, L"UI Layer 에 UI 가 아닌 오브젝트가 들어 있음");
			continue;
		}

		if (pUI->mMouseOn){
			focusedUI = pUI;
			pUI = getPriorityChk(pUI);

			if (pUI->mouseOnPrev != pUI->mMouseOn)
				pUI->onHovered(vMousePos);
			else
				pUI->mouseOn(vMousePos);
			if (bLbtnReleased){
				pUI->LBtnUp(vMousePos);
				if (pUI->mouseLBtnDown)
					pUI->LBtnClicked(vMousePos);
			}
			if (bLBtnTap){
				pUI->LBtnDown(vMousePos);
				pUI->mouseLBtnDown = true;

				std::advance(it, 1);
				vecUI.erase(it.base());

				vecUI.push_back(focusedUI);
			}
			if (bLbtnReleased)
				pUI->mouseLBtnDown = false;
			break;
		}
		else{
			if (pUI->mouseOnPrev != pUI->mMouseOn)
				pUI->onUnHovered(vMousePos);
			if (bLbtnReleased)
				pUI->mouseLBtnDown = false;
		}
		
	}
}

class UI* UIMgr::getPriorityChk(class UI* _parent)
{
	class UI* priorityUI = nullptr;

	static list<class UI*> queue;
	queue.clear();
	queue.push_back(_parent);

	while (!queue.empty())
	{
		class UI* pUI = queue.front();
		queue.pop_front();

		for (size_t i = 0; i < pUI->vecChildUI.size(); ++i)
			queue.push_back(pUI->vecChildUI[i]);

		if (pUI->mMouseOn)
			priorityUI = pUI;
	}
	return priorityUI;
}

UIMgr::UIMgr():focusedUI(nullptr){}
UIMgr::~UIMgr(){}
