#include "pch.h"

#include "MyUIMgr.h"
#include "MyLevelMgr.h"
#include "MyKeyMgr.h"
#include "MyLogMgr.h"

#include "MyLevel.h"
#include "MyLayer.h"
#include "MyUI.h"

MyUIMgr::MyUIMgr()
{

}

MyUIMgr::~MyUIMgr()
{

}

void MyUIMgr::tick()
{
	Vec2 vMousePos = MyKeyMgr::GetInst()->GetMousePos();
	bool bLBtnTap = KEY_TAP(LBTN);
	bool bLBtnReleased = KEY_RELEASED(LBTN);

	MyLevel* pLevel = MyLevelMgr::GetInst()->GetCurLevel();

	if (nullptr == pLevel)
	{
		return;
	}

	MyLayer* pUILayer = pLevel->GetLayer((int)LAYER::UI);
	const vector<MyObject*> vecUI = pUILayer->GetObjects();

	for (size_t i = 0; i < vecUI.size(); ++i)
	{
		MyUI* pUI = dynamic_cast<MyUI*>(vecUI[i]);

		if (nullptr == pUI)
		{
			LOG(ERR, L"UI Layer에 UI가 아닌 오브젝트가 들어있음");
			continue;
		}

		if (pUI->m_bMouseOn)
		{
			// 이전에는 마우스가 안올라와 있었지만
			// 이번 프레임에 마우스가 올라온 상태
			if (pUI->m_bMouseOn_Prev != pUI->m_bMouseOn)
			{
				pUI->OnHovered(vMousePos);
			}
			// 이전에도 마우스가 올라와있었고, 지금도 올라와있는 상태
			else
			{
				pUI->MouseOn(vMousePos);
			}

			// 마우스 누르던 걸 뗀 상태
			if (bLBtnReleased)
			{
				pUI->LBtnUp(vMousePos);

				// 이전에는 마우스를 누르고 있었다면
				if (pUI->m_bMouseLBtnDown)
				{
					// 클릭했다고 판단
					pUI->LBtnClicked(vMousePos);
				}
			}

			// 마우스를 이제 막 누른 상태
			if (bLBtnTap)
			{
				pUI->LBtnDown(vMousePos);
				pUI->m_bMouseLBtnDown = true;
			}
		}
		else
		{
			// 이전에는 마우스가 올라와 있었지만
			// 이번 프레임에 마우스가 안올라가있는 상태
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
