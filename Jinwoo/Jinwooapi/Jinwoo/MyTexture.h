#pragma once
#include "MyAsset.h"

class MyTexture :
    public MyAsset
{
private:
    HBITMAP		m_Image;
    HDC			m_DC;
    BITMAP		m_Info;

public:
    HDC GetDC() { return m_DC; }
    HBITMAP GetImage() { return m_Image; }
    UINT GetWidth() { return m_Info.bmWidth; }
    UINT GetHeight() { return m_Info.bmHeight; }

private:
    virtual bool Load(const wstring& _strFilePath) override;

public:
    MyTexture();
    ~MyTexture();

    friend class MyAssetMgr;
};

