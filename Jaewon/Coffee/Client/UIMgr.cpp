#include "pch.h"
#include "UIMgr.h"
#include "KeyMgr.h"
#include "CLevel.h"
#include "LevelMgr.h"
#include "UI.h"

void UIMgr::tick(){
	Vec2 vMousePos = KeyMgr::GetInst()->getMousePos();

	CLevel* pLevel = LevelMgr::GetInst()->getCurLevel();
	if (nullptr == pLevel)
		return;

	CLayer* pUILayer = pLevel->GetLayer(LAYER::UI);
	const vector<CObj*>& vecUI = pUILayer->getObjects();
	
	bool bLBtnTap = KeyMgr::GetInst()->getKeyState(LBTN) == TAP;
	bool bLbtnReleased = KeyMgr::GetInst()->getKeyState(LBTN) == RELEASED;

	for (size_t i = 0; i < vecUI.size(); ++i)
	{
		class UI* pUI = dynamic_cast<class UI*>(vecUI[i]);
		if (nullptr == pUI){
			LOG(ERR, L"UI Layer 에 UI 가 아닌 오브젝트가 들어 있음");
			continue;
		}

		if (pUI->mMouseOn){
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
			}
		}
		else{
			if (pUI->mouseOnPrev != pUI->mMouseOn)
				pUI->onUnHovered(vMousePos);
		}
		if (bLbtnReleased)
			pUI->mouseLBtnDown = false;
	}
}

UIMgr::UIMgr(){}
UIMgr::~UIMgr(){}
