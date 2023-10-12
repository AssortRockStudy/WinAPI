#include "pch.h"
#include "CTexture.h"

#include "CEngine.h"

bool CTexture::load(const wstring& _fPath)
{
	mBit = (HBITMAP)LoadImage(nullptr, _fPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	
	if (nullptr == mBit)
		return false;

	mDc = CreateCompatibleDC(CEngine::GetInst()->getMainDc());
	DeleteObject(SelectObject(mDc, mBit));
	GetObject(mBit, sizeof(BITMAP), &mInfo);
	return true;
}

CTexture::CTexture() :mBit(nullptr), mDc(nullptr), mInfo{} {}

CTexture::~CTexture(){
    DeleteObject(mBit);
    DeleteDC(mDc);
}
