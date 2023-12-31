#include "pch.h"
#include "CAnimator.h"

#include "CPathMgr.h"

#include "CAnim.h"

CAnimator::CAnimator(CObj* _Owner)
	: CComponent(_Owner)
	, m_pCurAnim(nullptr)
	, m_bRepeat(false)
{
}

CAnimator::~CAnimator()
{
	for (const auto& pair : m_mapAnim)
	{
		delete pair.second;
	}
}

void CAnimator::finaltick(float _DT)
{
	if (IsValid(m_pCurAnim))
	{
		if (m_bRepeat && m_pCurAnim->IsFinish())
		{
			m_pCurAnim->Reset();
		}

		m_pCurAnim->finaltick(_DT);
	}
}

void CAnimator::render(HDC _dc)
{
	if (IsValid(m_pCurAnim))
	{
		m_pCurAnim->render(_dc);
	}

}

void CAnimator::Play(const wstring& _strName, bool _bRepeat)
{
	m_bRepeat = _bRepeat;
	m_pCurAnim = FindAnimation(_strName);

	assert(m_pCurAnim);
}

void CAnimator::Stop()
{
}

void CAnimator::CreateAnimation(const wstring& _strName, CTexture* _pAtlas, Vec2 _vLeftTop, Vec2 _vCutSize, Vec2 _vOffset, float _fDuration, int _iMaxFrm)
{
	CAnim* pAnim = FindAnimation(_strName);

	if (IsValid(pAnim))
	{
		return;
	}

	pAnim = new CAnim;
	pAnim->m_pAnimator = this;
	pAnim->Create(_strName, _pAtlas, _vLeftTop, _vCutSize, _vOffset, _fDuration, _iMaxFrm);
	m_mapAnim.insert(make_pair(_strName, pAnim));
}

CAnim* CAnimator::FindAnimation(const wstring& _strName)
{
	map<wstring, CAnim*>::iterator iter = m_mapAnim.find(_strName);

	if (iter == m_mapAnim.end())
	{
		return nullptr;
	}

	return iter->second;
}

void CAnimator::SaveAnimations(const wstring& _strRelativePath)
{
	wstring strFolderPath = CPathMgr::GetContentDirectory();
	strFolderPath += _strRelativePath;

	for (const auto& pair : m_mapAnim)
	{
		wstring strFilePath = strFolderPath + L"\\" + pair.first + L".txt";
		if (!pair.second->Save(strFilePath))
		{
			LOG(LOG_LEVEL::ERR, L"Animation Save ����");
		}
	}
}

void CAnimator::LoadAnimation(const wstring& _strRelativePath)
{
	wstring strFilePath = CPathMgr::GetContentDirectory();
	strFilePath += _strRelativePath;

	CAnim* pNewAnim = new CAnim;

	if (!pNewAnim->Load(strFilePath))
	{
		LOG(LOG_LEVEL::ERR, L"Animation Load ����");
		delete pNewAnim;
		return;
	}

	pNewAnim->m_pAnimator = this;
	m_mapAnim.insert(make_pair(pNewAnim->GetName(), pNewAnim));

}
