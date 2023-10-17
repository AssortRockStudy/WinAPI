#include "pch.h"
#include "MyAssetMgr.h"

#include "MyPathMgr.h"
#include "MyTexture.h"

MyAssetMgr::MyAssetMgr()
{

}

MyAssetMgr::~MyAssetMgr()
{
	for (const auto& pair : m_mapTex)
	{
		delete pair.second;
	}
}

MyTexture* MyAssetMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	// 입력된 키에 해당하는 텍스처가 있는지 먼저 확인한다
	MyTexture* pTexture = FindTexture(_strKey);

	if (nullptr != pTexture)
	{
		// 키에 해당하는 텍스처가 있을 경우 이를 반환
		return pTexture;
	}

	// 키에 해당하는 텍스처가 없을 경우 불러와서 반환
	wstring strContentPath = MyPathMgr::GetContentPath();
	wstring strFilePath = strContentPath + _strRelativePath;

	pTexture = new MyTexture;

	if (!pTexture->Load(strFilePath))
	{
		// 텍스처 로드가 실패했을 경우(경로 문제 등)
		delete pTexture;
		return nullptr;
	}

	// Asset에 키값과 경로값을 알려준다
	pTexture->m_strKey = _strKey;
	pTexture->m_strRelativePath = _strRelativePath;

	m_mapTex.insert(make_pair(_strKey, pTexture));

	return pTexture;
}

MyTexture* MyAssetMgr::FindTexture(const wstring& _strKey)
{
	// map에서 find함수의 반환값은 iterator로 반환된다
	map<wstring, MyTexture*>::iterator iter = m_mapTex.find(_strKey);

	if (iter == m_mapTex.end())
	{
		return nullptr;
	}

	return iter->second;
}
