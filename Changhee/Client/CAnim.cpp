#include "pch.h"
#include "CAnim.h"

#include "CObj.h"
#include "CAnimator.h"
#include "CTexture.h"

CAnim::CAnim()
	: m_pAnimator(nullptr)
	, m_pAtlas(nullptr)
	, m_iCurFrm(0)
	, m_bFinish(false)
	, m_fAccTime(0.f)
{
}

CAnim::~CAnim()
{
}



void CAnim::Create(const wstring& _strName, CTexture* _pAtlas, Vec2 _vLeftTop, Vec2 _vCutSize, Vec2 _vOffset, float _fDuration, int _iMaxFrm)
{
	SetName(_strName);

	m_pAtlas = _pAtlas;
	m_vecFrm.reserve(_iMaxFrm);

	for (size_t i = 0; i < _iMaxFrm; ++i)
	{
		FFrame frm = {};
		frm.vLeftTop = _vLeftTop + Vec2(_vCutSize.x * i, 0.f);
		frm.vCutSize = _vCutSize;
		frm.fDuration = _fDuration;
		frm.vOffset = _vOffset;

		m_vecFrm.push_back(frm);
	}
}

bool CAnim::Save(const wstring& _FilePath)
{
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _FilePath.c_str(), L"wb");

	if (nullptr == pFile)
	{
		LOG(LOG_LEVEL::ERR, L"파일 열기 실패");
		return false;
	}

	// 키, 경로
	m_pAtlas;

	// 프레임 데이터
	m_vecFrm;

	fclose(pFile);

	return true;
}

void CAnim::Load(const wstring& _FilePath)
{
}

void CAnim::finaltick(float _DT)
{
	if (m_bFinish)
		return;

	m_fAccTime += _DT;

	if (m_vecFrm[m_iCurFrm].fDuration < m_fAccTime)
	{
		m_fAccTime = 0.f;

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

	TransparentBlt(_dc, int(vRenderPos.x - (frm.vCutSize.x / 2.f) + frm.vOffset.x)
					  , int(vRenderPos.y - (frm.vCutSize.y / 2.f) + frm.vOffset.y)
					  , int(frm.vCutSize.x), int(frm.vCutSize.y)
					  , m_pAtlas->GetDC()
					  , int(frm.vLeftTop.x), int(frm.vLeftTop.y)
					  , int(frm.vCutSize.x), int(frm.vCutSize.y)
					  , RGB(255, 0, 255));

}

