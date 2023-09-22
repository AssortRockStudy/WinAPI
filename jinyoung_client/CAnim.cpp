#include "pch.h"
#include "CAnim.h"

#include "CAnimator.h"
#include "CObj.h"
#include "CCamera.h"
#include "CTexture.h"
#include "CTimeManager.h"

CAnim::CAnim()
	: m_pAnimator(nullptr)
	, m_Atlas(nullptr)
	, m_iCurFrm(0)
	, m_bFinish(false)
{
}

CAnim::~CAnim()
{
}

void CAnim::finaltick()
{
	if (m_bFinish)
		return;

	m_AccTime += DT;

	if (m_vecFrm[m_iCurFrm].Duration < m_AccTime)
	{
		m_AccTime = 0.f;

		if (m_vecFrm.size() - 1 <= m_iCurFrm)
		{
			m_bFinish = true;
		}
		else
		{
			++m_iCurFrm;
		}
	}

}

void CAnim::render(HDC _dc)
{
	const FFrame& frm = m_vecFrm[m_iCurFrm];

	CObj* pOwnerObject = m_pAnimator->GetOwner();
	Vec2 vRenderPos = pOwnerObject->GetRenderPos();

	TransparentBlt(_dc, int(vRenderPos.x - (frm.vCutSize.x / 2.f))
		, int(vRenderPos.y - (frm.vCutSize.y / 2.f))
		, int(frm.vCutSize.x), int(frm.vCutSize.y)
		, m_Atlas->GetDC()
		, int(frm.vLeftTop.x), int(frm.vLeftTop.y)
		, int(frm.vCutSize.x), int(frm.vCutSize.y)
		, RGB(255, 0, 255));
}

void CAnim::Create(const wstring& _strName, CTexture* _Atlas
	, Vec2 _vLeftTop, Vec2 _vCutSize, float _Duration, int _MaxFrm)
{
	SetName(_strName);

	m_Atlas = _Atlas;

	m_vecFrm.reserve(_MaxFrm);

	for (size_t i = 0; i < _MaxFrm; ++i)
	{
		FFrame frm = {};

		frm.vLeftTop = _vLeftTop + Vec2(_vCutSize.x * i, 0.f);
		frm.vCutSize = _vCutSize;
		frm.Duration = _Duration;

		m_vecFrm.push_back(frm);
	}
}