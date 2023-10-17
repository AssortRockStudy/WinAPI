#include "pch.h"
#include "MyAnim.h"

#include "MyTimeMgr.h"
#include "MyLogMgr.h"
#include "MyAssetMgr.h"

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

	_wfopen_s(&pFile, _FilePath.c_str(), L"w");

	if (nullptr == pFile)
	{
		LOG(ERR, L"파일 열기 실패");
		return false;
	}

	// Animation 이름 저장
	fwprintf(pFile, L"[ANIM_NAME]\n");

	wstring strName = GetName();
	fwprintf_s(pFile, strName.c_str());
	fwprintf_s(pFile, L"\n\n");

	// 키, 경로
	fwprintf_s(pFile, L"[ATLAS_TEXTURE]\n");

	wstring strKey;
	wstring strRelativePath;

	if (IsValid(m_Atlas))
	{
		strKey = m_Atlas->GetKey();
		strRelativePath = m_Atlas->GetRelativePath();
	}

	fwprintf_s(pFile, strKey.c_str());
	fwprintf_s(pFile, L"\n");
	fwprintf_s(pFile, strRelativePath.c_str());
	fwprintf_s(pFile, L"\n\n");

	// 프레임 데이터, 숫자
	fwprintf_s(pFile, L"[FRAME_COUNT]\n");
	fwprintf_s(pFile, L"%d\n\n", m_vecFrame.size());

	for (size_t i = 0; i < m_vecFrame.size(); ++i)
	{
		fwprintf_s(pFile, L"[FRAME_NUMBER]\n");
		fwprintf_s(pFile, L"%d\n", i);

		fwprintf_s(pFile, L"[LEFT_TOP]\n");
		fwprintf_s(pFile, L"%f %f\n", m_vecFrame[i].vLeftTop.x, m_vecFrame[i].vLeftTop.y);

		fwprintf_s(pFile, L"[CUT_SIZE]\n");
		fwprintf_s(pFile, L"%f %f\n", m_vecFrame[i].vCutSize.x, m_vecFrame[i].vCutSize.y);

		fwprintf_s(pFile, L"[OFFSET]\n");
		fwprintf_s(pFile, L"%f %f\n", m_vecFrame[i].vOffset.x, m_vecFrame[i].vOffset.y);

		fwprintf_s(pFile, L"[DURATION]\n");
		fwprintf_s(pFile, L"%f\n\n", m_vecFrame[i].Duration);
	}

	fclose(pFile);

	return true;
}

bool MyAnim::Load(const wstring& _FilePath)
{
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _FilePath.c_str(), L"r");

	if (nullptr == pFile)
	{
		LOG(ERR, L"파일 열기 실패");
		return false;
	}

	// Animation 이름 로드
	while (true)
	{
		wchar_t szRead[255] = {};

		// EOF -> End Of File, -1의 값을 가짐
		if (EOF == fwscanf_s(pFile, L"%s", szRead, 255))
		{
			break;
		}

		if (!wcscmp(szRead, L"[ANIM_NAME]"))
		{
			fwscanf_s(pFile, L"%s", szRead, 255);
			SetName(szRead);
		}
		else if (!wcscmp(szRead, L"[ATLAS_TEXTURE]"))
		{
			wstring strKey;
			wstring strRelativePath;

			fwscanf_s(pFile, L"%s", szRead, 255);
			strKey = szRead;

			fwscanf_s(pFile, L"%s", szRead, 255);
			strRelativePath = szRead;

			m_Atlas = MyAssetMgr::GetInst()->LoadTexture(strKey, strRelativePath);
		}
		else if (!wcscmp(szRead, L"[FRAME_COUNT]"))
		{
			size_t iFrameCount = 0;
			fwscanf_s(pFile, L"%d", &iFrameCount);
			m_vecFrame.resize(iFrameCount);

			size_t iCurFrame = 0;

			while (true)
			{
				fwscanf_s(pFile, L"%s", szRead, 255);
				
				if (!wcscmp(szRead, L"[FRAME_NUMBER]"))
				{
					fwscanf_s(pFile, L"%d", &iCurFrame);
				}
				else if (!wcscmp(szRead, L"[LEFT_TOP]"))
				{
					fwscanf_s(pFile, L"%f", &m_vecFrame[iCurFrame].vLeftTop.x);
					fwscanf_s(pFile, L"%f", &m_vecFrame[iCurFrame].vLeftTop.y);
				}
				else if (!wcscmp(szRead, L"[CUT_SIZE]"))
				{
					fwscanf_s(pFile, L"%f", &m_vecFrame[iCurFrame].vCutSize.x);
					fwscanf_s(pFile, L"%f", &m_vecFrame[iCurFrame].vCutSize.y);
				}
				else if (!wcscmp(szRead, L"[OFFSET]"))
				{
					fwscanf_s(pFile, L"%f", &m_vecFrame[iCurFrame].vOffset.x);
					fwscanf_s(pFile, L"%f", &m_vecFrame[iCurFrame].vOffset.y);
				}
				else if (!wcscmp(szRead, L"[DURATION]"))
				{
					fwscanf_s(pFile, L"%f", &m_vecFrame[iCurFrame].Duration);

					if (iFrameCount - 1 <= iCurFrame)
					{
						break;
					}
				}
			}
		}
	}

	fclose(pFile);
	return true;
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
