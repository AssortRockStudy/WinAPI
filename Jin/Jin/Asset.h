#pragma once
#include "Entity.h"
class Asset :
    public Entity
{
private:
    wstring m_strKey;
    wstring m_strRelativePath;

    virtual bool Load(const wstring& _strFilePath) = 0;

public:
    const wstring& GetKey() { return m_strKey; }
    const wstring& GetRelativePath() { return m_strRelativePath; }

public:
    CLONE_DISABLE(Asset);
    Asset();
    Asset(const Asset& _Origin) = delete;
    ~Asset();

    friend class AssetMgr;
};

