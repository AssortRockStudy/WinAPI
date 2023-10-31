#include "pch.h"
#include "CTexture.h"

#include "CEngine.h"

CTexture::CTexture()
	: m_hBit(nullptr)
	, m_hDC(nullptr)
	, m_Info{}
{
}

CTexture::~CTexture()
{
	DeleteObject(m_hBit);
	DeleteDC(m_hDC);
}

bool CTexture::Load(const wstring& _strFilePath)
{
	// 플레이어가 사용할 이미지 비트맵 로딩
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	if (nullptr == m_hBit)
	{
		return false;
	}
	m_hDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());
	DeleteObject(SelectObject(m_hDC, m_hBit));
	GetObject(m_hBit, sizeof(BITMAP), &m_Info);

	return true;
}


void CTexture::Create(UINT _Width, UINT Height)
{
	m_hBit = CreateCompatibleBitmap(CEngine::GetInst()->GetMainDC(), _Width, Height);
	m_hDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());

	m_hDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());
	DeleteObject(SelectObject(m_hDC, m_hBit));
	GetObject(m_hBit, sizeof(BITMAP), &m_Info);
}

