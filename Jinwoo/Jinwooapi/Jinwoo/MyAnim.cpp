#include "pch.h"
#include "MyAnim.h"

#include "MyTimeMgr.h"
#include "MyLogMgr.h"

#include "MyObject.h"
#include "MyAnimator.h"
#include "MyTexture.h"

MyAnim::MyAnim() : m_Animator(nullptr), m_Atlas(nullptr), m_iCurFrame(0), m_Finish(false), m_AccTime(0.f)
{
}


MyAnim::~MyAnim()
{
}


bool MyAnim::Save(const wstring& _FilePath)
{
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _FilePath.c_str(), L"wb");

	if (nullptr == pFile)
	{
		LOG(ERR, L"파일 열기 실패");
		return false;
	}

	// m_Atlas와 m_vecFrame 저장

	fclose(pFile);

	return true;
}

void MyAnim::Load(const wstring& _FilePath)
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
		int(vRenderPos.x - (frm.vCutSize.x / 2.f) + frm.vOffset.x),
		int(vRenderPos.y - (frm.vCutSize.y / 2.f) + frm.vOffset.y),
		int(frm.vCutSize.x), int(frm.vCutSize.y),
		m_Atlas->GetDC(),
		int(frm.vLeftTop.x), int(frm.vLeftTop.y),
		int(frm.vCutSize.x), int(frm.vCutSize.y),
		RGB(255, 0, 255));
}

void MyAnim::Create(const wstring& _strName, MyTexture* _Atlas, Vec2 _vLeftTop, Vec2 _vCutSize, Vec2 _vOffset, float _Duration, int _MaxFrame)
{
	SetName(_strName);

	m_Atlas = _Atlas;

	m_vecFrame.reserve(_MaxFrame);

	for (int i = 0; i < _MaxFrame; ++i)
	{
		FFrame frm = {};

		frm.vLeftTop = _vLeftTop + Vec2(_vCutSize.x * i, 0.f);
		frm.vCutSize = _vCutSize;
		frm.vOffset = _vOffset;
		frm.Duration = _Duration;

		m_vecFrame.push_back(frm);
	}
}
