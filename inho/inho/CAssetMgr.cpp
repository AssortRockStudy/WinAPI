#include "pch.h"

#include "CAssetMgr.h"

#include "CPathMgr.h"
#include "CTexture.h"

CAssetMgr::CAssetMgr() {}

CAssetMgr::~CAssetMgr() {
    for (const auto& pair : m_mapTex) {
        delete pair.second;
    }
}

CTexture* CAssetMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
    CTexture* pTexture = FindTexture(_strKey);

    if (nullptr != pTexture) {
        return pTexture;
    }

    wstring strContentPath = CPathMgr::GetContentPath();
    wstring strFilePath = strContentPath + _strRelativePath;

    pTexture = new CTexture;
    if (!pTexture->Load(strFilePath)) {
        delete pTexture;
        return nullptr;
    }

    pTexture->m_strKey = _strKey;
    pTexture->m_strRelativePath = _strRelativePath;

    m_mapTex.insert(make_pair(_strKey, pTexture));

    return pTexture;
}

CTexture* CAssetMgr::CreateTexture(const wstring& _strKey, UINT _width, UINT _height)
{
    CTexture* pTexture = FindTexture(_strKey);
    if (nullptr != pTexture)
        return pTexture;

    pTexture = new CTexture;
    pTexture->Create(_width, _height);

    pTexture->m_strKey = _strKey;
    m_mapTex.insert(make_pair(_strKey, pTexture));

    return pTexture;
}

CTexture* CAssetMgr::FindTexture(const wstring& _strKey)
{
    auto iter = m_mapTex.find(_strKey);

    if (iter == m_mapTex.end()) {
        return nullptr;
    }

    return iter->second;
}
