#include "pch.h"
#include "CAssetMgr.h"

#include "CPathMgr.h"
#include "CTexture.h"


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
	// �Էµ� Ű�� �ش��ϴ� �ؽ��İ� �ִ��� Ȯ���Ѵ�.
	CTexture* pTexture = FindTexture(_strKey);
	if (nullptr != pTexture)
	{
		// �̹� �ִ� �ؽ��ĸ� ã���� ��ȯ���ش�.
		return pTexture;
	}

	// �Էµ� Ű�� �ش��ϴ� �ؽ��İ� ������ �ε��ؼ� ��ȯ���ش�.
	wstring strContentPath = CPathMgr::GetContentPath();
	wstring strFilePath = strContentPath + _strRelativePath;

	pTexture = new CTexture;
	pTexture->Load(strFilePath);

	m_mapTex.insert(make_pair(_strKey, pTexture));

	return pTexture;
}

CTexture* CAssetMgr::FindTexture(const wstring& _strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(_strKey);

	if (iter == m_mapTex.end())
	{
		return nullptr;
	}

	return iter->second;
}
