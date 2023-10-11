#include "pch.h"
#include "Texture.h"
#include "Engine.h"


Texture::Texture()
    : m_hBit(nullptr)
    , m_hDC(nullptr)
    , m_Info{}
{
}

Texture::~Texture()
{
    DeleteObject(m_hBit);
    DeleteDC(m_hDC);
}

bool Texture::Load(const wstring& _strFilePath)
{
    m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    if (nullptr == m_hBit)
    {
        return false;
   }
    m_hDC = CreateCompatibleDC(Engine::GetInst()->GetMainDC());
    DeleteObject(SelectObject(m_hDC, m_hBit));
    GetObject(m_hBit, sizeof(BITMAP), &m_Info);

    return true;
}