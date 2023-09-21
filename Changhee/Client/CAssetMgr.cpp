#include "pch.h"
#include "CAssetMgr.h"

#include "CTexture.h"
#include "CPathMgr.h"

CAssetMgr::CAssetMgr()
{
}

CAssetMgr::~CAssetMgr()
{
	for (const auto& pair : m_mapTex)
	{
		delete pair.second;
	}

}

CTexture* CAssetMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	CTexture* pTexture = FindTexture(_strKey);

	if (nullptr != pTexture)
	{
		return pTexture;
	}

	wstring strContentPath = CPathMgr::GetContentDirectory();
	strContentPath += _strRelativePath;

	pTexture = new CTexture;
	pTexture->Load(strContentPath);

	m_mapTex.insert(make_pair(_strKey, pTexture));

	return pTexture;
}

CTexture* CAssetMgr::FindTexture(const wstring& _strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(_strKey);

	if (m_mapTex.end() == iter)
	{
		return nullptr;
	}

	return iter->second;
}
