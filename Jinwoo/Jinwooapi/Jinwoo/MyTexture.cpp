#include "pch.h"
#include "MyTexture.h"

#include "MyEngine.h"

MyTexture::MyTexture() : m_Image(nullptr), m_DC(nullptr), m_Info{}
{
}

MyTexture::~MyTexture()
{
	DeleteObject(m_Image);
	DeleteDC(m_DC);
}

bool MyTexture::Load(const wstring& _strFilePath)
{
	// 플레이어가 사용할 이미지 로드
	m_Image = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_DC = CreateCompatibleDC(MyEngine::GetInst()->GetMainDC());
	DeleteObject(SelectObject(m_DC, m_Image));
	GetObject(m_Image, sizeof(BITMAP), &m_Info);

	return true;
}
