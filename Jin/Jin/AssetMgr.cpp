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
	// �Էµ� Ű�� �ش��ϴ� �ؽ��İ� �ִ��� Ȯ���Ѵ�.
	Sound* pSound = FindSound(_strKey);
	if (nullptr != pSound)
	{
		// �̹� �ִ� �ؽ��ĸ� ã���� ��ȯ���ش�.
		return pSound;
	}

	// �Էµ� Ű�� �ش��ϴ� �ؽ��İ� ������ �ε��ؼ� ��ȯ���ش�.
	wstring strContentPath = PathMgr::GetContentPath();
	wstring strFilePath = strContentPath + _strRelativePath;

	pSound = new Sound;

	if (!pSound->Load(strFilePath))
	{
		// �ؽ��� �ε尡 ������ ���(��� ���� ���..)
		delete pSound;
		return nullptr;
	}

	// Asset �� Ű���� ��ΰ��� �˷��ش�.
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
