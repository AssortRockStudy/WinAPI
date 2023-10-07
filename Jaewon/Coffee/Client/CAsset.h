#pragma once
#include "CEntity.h"
class CAsset :
    public CEntity
{
private:
    wstring sKey;
    wstring sPath;

public:
    const wstring& getKey() { return sKey; }
    const wstring& getPath() { return sPath; }

private:
    virtual bool load(const wstring& _sPath) = 0;

public:
    CAsset();
    ~CAsset();

    friend class CAssetMgr;
};

