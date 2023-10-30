#include "pch.h"
#include "AssetMgr.h"
#include "PathMgr.h"
#include "Texture.h"
#include "Sound.h"

AssetMgr::AssetMgr()
{

}

AssetMgr::~AssetMgr()
{
	for (const auto& pair : m_mapTex)
	{
		delete pair.second;
	}
		for (const auto& pair : m_mapSound)
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

Texture* AssetMgr::CreateTexture(const wstring& _strKey, UINT _width, UINT _height)
{
	Texture* pTexture = FindTexture(_strKey);
	if (nullptr != pTexture)
		return pTexture;

	pTexture = new Texture;
	pTexture->Create(_width, _height);

	pTexture->m_strKey = _strKey;
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

Sound* AssetMgr::LoadSound(const wstring& _strKey, const wstring& _strRelativePath)
{
	// 입력된 키에 해당하는 텍스쳐가 있는지 확인한다.
	Sound* pSound = FindSound(_strKey);
	if (nullptr != pSound)
	{
		// 이미 있는 텍스쳐면 찾은걸 반환해준다.
		return pSound;
	}

	// 입력된 키에 해당하는 텍스쳐가 없으면 로딩해서 반환해준다.
	wstring strContentPath = PathMgr::GetContentPath();
	wstring strFilePath = strContentPath + _strRelativePath;

	pSound = new Sound;

	if (!pSound->Load(strFilePath))
	{
		// 텍스쳐 로드가 실패한 경우(경로 문제 등등..)
		delete pSound;
		return nullptr;
	}

	// Asset 에 키값과 경로값을 알려준다.
	pSound->m_strKey = _strKey;
	pSound->m_strRelativePath = _strRelativePath;

	m_mapSound.insert(make_pair(_strKey, pSound));

	return pSound;
}

Sound* AssetMgr::FindSound(const wstring& _strKey)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(_strKey);

	if (iter == m_mapSound.end())
	{
		return nullptr;
	}

	return iter->second;
}
