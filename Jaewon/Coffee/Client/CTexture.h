#pragma once
#include "CAsset.h"
class CTexture :
    public CAsset
{
private:
    HBITMAP mBit;
    HDC mDc;
    BITMAP mInfo;

public:
    HDC getDc(){ return mDc; }
    HBITMAP getBitMap() { return mBit; }
    UINT getWidth() { return mInfo.bmWidth; }
    UINT getHeight() { return mInfo.bmHeight; }

private:
    virtual bool load(const wstring& _fPath) override;

private:
    CTexture();
    ~CTexture();

    friend class CAssetMgr;
};

