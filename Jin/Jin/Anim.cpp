#include "pch.h"
#include "Anim.h"
#include "Animator.h"
#include "Obj.h"
#include "Camera.h"
#include "Texture.h"
#include "TimeMgr.h"
#include "LogMgr.h"


Anim::Anim()
	: m_pAnimator(nullptr)
	, m_Atlas(nullptr)
	, m_iCurFrm(0)
	, m_bFinish(false)
	, m_Acctime(0.f)
{
}

Anim::~Anim()
{
}

void Anim::finaltick()
{
	if (m_bFinish)
		return;
	
	m_Acctime += DT;

	if (m_vecFrm[m_iCurFrm].Duration < m_Acctime)
	{
		m_Acctime = 0.f;

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

void Anim::render(HDC _dc)
{
	const FFrame& frm = m_vecFrm[m_iCurFrm];

	Obj* pOwnerObject = m_pAnimator->GetOwner();
	Vec2 vRenderPos = pOwnerObject->GetRenderPos();

	TransparentBlt(_dc, int(vRenderPos.x - (frm.vCutSize.x / 2.f) + frm.vOffset.x)
		, int(vRenderPos.y - (frm.vCutSize.y / 2.f) + frm.vOffset.y)
		, int(frm.vCutSize.x), int(frm.vCutSize.y)
		, m_Atlas->GetDC()
		, int(frm.vLeftTop.x), int(frm.vLeftTop.y)
		, int(frm.vCutSize.x), int(frm.vCutSize.y)
		, RGB(255, 0, 255));
}

void Anim::Create(const wstring& _strName, Texture* _Atlas, Vec2 _vLeftTop, Vec2 _vCutSize, Vec2 _vOffset, float _Duration, int _MaxFrm)
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
		frm.vOffset = _vOffset;

		m_vecFrm.push_back(frm);

	}
}

bool Anim::Save(const wstring& _FilePath)
{
	FILE* pFile = nullptr;
	_wfopen_s(&pFile, _FilePath.c_str(), L"wb");

	if (nullptr == pFile)
	{
		LOG(ERR, L"파일 열기 실패..");
		return false;
	}

	m_Atlas;
	m_vecFrm;


	fclose(pFile);
	return true;
}

void Anim::Load(const wstring& _FilePath)
{
}
