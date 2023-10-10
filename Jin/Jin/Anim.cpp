#include "pch.h"
#include "Anim.h"
#include "Animator.h"
#include "Obj.h"
#include "Camera.h"
#include "Texture.h"
#include "TimeMgr.h"
#include "LogMgr.h"
#include "AssetMgr.h"

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

	wstring strname = GetName();
	int iLen = 0;
	iLen = strname.length();
	fwrite(&iLen, sizeof(int), 1, pFile);
	fwrite(strname.c_str(),sizeof(wchar_t), strname.length(),pFile );

	bool bExist = m_Atlas;
	fwrite(&bExist, sizeof(bool), 1, pFile);

	if (bExist)
	{
		wstring strkey = m_Atlas->GetKey();
		wstring strRelativePath = m_Atlas->GetRelativePath();

		int iLen = 0;
		iLen = strkey.length();
		fwrite(&iLen, sizeof(int), 1, pFile);
		fwrite(strkey.c_str(), sizeof(wchar_t), strkey.length(), pFile);


		iLen = strRelativePath.length();
		fwrite(&iLen, sizeof(int), 1, pFile);
		fwrite(strRelativePath.c_str(), sizeof(wchar_t), strRelativePath.length(), pFile);
	}

	size_t FrmCount = m_vecFrm.size();
	fwrite(&FrmCount, sizeof(size_t), 1 , pFile);
	fwrite(&m_vecFrm[0], sizeof(FFrame),m_vecFrm.size(), pFile);

	fclose(pFile);
	return true;
}

bool Anim::Load(const wstring& _FilePath)
{
	FILE* pFile = nullptr;
	_wfopen_s(&pFile, _FilePath.c_str(), L"rb");

	if (nullptr == pFile)
	{
		LOG(ERR, L"파일 열기 실패");
		return false;
	}

	wchar_t szName[255] = {};
	int iLen = 0;
	fread(&iLen, sizeof(int), 1, pFile);
	fread(szName, sizeof(wchar_t), iLen, pFile);

	SetName(szName);

	bool bExist = 0;
	fread(&bExist, sizeof(bool), 1, pFile);
	
	if (bExist)
	{
		wchar_t szBuff[255] = {};
		int iLen = 0;

		fread(&iLen, sizeof(int), 1, pFile);
		fread(szBuff, sizeof(wchar_t), iLen, pFile);
		wstring strKey = szBuff;

		wmemset(szBuff, 0, 255); // 메모리 초기화 다 0으로

		fread(&iLen, sizeof(int), 1, pFile);
		fread(szBuff, sizeof(wchar_t), iLen, pFile);
		wstring strRelativePath = szBuff;
	
		m_Atlas = AssetMgr::GetInst()->LoadTexture(strKey, strRelativePath);

	}

	size_t FrmCount = 0;
	fread(&FrmCount, sizeof(size_t), 1,  pFile);
	m_vecFrm.resize(FrmCount);
	fread(&m_vecFrm[0], sizeof(FFrame), m_vecFrm.size(),pFile);

	fclose(pFile);
	return true;
}
