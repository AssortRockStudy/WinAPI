#include "pch.h"
#include "MyAnim.h"

#include "MyTimeMgr.h"

#include "MyObject.h"
#include "MyAnimator.h"
#include "MyTexture.h"

MyAnim::MyAnim() : m_Animator(nullptr), m_Atlas(nullptr), m_iCurFrame(0), m_Finish(false)
{
}


MyAnim::~MyAnim()
{
}


void MyAnim::finaltick()
{
	if (m_Finish)
	{
		return;
	}

	m_AccTime += DT;

	if (m_vecFrame[m_iCurFrame].Duration < m_AccTime)
	{
		m_AccTime = 0.f;

		if (m_vecFrame.size() - 1 <= m_iCurFrame)
		{
			m_Finish = true;
		}
		else
		{
			++m_iCurFrame;
		}
	}
}

void MyAnim::render(HDC _dc)
{
	const FFrame& frm = m_vecFrame[m_iCurFrame];

	MyObject* pOwnerObject = m_Animator->GetOwner();
	Vec2 vRenderPos = pOwnerObject->GetRenderPos();

	TransparentBlt(_dc,
		int(vRenderPos.x - (frm.vCutSize.x / 2.f)),
		int(vRenderPos.y - (frm.vCutSize.y / 2.f)),
		int(frm.vCutSize.x), int(frm.vCutSize.y),
		m_Atlas->GetDC(),
		int(frm.vLeftTop.x), int(frm.vLeftTop.y),
		int(frm.vCutSize.x), int(frm.vCutSize.y),
		RGB(255, 0, 255));
}

void MyAnim::Create(const wstring& _strName, MyTexture* _Atlas, Vec2 _vLeftTop, Vec2 _vCutSize, float _Duration, int _MaxFrame)
{
	SetName(_strName);

	m_Atlas = _Atlas;

	m_vecFrame.reserve(_MaxFrame);

	for (int i = 0; i < _MaxFrame; ++i)
	{
		FFrame frm = {};

		frm.vLeftTop = _vLeftTop + Vec2(_vCutSize.x * i, 0.f);
		frm.vCutSize = _vCutSize;
		frm.Duration = _Duration;

		m_vecFrame.push_back(frm);
	}
}
