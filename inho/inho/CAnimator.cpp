﻿#include "pch.h"

#include "CAnimator.h"
#include "CAnim.h"

#include "CPathMgr.h"
#include "CLogMgr.h"

CAnimator::CAnimator(CObj* _Owner):
	CComponent(_Owner),
	m_CurAnim(nullptr),
	m_bRepeat(false)
{}

CAnimator::~CAnimator() {
	for (const auto& pair : m_mapAnim) {
		delete pair.second;
	}
}

void CAnimator::finaltick(float _DT) {
	
	if (IsValid(m_CurAnim)) {
		if (m_bRepeat && m_CurAnim->IsFinish()) {
			m_CurAnim->Reset();
		}
		m_CurAnim->finaltick();
	}
}

void CAnimator::render(HDC _dc) {
	if (IsValid(m_CurAnim)) {
		m_CurAnim->render(_dc);
	}
}

void CAnimator::Play(const wstring& _strName, bool _bRepeat) {
	m_bRepeat = _bRepeat;
	m_CurAnim = FindAnim(_strName);
}

void CAnimator::Stop() {}

CAnim* CAnimator::FindAnim(const wstring& _strName)
{
	auto iter = m_mapAnim.find(_strName);

	if (iter == m_mapAnim.end()) {
		return nullptr;
	}

	return iter->second;
}

void CAnimator::CreateAnimation(const wstring& _strName, CTexture* _Altas, Vec2 _vLeftTop, Vec2 _vCutSize, Vec2 _vOffset, float _Duration, int _MaxFrm)
{
	CAnim* pAnim = FindAnim(_strName);
	if (IsValid(pAnim)) {
		return;
	}

	pAnim = new CAnim;
	pAnim->m_pAnimator = this;
	pAnim->Create(_strName, _Altas, _vLeftTop, _vCutSize, _vOffset, _Duration, _MaxFrm);
	m_mapAnim.insert(make_pair(_strName, pAnim));

}

void CAnimator::SaveAnimation(const wstring& _strRelativePath)
{
	wstring strFolderPath = CPathMgr::GetContentPath();
	strFolderPath += _strRelativePath;

	for (const auto& pair : m_mapAnim) {
		wstring strFilePath = strFolderPath + L"\\" + pair.first + L".txt";

		if (!pair.second->Save(strFilePath)) {
			LOG(ERR, L"Animation Save 실패");
		}
	}
}

void CAnimator::LoadAnimation(const wstring& _strRelativePath)
{
	wstring strFilePath = CPathMgr::GetContentPath();
	strFilePath += _strRelativePath;

	CAnim* pNewAnim = new CAnim;
	if (!pNewAnim->Load(strFilePath)) {
		LOG(ERR, L"Animation Load Fail");
		delete pNewAnim;

		return;
	}

	pNewAnim->m_pAnimator = this;
	m_mapAnim.insert(make_pair(pNewAnim->GetName(), pNewAnim));
}



