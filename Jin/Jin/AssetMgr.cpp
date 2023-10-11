#include "pch.h"
#include "AssetMgr.h"
#include "PathMgr.h"
#include "Texture.h"

AssetMgr::AssetMgr()
{

}

AssetMgr::~AssetMgr()
{
	for (const auto& pair : m_mapTex)
	{
		delete pair.second;
	}
}

Texture* AssetMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	Texture* pTexture = FindTexture(_strKey);
	if (nullptr != pTexture)
	{
		return pTexture;
	}

	wstring strContentPath = PathMgr::GetContentPath();
	wstring strFilePath = strContentPath + _strRelativePath;

	pTexture = new Texture;
	if (!pTexture->Load(strFilePath))
	{
		delete pTexture;
		return nullptr;
	}

	pTexture->m_strKey = _strKey;
	pTexture->m_strRelativePath = _strRelativePath;

	m_mapTex.insert(make_pair(_strKey, pTexture));

	return pTexture;
}

Texture* AssetMgr::FindTexture(const wstring& _strKey)
{
	map<wstring, Texture*>::iterator iter = m_mapTex.find(_strKey);

	if (iter == m_mapTex.end())
	{
		return nullptr;
	}
	return iter->second;
}
