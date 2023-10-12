#include "pch.h"
#include "CAssetMgr.h"
#include "CPathMgr.h"
#include "CTexture.h"

CTexture* CAssetMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath){
	CTexture* pTexture = FindTexture(_strKey);
	if (nullptr != pTexture)
		return pTexture;
	
	wstring strContentPath = CPathMgr::getContentPath();
	wstring strFilePath = strContentPath + _strRelativePath;

	pTexture = new CTexture;
	
	if (!pTexture->load(strFilePath)) {
		delete pTexture;
		return nullptr;
	}

	pTexture->sKey = _strKey;
	pTexture->sPath = _strRelativePath;

	mTexture.insert(make_pair(_strKey, pTexture));

	return pTexture;
}

CTexture* CAssetMgr::FindTexture(const wstring& _strKey){
	map<wstring, CTexture*>::iterator iter = mTexture.find(_strKey);

	if (iter == mTexture.end())
		return nullptr;

	return iter->second;
}

CAssetMgr::CAssetMgr(){}

CAssetMgr::~CAssetMgr(){
	for (const auto& pair : mTexture){
		delete pair.second;
	}
}