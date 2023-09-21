#include "pch.h"
#include "CAnimator.h"

CAnimator::CAnimator(CObj* _Owner)
	: CComponent(_Owner)
	, m_pCurAnim(nullptr)
	, m_bRepeat(false)
{
}

CAnimator::~CAnimator()
{
}

void CAnimator::finaltick(float _DT)
{
}

void CAnimator::render(HDC _dc)
{
}

void CAnimator::Play(const wstring& _strName, bool _bRepeat)
{
}

void CAnimator::Stop()
{
}

void CAnimator::CreateAnimation()
{
}