#include "pch.h"
#include "Animator.h"
#include "Anim.h"
#include "PathMgr.h"
#include "LogMgr.h"


Animator::Animator(Obj* _Owner)
	: Component(_Owner)
	, m_CurAnim(nullptr)
	, m_bRepeat(false)
{
}

Animator::Animator(const Animator& _Origin)
	: Component(_Origin)
	, m_CurAnim(nullptr)
	, m_bRepeat(_Origin.m_bRepeat)
{
	for (const auto& pair : _Origin.m_mapAnim)
	{
		Anim* pAnim = pair.second->Clone();
		pAnim->m_pAnimator = this;
		m_mapAnim.insert(make_pair(pair.first, pAnim));
	}

	if (nullptr != _Origin.m_CurAnim)
	{
		m_CurAnim = FindAnim(_Origin.m_CurAnim->GetName());
	}
}


Animator::~Animator()
{
	for (const auto& pair : m_mapAnim)
	{
		delete pair.second;
	}
}

void Animator::finaltick(float _DT)
{
	if (IsValid(m_CurAnim))
	{
		if (m_bRepeat && m_CurAnim->IsFinish())
		{
			m_CurAnim->Reset();
		}
		m_CurAnim->finaltick();
	}
}

void Animator::render(HDC _dc)
{
	if (IsValid(m_CurAnim))
	{
		m_CurAnim->render(_dc);
	}
}


void Animator::Play(const wstring& _strName, bool _bRepeat)
{
	m_bRepeat = _bRepeat;
	m_CurAnim = FindAnim(_strName);
	m_CurAnim->Reset();
}

void Animator::Stop()
{
}

Anim* Animator::FindAnim(const wstring& _strName)
{
	map<wstring, Anim*>::iterator iter = m_mapAnim.find(_strName);

	if (iter == m_mapAnim.end())
	{
		return nullptr;
	}

	return iter->second;
}

void Animator::CreateAnimation(const wstring& _strName, Texture* _Atlas, Vec2 _vLeftTop, Vec2 _vCutSize,Vec2 _vOffset, float _Duration, int _MaxFrm)
{
	Anim* pAnim = FindAnim(_strName);
	if (IsValid(pAnim))
	{
		return;
	}

	pAnim = new Anim;
	pAnim->m_pAnimator = this;
	pAnim->Create(_strName, _Atlas, _vLeftTop, _vCutSize, _vOffset,_Duration, _MaxFrm);

	m_mapAnim.insert(make_pair(_strName, pAnim));
}



void Animator::SaveAnimations(const wstring& _strRelativePath)
{
	wstring strFolderPath = PathMgr::GetContentPath();
	strFolderPath += _strRelativePath;

	for (const auto& pair : m_mapAnim)
	{
		wstring strFilePath = strFolderPath + L"\\" + pair.first + L".txt";
		if (!pair.second->Save(strFilePath))
		{
			LOG(ERR, L"Animation Save 실패");
		}
	}
}

void Animator::LoadAnimation(const wstring& _strRelativePath)
{
	wstring strFilePath = PathMgr::GetContentPath();
	strFilePath += _strRelativePath;

	Anim* pNewAnim = new Anim;

	if (!pNewAnim->Load(strFilePath))
	{
		LOG(ERR, L"Animation Load 실패");
		delete pNewAnim;
		return;
	}
	wstring name = pNewAnim->GetName();
	pNewAnim->m_pAnimator = this;

	m_mapAnim.insert(make_pair(pNewAnim->GetName(), pNewAnim));
}