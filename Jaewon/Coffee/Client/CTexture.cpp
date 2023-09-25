#include "pch.h"
#include "CTexture.h"

bool CTexture::load(const wstring& _fPath)
{
    return false;
}

CTexture::CTexture() :mBit(nullptr), mDc(nullptr), mInfo{} {}

CTexture::~CTexture(){
    DeleteObject(mBit);
    DeleteDC(mDc);
}
